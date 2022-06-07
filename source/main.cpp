#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

//    MotorDriver motor(0x01,"COM4",115200);
//    ImuDriver imu("COM3",921600);
//    PID pid(5000,0.01,0.01);

//    QObject::connect(&imu,&ImuDriver::sendVelocityZ,[&](float v)
//    {
//        pid.control(0,v);
//    });
//    QObject::connect(&pid,&PID::sendPidOutput,&motor,&MotorDriver::cmdSpeedCloseLoopControl);


////    QObject::connect(&imu,&ImuDriver::sendVelocityZ,[&](float v)
////    {
////        qDebug()<<v;
////    });

    return a.exec();
}
