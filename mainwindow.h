#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "appcontext.h"
#include "entrypoint.h"
#include "matrixtransformations.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    Point2D projectPoint(Point3D* point);
    void onFileClicked();
    void onUploadClicked();
    void onRotateXPlusClicked();
    void onRotateXMinusClicked();
    void onRotateYPlusClicked();
    void onRotateYMinusClicked();
    void onRotateZPlusClicked();
    void onRotateZMinusClicked();
    void onTranslateXPlusClicked();
    void onTranslateXMinusClicked();
    void onTranslateYPlusClicked();
    void onTranslateYMinusClicked();
    void onTranslateZPlusClicked();
    void onTranslateZMinusClicked();
    void onZoomInClicked();
    void onZoomOutClicked();
    void onResetViewClicked();
    void onExitClicked();
    void onNormalizeClicked();
    void onStepChanged(double value);

private:
    Ui::MainWindow *ui;
    AppContext context;
    void setupConnections();
    void drawSurface();
    void drawAxes();
};

#endif // MAINWINDOW_H
