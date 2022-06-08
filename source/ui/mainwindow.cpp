#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QGridLayout>
#include "inibase.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    motor=nullptr;
    pid=nullptr;
    imu=nullptr;

    plot=new PlotRealtimeCurve(this);
    plot->makeGraph();
    QGridLayout* gl1=new QGridLayout(this);
    gl1->setMargin(0);
    gl1->addWidget(plot);
    ui->frame->setLayout(gl1);

    scanPorts();

    ui->spinBox_kp->setValue(IniBase::GetInstance()->getValue("pid/kp").toInt());
    ui->spinBox_ki->setValue(IniBase::GetInstance()->getValue("pid/ki").toInt());
    ui->spinBox_kd->setValue(IniBase::GetInstance()->getValue("pid/kd").toInt());
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_checkBox_serialSwitch_clicked(bool checked)
{
    if(checked)
    {
        imu=new ImuDriver(ui->comboBox_imuPort->currentText(),ui->comboBox_imuBaudrate->currentText().toUInt(),this);
        motor=new MotorDriver(0x01,ui->comboBox_motorPort->currentText(),ui->comboBox_motorBaudrate->currentText().toUInt(),this);
        pid=new PID(ui->spinBox_kp->value(),ui->spinBox_ki->value(),ui->spinBox_kd->value(),this);

        connect(imu,&ImuDriver::sendVelocityZ,plot,&PlotRealtimeCurve::updateImuData);
        connect(motor,&MotorDriver::sendMotorVel,plot,&PlotRealtimeCurve::updateMotorData);
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
        pid=new PID(ui->spinBox_kp->value(),ui->spinBox_ki->value(),ui->spinBox_kd->value(),this);

        connect(imu,&ImuDriver::sendVelocityZ,pid,&PID::control);
        connect(pid,&PID::sendPidOutput,motor,&MotorDriver::cmdSpeedCloseLoopControl);
    }
    else
    {
        disconnect(imu,&ImuDriver::sendVelocityZ,pid,&PID::control);
        disconnect(pid,&PID::sendPidOutput,motor,&MotorDriver::cmdSpeedCloseLoopControl);

        if(pid!=nullptr)
        {
            delete pid;
        }
    }

    if(motor!=nullptr)
    {
        motor->cmdMotorStop();
    }
}


void MainWindow::scanPorts()
{
    ui->comboBox_imuPort->clear();
    ui->comboBox_motorPort->clear();

    auto portLists=QSerialPortInfo::availablePorts();

    for(auto p:portLists)
    {
        ui->comboBox_imuPort->addItem(p.portName());
        ui->comboBox_motorPort->addItem(p.portName());
    }
}


void MainWindow::on_checkBox_stopMotor_clicked()
{
    if(motor!=nullptr)
    {
        motor->cmdMotorStop();
    }
}


void MainWindow::on_pushButton_cmdMotorSpeed_clicked()
{
    if(motor==nullptr)
        return;

    int flag=0;
    ui->comboBox_motorSpeedFlag->currentText()=="+"?flag=1:flag=-1;
    auto speed=flag*ui->spinBox_speedValue->value();
    motor->cmdSpeedCloseLoopControl(speed);
}


void MainWindow::on_pushButton_cmdMotorDegree_clicked()
{
    if(motor==nullptr)
        return;

    int flag=0;
    ui->comboBox_motorDegreeFlag->currentText()=="+"?flag=1:flag=-1;
    auto speed=flag*ui->spinBox_degree->value();
//    motor->cmdSpeedCloseLoopControl(speed);
}


void MainWindow::on_pushButton_savePidCfg_clicked()
{
    IniBase::GetInstance()->setValue("pid/kp",QString::number(ui->spinBox_kp->value()));
    IniBase::GetInstance()->setValue("pid/ki",QString::number(ui->spinBox_ki->value()));
    IniBase::GetInstance()->setValue("pid/kd",QString::number(ui->spinBox_kd->value()));
}

