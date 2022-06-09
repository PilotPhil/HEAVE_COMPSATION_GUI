#include "imudriver.h"
#include "util.h"

ImuDriver::ImuDriver(const QString& _portName,int _baudRate,QObject *parent):QObject(parent)
{
    serial=new QSerialPort(this);

    serial->setPortName(_portName);
    serial->setBaudRate(_baudRate);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);

    if(serial->isOpen()==false)
    {
        auto flag=serial->open(QSerialPort::ReadOnly);

        if(flag)
        {
            qDebug()<<QString::fromLocal8Bit("IMU串口打开成功");
        }
        else
        {
            qDebug()<<QString::fromLocal8Bit("IMU串口打开失败");
        }
    }

    start();
}

ImuDriver::~ImuDriver()
{
    if(serial->isOpen())
    {
        serial->close();
        qDebug()<<QString::fromLocal8Bit("IMU串口已关闭");
    }
}

void ImuDriver::start()
{
    connect(serial,&QSerialPort::readyRead,this,&ImuDriver::parseVelocity);
}

void ImuDriver::stop()
{
    disconnect(serial,&QSerialPort::readyRead,this,&ImuDriver::parseVelocity);
}

void ImuDriver::parseVelocity()
{
    auto m=serial->readAll();

    if(m.length()!=20)
        return;

    if(m[0]!=char(0xfc))
    {
        qDebug()<<"err 0";
        return;
    }

    if(m[1]!=char(0x60))
    {
        qDebug()<<"err 1";
        return;
    }

    if(m[2]!=char(0x0c))
    {
        qDebug()<<"err 2";
        return;
    }

    if(m[19]!=char(0xfd))
    {
        qDebug()<<"err 19";
        return;
    }

    auto vel_z=m.mid(15,4);
    std::reverse(vel_z.begin(),vel_z.end());
    velZ=byte2float(vel_z);

//    qDebug()<<QString::fromLocal8Bit("IMU速度: ")<<velZ<<" m/s";
}

