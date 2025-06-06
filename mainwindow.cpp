#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QGraphicsScene>
#include <QGraphicsLineItem>
#include <QColor>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupConnections();

    ui->stepSpinBox->setMaximum(Constants::MAX_STEP);
    ui->normASpinBox->setMinimum(Constants::MIN_NORMA);
    ui->normBSpinBox->setMaximum(Constants::MAX_NORMB);

}

void MainWindow::setupConnections() {
    connect(ui->filePushButton, &QPushButton::clicked, this, &MainWindow::onFileClicked);
    connect(ui->uploadPushButton, &QPushButton::clicked, this, &MainWindow::onUploadClicked);
    connect(ui->rotateXPlusButton, &QPushButton::clicked, this, &MainWindow::onRotateXPlusClicked);
    connect(ui->rotateXMinusButton, &QPushButton::clicked, this, &MainWindow::onRotateXMinusClicked);
    connect(ui->rotateYPlusButton, &QPushButton::clicked, this, &MainWindow::onRotateYPlusClicked);
    connect(ui->rotateYMinusButton, &QPushButton::clicked, this, &MainWindow::onRotateYMinusClicked);
    connect(ui->rotateZPlusButton, &QPushButton::clicked, this, &MainWindow::onRotateZPlusClicked);
    connect(ui->rotateZMinusButton, &QPushButton::clicked, this, &MainWindow::onRotateZMinusClicked);
    connect(ui->translateXPlusButton, &QPushButton::clicked, this, &MainWindow::onTranslateXPlusClicked);
    connect(ui->translateXMinusButton, &QPushButton::clicked, this, &MainWindow::onTranslateXMinusClicked);
    connect(ui->translateYPlusButton, &QPushButton::clicked, this, &MainWindow::onTranslateYPlusClicked);
    connect(ui->translateYMinusButton, &QPushButton::clicked, this, &MainWindow::onTranslateYMinusClicked);
    connect(ui->translateZPlusButton, &QPushButton::clicked, this, &MainWindow::onTranslateZPlusClicked);
    connect(ui->translateZMinusButton, &QPushButton::clicked, this, &MainWindow::onTranslateZMinusClicked);
    connect(ui->zoomInButton, &QPushButton::clicked, this, &MainWindow::onZoomInClicked);
    connect(ui->zoomOutButton, &QPushButton::clicked, this, &MainWindow::onZoomOutClicked);
    connect(ui->resetViewButton, &QPushButton::clicked, this, &MainWindow::onResetViewClicked);
    connect(ui->exitButton, &QPushButton::clicked, this, &MainWindow::onExitClicked);
    connect(ui->normalizeButton, &QPushButton::clicked, this, &MainWindow::onNormalizeClicked);
    connect(ui->stepSpinBox, QOverload<double>::of(&QDoubleSpinBox::valueChanged),this, &MainWindow::onStepChanged);

}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::onFileClicked() {
    QString path = QFileDialog::getOpenFileName(this, "Выбрать файл", "D:/labsFiles/2-st semester/OOP/OOP_lab4/files4labs", "CSV файлы (*.csv);;Все файлы (*.*)");
    if (!path.isEmpty())
        ui->pathLabel->setText(path);
}

void MainWindow::onUploadClicked() {
    if (ui->pathLabel->text().isEmpty()) {
        QMessageBox::critical(this, "Ошибка", "Сначала выберите файл");
        return;
    }

    if (ui->normASpinBox->value() >= ui->normBSpinBox->value()) {
        QMessageBox::critical(this, "Ошибка", "Неккоректный диапазон нормировки");
        return;
    }

    qDebug("START ");

    doOperation(Init, &context);
    qDebug("INIT OK ");

    strncpy(context.currentFilePath, ui->pathLabel->text().toStdString().c_str(), Constants::LEN_PATH -1);
    context.currentFilePath[Constants::LEN_PATH -1] = '\0';

    doOperation(LoadData, &context);
    qDebug("LOAD OK");
    if (context.fileLoaded) {
        context.surfaceData.step = ui->stepSpinBox->value();
        context.surfaceData.normA = ui->normASpinBox->value();
        context.surfaceData.normB = ui->normBSpinBox->value();

        doOperation(ApplyStep, &context);
        qDebug("STEP OK");

        doOperation(Normalize, &context);
        qDebug("NORMALIZE OK");

        drawSurface();

        QMessageBox::information(this, "Успех", "Данные успешно загружены");
    }
    else QMessageBox::warning(this, "Ошибка", "Не удалось загрузить данные из файла");
}

void MainWindow::drawAxes() {
    if (!ui->graphicsView->scene())
        return;

    QGraphicsScene* scene = ui->graphicsView->scene();
    float centerX = ui->graphicsView->width() / Constants::DIVISOR_FOR_CENTER;
    float centerY = ui->graphicsView->height() / Constants::DIVISOR_FOR_CENTER;

    float axisLength = Constants::AXIS_LENGTH;

    QGraphicsLineItem* xAxis = new QGraphicsLineItem( centerX, centerY,centerX + axisLength, centerY);
    xAxis->setPen(QPen(Qt::red, Constants::AXIS_WIDTH));
    scene->addItem(xAxis);

    QGraphicsLineItem* yAxis = new QGraphicsLineItem(centerX, centerY, centerX, centerY - axisLength);
    yAxis->setPen(QPen(Qt::green, Constants::AXIS_WIDTH));
    scene->addItem(yAxis);

    QGraphicsLineItem* zAxis = new QGraphicsLineItem(centerX, centerY, centerX, centerY + axisLength/Constants::COEFFICIENT_Y_ZAXIS);
    zAxis->setPen(QPen(Qt::blue, Constants::AXIS_WIDTH));
    scene->addItem(zAxis);

}

