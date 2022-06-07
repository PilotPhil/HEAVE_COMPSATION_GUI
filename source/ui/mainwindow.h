#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "motordriver.h"
#include "imudriver.h"
#include "pid.h"
#include "plotrealtimecurve.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_checkBox_serialSwitch_clicked(bool checked);

    void on_checkBox_controlSwitch_clicked(bool checked);

    void on_pushButton_positiveRotate_clicked();

    void on_pushButton_negativeRotate_clicked();

    void on_pushButton_rotateDegree_clicked();

    void on_pushButton_stopMotor_clicked();

private:
    Ui::MainWindow *ui;

    PID* pid;
    MotorDriver* motor;
    ImuDriver* imu;

    PlotRealtimeCurve* plot;
};
#endif // MAINWINDOW_H
