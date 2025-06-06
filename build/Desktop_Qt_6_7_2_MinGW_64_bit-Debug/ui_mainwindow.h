/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QGraphicsView *graphicsView;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *pathLabel;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *filePushButton;
    QPushButton *uploadPushButton;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_3;
    QDoubleSpinBox *normASpinBox;
    QLabel *label_2;
    QDoubleSpinBox *normBSpinBox;
    QPushButton *normalizeButton;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout_4;
    QDoubleSpinBox *stepSpinBox;
    QGridLayout *gridLayout;
    QPushButton *rotateXPlusButton;
    QPushButton *rotateXMinusButton;
    QPushButton *rotateZPlusButton;
    QPushButton *rotateYPlusButton;
    QPushButton *translateXPlusButton;
    QPushButton *rotateYMinusButton;
    QPushButton *rotateZMinusButton;
    QPushButton *translateXMinusButton;
    QPushButton *translateYPlusButton;
    QPushButton *translateYMinusButton;
    QPushButton *translateZPlusButton;
    QPushButton *translateZMinusButton;
    QPushButton *zoomInButton;
    QPushButton *zoomOutButton;
    QPushButton *resetViewButton;
    QPushButton *exitButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(900, 855);
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow {\n"
"    background-color: #2D3848;\n"
"    font-family: 'Segoe UI', Arial, sans-serif;\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8("QWidget#centralwidget {\n"
"   background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #1A2A3A, stop:1 #2D3848);\n"
"}\n"
""));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setMinimumSize(QSize(600, 400));
        graphicsView->setStyleSheet(QString::fromUtf8("QGraphicsView {\n"
"    background-color: #1E2B38;\n"
"    border: 1px solid #3A4A5D;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"QGraphicsView QScrollBar:vertical {\n"
"    background: #2C3E50;\n"
"    width: 10px;\n"
"    margin: 0px;\n"
"}\n"
"\n"
"QGraphicsView QScrollBar::handle:vertical {\n"
"    background: #4A5D6E;\n"
"    min-height: 20px;\n"
"    border-radius: 4px;\n"
"}"));

        verticalLayout->addWidget(graphicsView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        pathLabel = new QLabel(centralwidget);
        pathLabel->setObjectName("pathLabel");
        pathLabel->setMinimumSize(QSize(0, 30));
        pathLabel->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #E0E0E0;\n"
"    font-size: 13px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QLabel#pathLabel {\n"
"    background-color: rgba(44, 62, 80, 150);\n"
"    border: 1px solid #3A4A5D;\n"
"    border-radius: 3px;\n"
"}"));
        pathLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_2->addWidget(pathLabel);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        filePushButton = new QPushButton(centralwidget);
        filePushButton->setObjectName("filePushButton");
        filePushButton->setMinimumSize(QSize(0, 0));
        QFont font;
        font.setBold(true);
        filePushButton->setFont(font);
        filePushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"     background-color: #2980B9;\n"
"    border: 1px solid #4A5D6E;\n"
"    border-radius: 4px;\n"
"    color: #E0E0E0;\n"
"    padding: 6px 12px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #4A5D6E;\n"
"    border-color: #5B6E80;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #2C3E50;\n"
"    padding: 7px 11px 5px 13px;\n"
"}"));

        horizontalLayout_2->addWidget(filePushButton);

        uploadPushButton = new QPushButton(centralwidget);
        uploadPushButton->setObjectName("uploadPushButton");
        uploadPushButton->setMinimumSize(QSize(0, 0));
        uploadPushButton->setFont(font);
        uploadPushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"     background-color: #2980B9;\n"
"    border: 1px solid #4A5D6E;\n"
"    border-radius: 4px;\n"
"    color: #E0E0E0;\n"
"    padding: 6px 12px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #4A5D6E;\n"
"    border-color: #5B6E80;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #2C3E50;\n"
"    padding: 7px 11px 5px 13px;\n"
"}"));

        horizontalLayout_2->addWidget(uploadPushButton);


        verticalLayout_2->addLayout(horizontalLayout_2);

        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setFont(font);
        groupBox_3->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 1px solid #3A4A5D;\n"
