#include "motordriver.h"

MotorDriver::MotorDriver(char _motorId,const QString &_portName, int _baudRate, QObject *parent):MotorProtocol(_motorId,parent)
{
    serial=new QSerialPort(this);

    //设置串口
    serial->setPortName(_portName);
    serial->setBaudRate(_baudRate);
    serial->setDataBits(QSerialPort::Data8);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setParity(QSerialPort::NoParity);

    if(serial->isOpen()==false)
    {
        auto flag=serial->open(QIODevice::ReadWrite);

        if(!flag)
        {
            qDebug()<<QString::fromLocal8Bit("串口打开失败");
        }
    }
}

MotorDriver::~MotorDriver()
{
    cmdMotorStop();

    if(serial->isOpen())
        serial->close();
}

bool MotorDriver::cmdMotorOff()
{
    auto cmd=motoOff();
    return sendCommand(cmd);
}

bool MotorDriver::cmdMotorStop()
{
    auto cmd=motoStop();
    return sendCommand(cmd);
}

bool MotorDriver::cmdMotorRun()
{
    auto cmd=motoRun();
    return sendCommand(cmd);
}

bool MotorDriver::cmdSpeedCloseLoopControl(int speed)
{
    auto cmd=speedCloseLoopControl(speed);
    return sendCommand(cmd);
}

bool MotorDriver::sendCommand(const QByteArray &cmd)
{
    if(serial->isOpen()==false)
        return false;

    auto len=serial->write(cmd);

    if(len==-1)
        return false;

    return true;
}
