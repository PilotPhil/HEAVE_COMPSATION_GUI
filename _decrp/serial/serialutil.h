#ifndef SERIALUTIL_H
#define SERIALUTIL_H

#include <QObject>
#include <iostream>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QByteArray>

using namespace std;

class Serialutil : public QObject
{
    Q_OBJECT
public:
    explicit Serialutil(QObject *parent = nullptr);

    QStringList ScanPorts();
    void SerialSwitch(const QString& portName);

    void WriteHEX(const QByteArray& array);

    void ReadSerialData();

signals:

private:
    QSerialPort* serial;

};

#endif // SWEIALUTIL_H