"    border-radius: 4px;\n"
"    margin-top: 10px;\n"
"    padding-top: 15px;\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    left: 10px;\n"
"    padding: 0 5px;\n"
"    color: #E0E0E0;\n"
"    font-weight: bold;\n"
"}"));
        horizontalLayout_3 = new QHBoxLayout(groupBox_3);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        normASpinBox = new QDoubleSpinBox(groupBox_3);
        normASpinBox->setObjectName("normASpinBox");
        normASpinBox->setFont(font);
        normASpinBox->setStyleSheet(QString::fromUtf8("QDoubleSpinBox, QSpinBox {\n"
"    background-color: #2C3E50;\n"
"    border: 1px solid #3A4A5D;\n"
"    border-radius: 3px;\n"
"    color: #E0E0E0;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QDoubleSpinBox:hover, QSpinBox:hover {\n"
"    border-color: #4A5D6E;\n"
"}\n"
"\n"
"QDoubleSpinBox::up-button, QSpinBox::up-button {\n"
"    width: 16px;\n"
"    subcontrol-origin: border;\n"
"    left: -2px;\n"
"}\n"
"\n"
"QDoubleSpinBox::down-button, QSpinBox::down-button {\n"
"    width: 16px;\n"
"    subcontrol-origin: border;\n"
"    left: -2px;\n"
"}"));
        normASpinBox->setMinimum(-1000000.000000000000000);
        normASpinBox->setMaximum(1000000.000000000000000);
        normASpinBox->setValue(0.000000000000000);

        horizontalLayout_3->addWidget(normASpinBox);

        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName("label_2");
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: #E0E0E0;\n"
"    font-size: 13px;\n"
"    padding: 5px;\n"
"}"));

        horizontalLayout_3->addWidget(label_2);

        normBSpinBox = new QDoubleSpinBox(groupBox_3);
        normBSpinBox->setObjectName("normBSpinBox");
        normBSpinBox->setFont(font);
        normBSpinBox->setStyleSheet(QString::fromUtf8("QDoubleSpinBox, QSpinBox {\n"
"    background-color: #2C3E50;\n"
"    border: 1px solid #3A4A5D;\n"
"    border-radius: 3px;\n"
"    color: #E0E0E0;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QDoubleSpinBox:hover, QSpinBox:hover {\n"
"    border-color: #4A5D6E;\n"
"}\n"
"\n"
"QDoubleSpinBox::up-button, QSpinBox::up-button {\n"
"    width: 16px;\n"
"    subcontrol-origin: border;\n"
"    left: -2px;\n"
"}\n"
"\n"
"QDoubleSpinBox::down-button, QSpinBox::down-button {\n"
"    width: 16px;\n"
"    subcontrol-origin: border;\n"
"    left: -2px;\n"
"}"));
        normBSpinBox->setMinimum(-1000000.000000000000000);
        normBSpinBox->setMaximum(1000000.000000000000000);
        normBSpinBox->setValue(1.000000000000000);

        horizontalLayout_3->addWidget(normBSpinBox);

        normalizeButton = new QPushButton(groupBox_3);
        normalizeButton->setObjectName("normalizeButton");
        normalizeButton->setFont(font);
        normalizeButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"     background-color: #2980B9;\n"
"    border: 1px solid #4A5D6E;\n"
"    border-radius: 4px;\n"
"    color: #E0E0E0;\n"
"    padding: 6px 12px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #4A5D6E;\n"
"    border-color: #5B6E80;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #2C3E50;\n"
"    padding: 7px 11px 5px 13px;\n"
"}"));

        horizontalLayout_3->addWidget(normalizeButton);


        verticalLayout_2->addWidget(groupBox_3);

        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName("groupBox_4");
        groupBox_4->setFont(font);
        groupBox_4->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 1px solid #3A4A5D;\n"
"    border-radius: 4px;\n"
"    margin-top: 10px;\n"
"    padding-top: 15px;\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    left: 10px;\n"
"    padding: 0 5px;\n"
"    color: #E0E0E0;\n"
"    font-weight: bold;\n"
"}"));
        horizontalLayout_4 = new QHBoxLayout(groupBox_4);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        stepSpinBox = new QDoubleSpinBox(groupBox_4);
        stepSpinBox->setObjectName("stepSpinBox");
        stepSpinBox->setFont(font);
        stepSpinBox->setStyleSheet(QString::fromUtf8("QDoubleSpinBox, QSpinBox {\n"
"    background-color: #2C3E50;\n"
"    border: 1px solid #3A4A5D;\n"
"    border-radius: 3px;\n"
"    color: #E0E0E0;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QDoubleSpinBox:hover, QSpinBox:hover {\n"
"    border-color: #4A5D6E;\n"
"}\n"
"\n"
"QDoubleSpinBox::up-button, QSpinBox::up-button {\n"
"    width: 16px;\n"
"    subcontrol-origin: border;\n"
"    left: -2px;\n"
"}\n"
"\n"
"QDoubleSpinBox::down-button, QSpinBox::down-button {\n"
"    width: 16px;\n"
"    subcontrol-origin: border;\n"
"    left: -2px;\n"
"}"));
        stepSpinBox->setMinimum(1.000000000000000);
        stepSpinBox->setMaximum(100.000000000000000);
        stepSpinBox->setValue(1.000000000000000);

        horizontalLayout_4->addWidget(stepSpinBox);


        verticalLayout_2->addWidget(groupBox_4);


        horizontalLayout->addLayout(verticalLayout_2);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        rotateXPlusButton = new QPushButton(centralwidget);
        rotateXPlusButton->setObjectName("rotateXPlusButton");
        rotateXPlusButton->setFont(font);
        rotateXPlusButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #3A4A5D;\n"
