#include "imudriver.h"

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
            qDebug()<<"serial open succedd";
            connect(serial,&QSerialPort::readyRead,this,&ImuDriver::parseVelocity);
        }
        else
        {
            qDebug()<<QString::fromLocal8Bit("IMU串口打开失败");
        }
    }
}

void ImuDriver::parseVelocity()
{
    //1+1+1+1+1+2+12+1=20
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
    auto t=byte2float(vel_z);
    emit sendVelocityZ(t);
}

float ImuDriver::byte2float(QByteArray &byte)
{
    float result = 0;
    int size = byte.size();
    char* data_char = byte.data();
    char* p = (char*)&result;
    for(int index = 0; index < size; index++)
    {
        *(p + index) = *(data_char + size - 1 - index);
    }
    return result;
}


