#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QGridLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    motor=nullptr;
    pid=nullptr;
    imu=nullptr;

    plot=new PlotRealtimeCurve(this);
    QGridLayout* gl1=new QGridLayout(this);
    gl1->setMargin(0);
    gl1->addWidget(plot);
    ui->frame->setLayout(gl1);

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_checkBox_serialSwitch_clicked(bool checked)
{
    if(checked)
    {
        imu=new ImuDriver(ui->lineEdit_imu_portName->text(),ui->spinBox_imu_baudRate->value(),this);
        motor=new MotorDriver(0x01,ui->lineEdit_motor_portName->text(),ui->spinBox_motor_baudRate->value(),this);
        pid=new PID(ui->spinBox_kp->value(),ui->spinBox_ki->value(),ui->spinBox_kd->value(),this);
    }
    else
    {
        if(motor!=nullptr)
            delete motor;
        if(imu!=nullptr)
            delete imu;
        if(pid!=nullptr)
            delete pid;

        motor=nullptr;
        pid=nullptr;
        imu=nullptr;
    }
}


void MainWindow::on_checkBox_controlSwitch_clicked(bool checked)
{
    if(checked)
    {
        connect(imu,&ImuDriver::sendVelocityZ,this,[&](float v)
        {
            pid->control(v);
        });
        connect(pid,&PID::sendPidOutput,motor,&MotorDriver::cmdSpeedCloseLoopControl);
    }
    else
    {
        //disconnect(imu,&ImuDriver::sendVelocityZ,pid,&PID::control);
        disconnect(pid,&PID::sendPidOutput,motor,&MotorDriver::cmdSpeedCloseLoopControl);
    }

    if(motor!=nullptr)
    {
        motor->cmdMotorStop();
    }
}


void MainWindow::on_pushButton_positiveRotate_clicked()
{
    if(motor!=nullptr)
    {
        motor->cmdSpeedCloseLoopControl(1*ui->spinBox_speedValue->value());
    }
}


void MainWindow::on_pushButton_negativeRotate_clicked()
{
    if(motor!=nullptr)
    {
        motor->cmdSpeedCloseLoopControl(-1*ui->spinBox_speedValue->value());
    }
}


void MainWindow::on_pushButton_rotateDegree_clicked()
{
    if(motor!=nullptr)
    {
//        motor
    }
}


void MainWindow::on_pushButton_stopMotor_clicked()
{
    if(motor!=nullptr)
    {
        motor->cmdMotorStop();
    }
}