"    border: 1px solid #4A5D6E;\n"
"    border-radius: 4px;\n"
"    color: #E0E0E0;\n"
"    padding: 6px 12px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #4A5D6E;\n"
"    border-color: #5B6E80;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #2C3E50;\n"
"    padding: 7px 11px 5px 13px;\n"
"}"));

        gridLayout->addWidget(rotateXPlusButton, 0, 0, 1, 1);

        rotateXMinusButton = new QPushButton(centralwidget);
        rotateXMinusButton->setObjectName("rotateXMinusButton");
        rotateXMinusButton->setFont(font);
        rotateXMinusButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #3A4A5D;\n"
"    border: 1px solid #4A5D6E;\n"
"    border-radius: 4px;\n"
"    color: #E0E0E0;\n"
"    padding: 6px 12px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #4A5D6E;\n"
"    border-color: #5B6E80;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #2C3E50;\n"
"    padding: 7px 11px 5px 13px;\n"
"}"));

        gridLayout->addWidget(rotateXMinusButton, 0, 1, 1, 1);

        rotateZPlusButton = new QPushButton(centralwidget);
        rotateZPlusButton->setObjectName("rotateZPlusButton");
        rotateZPlusButton->setFont(font);
        rotateZPlusButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #3A4A5D;\n"
"    border: 1px solid #4A5D6E;\n"
"    border-radius: 4px;\n"
"    color: #E0E0E0;\n"
"    padding: 6px 12px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #4A5D6E;\n"
"    border-color: #5B6E80;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #2C3E50;\n"
"    padding: 7px 11px 5px 13px;\n"
"}"));

        gridLayout->addWidget(rotateZPlusButton, 2, 0, 1, 1);

        rotateYPlusButton = new QPushButton(centralwidget);
        rotateYPlusButton->setObjectName("rotateYPlusButton");
        rotateYPlusButton->setFont(font);
        rotateYPlusButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #3A4A5D;\n"
"    border: 1px solid #4A5D6E;\n"
"    border-radius: 4px;\n"
"    color: #E0E0E0;\n"
"    padding: 6px 12px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #4A5D6E;\n"
"    border-color: #5B6E80;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #2C3E50;\n"
"    padding: 7px 11px 5px 13px;\n"
"}"));

        gridLayout->addWidget(rotateYPlusButton, 1, 0, 1, 1);

        translateXPlusButton = new QPushButton(centralwidget);
        translateXPlusButton->setObjectName("translateXPlusButton");
        translateXPlusButton->setFont(font);
        translateXPlusButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #3A4A5D;\n"
"    border: 1px solid #4A5D6E;\n"
"    border-radius: 4px;\n"
"    color: #E0E0E0;\n"
"    padding: 6px 12px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #4A5D6E;\n"
"    border-color: #5B6E80;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #2C3E50;\n"
"    padding: 7px 11px 5px 13px;\n"
"}"));

        gridLayout->addWidget(translateXPlusButton, 0, 2, 1, 1);

        rotateYMinusButton = new QPushButton(centralwidget);
        rotateYMinusButton->setObjectName("rotateYMinusButton");
        rotateYMinusButton->setFont(font);
        rotateYMinusButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #3A4A5D;\n"
"    border: 1px solid #4A5D6E;\n"
"    border-radius: 4px;\n"
"    color: #E0E0E0;\n"
"    padding: 6px 12px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #4A5D6E;\n"
"    border-color: #5B6E80;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #2C3E50;\n"
"    padding: 7px 11px 5px 13px;\n"
"}"));

        gridLayout->addWidget(rotateYMinusButton, 1, 1, 1, 1);

        rotateZMinusButton = new QPushButton(centralwidget);
        rotateZMinusButton->setObjectName("rotateZMinusButton");
        rotateZMinusButton->setFont(font);
        rotateZMinusButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #3A4A5D;\n"