void MainWindow::drawSurface() {
    if (!context.fileLoaded)
        return;

    QGraphicsScene* oldScene = ui->graphicsView->scene();
    if (oldScene)
        oldScene->clear();
    else {
        oldScene = new QGraphicsScene(this);
        ui->graphicsView->setScene(oldScene);
    }

    oldScene->setBackgroundBrush(QColor("#2D3848"));
    drawAxes();

    QColor lineColor = QColor(100, 200, 255);

    for (int i = 0; i < context.surfaceData.edgesCount; i++) {
        SurfaceEdge edge = context.surfaceData.edges[i];
        Point3D point1 = context.surfaceData.points[edge.pointIndex1].point;
        Point3D point2 = context.surfaceData.points[edge.pointIndex2].point;

        Point2D proj1 = projectPoint(&point1);
        Point2D proj2 = projectPoint(&point2);

        QGraphicsLineItem* line = new QGraphicsLineItem(proj1.x, proj1.y, proj2.x, proj2.y);

        line->setPen(QPen(lineColor, Constants::LINE_WIDTH));
        oldScene->addItem(line);
    }
}

Point2D MainWindow::projectPoint(Point3D* point) {
    return ::projectPoint(point, &context, ui->graphicsView->width(), ui->graphicsView->height());
}

void MainWindow::onRotateXPlusClicked() {
    doOperation(RotateX, &context,  Constants::UNIT_OF_ROTATION);
    drawSurface();
}

void MainWindow::onRotateXMinusClicked() {
    doOperation(RotateX, &context, -Constants::UNIT_OF_ROTATION);
    drawSurface();
}

void MainWindow::onRotateYPlusClicked() {
    doOperation(RotateY, &context,  Constants::UNIT_OF_ROTATION);
    drawSurface();
}
void MainWindow::onRotateYMinusClicked() {
    doOperation(RotateY, &context, -Constants::UNIT_OF_ROTATION);
    drawSurface();
}

void MainWindow::onRotateZPlusClicked() {
    doOperation(RotateZ, &context,  Constants::UNIT_OF_ROTATION);
    drawSurface();
}

void MainWindow::onRotateZMinusClicked() {
    doOperation(RotateZ, &context, -Constants::UNIT_OF_ROTATION);
    drawSurface();
}

void MainWindow::onTranslateXPlusClicked() {
    doOperation(TranslateX, &context,  Constants::UNIT_OF_TRANSLATE);
    drawSurface();
}

void MainWindow::onTranslateXMinusClicked() {
    doOperation(TranslateX, &context, -Constants::UNIT_OF_TRANSLATE);
    drawSurface();
}

void MainWindow::onTranslateYPlusClicked() {
    doOperation(TranslateY, &context,  Constants::UNIT_OF_TRANSLATE);
    drawSurface();
}

void MainWindow::onTranslateYMinusClicked() {
    doOperation(TranslateY, &context, -Constants::UNIT_OF_TRANSLATE);
    drawSurface();
}

void MainWindow::onTranslateZPlusClicked() {
    doOperation(TranslateZ, &context, -Constants::UNIT_OF_TRANSLATE);
    drawSurface();
}

void MainWindow::onTranslateZMinusClicked() {
    doOperation(TranslateZ, &context,  Constants::UNIT_OF_TRANSLATE);
    drawSurface();
}

void MainWindow::onZoomInClicked() {
    doOperation(ZoomIn, &context,  Constants::COEFFICIENT_ZOMM_IN);
    drawSurface();
}

void MainWindow::onZoomOutClicked() {
    doOperation(ZoomOut, &context,  Constants::COEFFICIENT_ZOMM_OUT);
    drawSurface();
}

void MainWindow::onResetViewClicked() {
    doOperation(ResetView, &context);
    drawSurface();
}

void MainWindow::onExitClicked() {
    doOperation(Clear, &context);
    qDebug("CLEAR OK");
    qApp->quit();
}

void MainWindow::onNormalizeClicked() {
    context.surfaceData.normA = ui->normASpinBox->value();
    context.surfaceData.normB = ui->normBSpinBox->value();

    if (ui->normASpinBox->value() >= ui->normBSpinBox->value()) {
        QMessageBox::critical(this, "Ошибка", "Неккоректный диапазон нормировки");
        return;
    }

    doOperation(Normalize, &context);
    qDebug("NORMALIZE OK");
    drawSurface();
}

void MainWindow::onStepChanged(double value) {
    context.surfaceData.step = value;
    if (context.fileLoaded) {
        doOperation(ApplyStep, &context);
        qDebug("STEP OK");
        drawSurface();
    }
}
