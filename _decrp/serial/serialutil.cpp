#include "serialutil.h"

Serialutil::Serialutil(QObject *parent) : QObject(parent)
{
    serial=new QSerialPort();

    //serial->setPortName("COM6");
    serial->setBaudRate(115200);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);

    connect(serial,&QSerialPort::readyRead,this,&Serialutil::ReadSerialData);
}

QStringList Serialutil::ScanPorts()
{
    QList<QSerialPortInfo> portLists=QSerialPortInfo::availablePorts();

    QStringList ports;
    foreach(QSerialPortInfo pi,portLists)
    {
        ports.append(pi.portName());
    }
    return ports;
}

void Serialutil::SerialSwitch(const QString &portName)
{
    if(serial->isOpen()==false)//未开
    {
        serial->setPortName(portName);
        serial->open(QIODevice::ReadWrite);
        cout<<portName.toStdString()<<" opened!"<<endl;
    }
    else
    {
        serial->close();
        cout<<portName.toStdString()<<" closed!"<<endl;
    }
}

void Serialutil::WriteHEX(const QByteArray &array)
{
    this->serial->write(array);
}

void Serialutil::ReadSerialData()
{
    QByteArray serial_data=serial->readAll();
    cout<<"res"<<endl;
    cout<<serial_data.toInt()<<endl;
}