"    border: 1px solid #4A5D6E;\n"
"    border-radius: 4px;\n"
"    color: #E0E0E0;\n"
"    padding: 6px 12px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #4A5D6E;\n"
"    border-color: #5B6E80;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #2C3E50;\n"
"    padding: 7px 11px 5px 13px;\n"
"}"));

        gridLayout->addWidget(rotateZMinusButton, 2, 1, 1, 1);

        translateXMinusButton = new QPushButton(centralwidget);
        translateXMinusButton->setObjectName("translateXMinusButton");
        translateXMinusButton->setFont(font);
        translateXMinusButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #3A4A5D;\n"
"    border: 1px solid #4A5D6E;\n"
"    border-radius: 4px;\n"
"    color: #E0E0E0;\n"
"    padding: 6px 12px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #4A5D6E;\n"
"    border-color: #5B6E80;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #2C3E50;\n"
"    padding: 7px 11px 5px 13px;\n"
"}"));

        gridLayout->addWidget(translateXMinusButton, 0, 3, 1, 1);

        translateYPlusButton = new QPushButton(centralwidget);
        translateYPlusButton->setObjectName("translateYPlusButton");
        translateYPlusButton->setFont(font);
        translateYPlusButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #3A4A5D;\n"
"    border: 1px solid #4A5D6E;\n"
"    border-radius: 4px;\n"
"    color: #E0E0E0;\n"
"    padding: 6px 12px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #4A5D6E;\n"
"    border-color: #5B6E80;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #2C3E50;\n"
"    padding: 7px 11px 5px 13px;\n"
"}"));

        gridLayout->addWidget(translateYPlusButton, 1, 2, 1, 1);

        translateYMinusButton = new QPushButton(centralwidget);
        translateYMinusButton->setObjectName("translateYMinusButton");
        translateYMinusButton->setFont(font);
        translateYMinusButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #3A4A5D;\n"
"    border: 1px solid #4A5D6E;\n"
"    border-radius: 4px;\n"
"    color: #E0E0E0;\n"
"    padding: 6px 12px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #4A5D6E;\n"
"    border-color: #5B6E80;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #2C3E50;\n"
"    padding: 7px 11px 5px 13px;\n"
"}"));

        gridLayout->addWidget(translateYMinusButton, 1, 3, 1, 1);

        translateZPlusButton = new QPushButton(centralwidget);
        translateZPlusButton->setObjectName("translateZPlusButton");
        translateZPlusButton->setFont(font);
        translateZPlusButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #3A4A5D;\n"
"    border: 1px solid #4A5D6E;\n"
"    border-radius: 4px;\n"
"    color: #E0E0E0;\n"
"    padding: 6px 12px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #4A5D6E;\n"
"    border-color: #5B6E80;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #2C3E50;\n"
"    padding: 7px 11px 5px 13px;\n"
"}"));

        gridLayout->addWidget(translateZPlusButton, 2, 2, 1, 1);

        translateZMinusButton = new QPushButton(centralwidget);
        translateZMinusButton->setObjectName("translateZMinusButton");
        translateZMinusButton->setFont(font);
        translateZMinusButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #3A4A5D;\n"
"    border: 1px solid #4A5D6E;\n"
"    border-radius: 4px;\n"
"    color: #E0E0E0;\n"
"    padding: 6px 12px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #4A5D6E;\n"
"    border-color: #5B6E80;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #2C3E50;\n"
"    padding: 7px 11px 5px 13px;\n"
"}"));

        gridLayout->addWidget(translateZMinusButton, 2, 3, 1, 1);

        zoomInButton = new QPushButton(centralwidget);
        zoomInButton->setObjectName("zoomInButton");
        zoomInButton->setFont(font);
        zoomInButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"     background-color: #2980B9;;\n"
"    border: 1px solid #4A5D6E;\n"
"    border-radius: 4px;\n"
"    color: #E0E0E0;\n"
"    padding: 6px 12px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #4A5D6E;\n"
"    border-color: #5B6E80;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #2C3E50;\n"
"    padding: 7px 11px 5px 13px;\n"
"}"));

        gridLayout->addWidget(zoomInButton, 6, 2, 1, 2);

        zoomOutButton = new QPushButton(centralwidget);
        zoomOutButton->setObjectName("zoomOutButton");
        zoomOutButton->setFont(font);
        zoomOutButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"     background-color: #2980B9;\n"
