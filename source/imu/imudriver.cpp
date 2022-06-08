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
            qDebug()<<QString::fromLocal8Bit("IMU串口打开成功");
            connect(serial,&QSerialPort::readyRead,this,&ImuDriver::parseVelocity);
        }
        else
        {
            qDebug()<<QString::fromLocal8Bit("IMU串口打开失败");
        }
    }
}

ImuDriver::~ImuDriver()
{
    if(serial->isOpen())
    {
        serial->close();
        qDebug()<<QString::fromLocal8Bit("IMU串口已关闭");
    }
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

    qDebug()<<QString::fromLocal8Bit("IMU速度: ")<<velZ<<" m/s";

    emit sendVelocityZ(velZ);
}

QString ImuDriver::toHexadecimal(const QByteArray &byteArray)
{
    QString str;
    for(int i = 0; i< byteArray.length(); i++){
        QString byteStr = QString::number(static_cast<uchar>(byteArray[i]), 16);
        if(byteStr.length() == 1) str += "0" + byteStr;
        else str += byteStr;
    }
    qDebug()<<str;
    return str;
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


