﻿#ifndef MOTORDRIVER_H
#define MOTORDRIVER_H

#include <QObject>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>
#include "motorprotocol.h"

class MotorDriver : public MotorProtocol
{
    Q_OBJECT
public:
    explicit MotorDriver(char _motorId,const QString& _portName,int _baudRate,QObject *parent = nullptr);

    ~MotorDriver();

    bool cmdMotorOff();

    bool cmdMotorStop();

    bool cmdMotorRun();

    bool cmdSpeedCloseLoopControl(int speed);

signals:

private:
    /**
     * @brief serial 串口对象
     */
    QSerialPort* serial;

    /**
     * @brief sendCommand 发送命令
     * @param cmd 命令
     * @return
     */
    bool sendCommand(const QByteArray& cmd);

};

#endif // MOTORDRIVER_H