"    border: 1px solid #4A5D6E;\n"
"    border-radius: 4px;\n"
"    color: #E0E0E0;\n"
"    padding: 6px 12px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #4A5D6E;\n"
"    border-color: #5B6E80;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #2C3E50;\n"
"    padding: 7px 11px 5px 13px;\n"
"}"));

        gridLayout->addWidget(zoomOutButton, 6, 0, 1, 2);

        resetViewButton = new QPushButton(centralwidget);
        resetViewButton->setObjectName("resetViewButton");
        resetViewButton->setFont(font);
        resetViewButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"     background-color: #27AE60;\n"
"    border-color: #16A085;\n"
"    border: 1px solid #4A5D6E;\n"
"    border-radius: 4px;\n"
"    color: #E0E0E0;\n"
"    padding: 6px 12px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #4A5D6E;\n"
"    border-color: #5B6E80;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #2C3E50;\n"
"    padding: 7px 11px 5px 13px;\n"
"}"));

        gridLayout->addWidget(resetViewButton, 8, 0, 1, 4);

        exitButton = new QPushButton(centralwidget);
        exitButton->setObjectName("exitButton");
        exitButton->setFont(font);
        exitButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #E74C3C;\n"
"    border-color: #C0392B;\n"
"    border: 1px solid #4A5D6E;\n"
"    border-radius: 4px;\n"
"    color: #E0E0E0;\n"
"    padding: 6px 12px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #4A5D6E;\n"
"    border-color: #5B6E80;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #2C3E50;\n"
"    padding: 7px 11px 5px 13px;\n"
"}"));

        gridLayout->addWidget(exitButton, 9, 0, 1, 4);


        horizontalLayout->addLayout(gridLayout);


        verticalLayout->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Main Window", nullptr));
        filePushButton->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
        uploadPushButton->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \320\264\320\260\320\275\320\275\321\213\320\265", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "\320\235\320\276\321\200\320\274\320\270\321\200\320\276\320\262\320\272\320\260", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\264\320\276", nullptr));
        normalizeButton->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "\320\250\320\260\320\263 \321\202\320\276\321\207\320\265\320\272", nullptr));
        rotateXPlusButton->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\262\320\276\321\200\320\276\321\202 X+", nullptr));
        rotateXMinusButton->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\262\320\276\321\200\320\276\321\202 X-", nullptr));
        rotateZPlusButton->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\262\320\276\321\200\320\276\321\202 Z+", nullptr));
        rotateYPlusButton->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\262\320\276\321\200\320\276\321\202 Y+", nullptr));
        translateXPlusButton->setText(QCoreApplication::translate("MainWindow", "\320\241\320\264\320\262\320\270\320\263 X+", nullptr));
        rotateYMinusButton->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\262\320\276\321\200\320\276\321\202 Y-", nullptr));
        rotateZMinusButton->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\262\320\276\321\200\320\276\321\202 Z-", nullptr));
        translateXMinusButton->setText(QCoreApplication::translate("MainWindow", "\320\241\320\264\320\262\320\270\320\263 X-", nullptr));
        translateYPlusButton->setText(QCoreApplication::translate("MainWindow", "\320\241\320\264\320\262\320\270\320\263 Y+", nullptr));
        translateYMinusButton->setText(QCoreApplication::translate("MainWindow", "\320\241\320\264\320\262\320\270\320\263 Y-", nullptr));
        translateZPlusButton->setText(QCoreApplication::translate("MainWindow", "\320\241\320\264\320\262\320\270\320\263 Z+", nullptr));
        translateZMinusButton->setText(QCoreApplication::translate("MainWindow", "\320\241\320\264\320\262\320\270\320\263 Z-", nullptr));
        zoomInButton->setText(QCoreApplication::translate("MainWindow", "\320\243\320\262\320\265\320\273\320\270\321\207\320\270\321\202\321\214", nullptr));
        zoomOutButton->setText(QCoreApplication::translate("MainWindow", "\320\243\320\274\320\265\320\275\321\214\321\210\320\270\321\202\321\214", nullptr));
        resetViewButton->setText(QCoreApplication::translate("MainWindow", "\320\241\320\261\321\200\320\276\321\201 \320\262\320\270\320\264\320\260", nullptr));
        exitButton->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
