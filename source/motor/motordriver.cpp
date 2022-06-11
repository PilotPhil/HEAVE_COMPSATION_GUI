#include "motordriver.h"

#include "util.h"

MotorDriver::MotorDriver(char _motorId, const QString &_portName, int _baudRate,
                         QObject *parent)
    : MotorProtocol(_motorId, parent) {
  serial = new QSerialPort(this);

  //设置串口
  serial->setPortName(_portName);
  serial->setBaudRate(_baudRate);
  serial->setDataBits(QSerialPort::Data8);
  serial->setStopBits(QSerialPort::OneStop);
  serial->setParity(QSerialPort::NoParity);

  if (serial->isOpen() == false) {
    auto flag = serial->open(QIODevice::ReadWrite);

    if (!flag) {
      qDebug() << QString::fromLocal8Bit("电机串口打开失败");
    } else {
      qDebug() << QString::fromLocal8Bit("电机串口打开成功");
    }
  }

  connect(serial, &QSerialPort::readyRead, this, &MotorDriver::parseMotorVel);
}

MotorDriver::~MotorDriver() {
  cmdMotorStop();

  if (serial->isOpen()) {
    serial->close();
    qDebug() << QString::fromLocal8Bit("电机串口已关闭");
  }
}

bool MotorDriver::cmdMotorOff() {
  auto cmd = motoOff();
  qDebug() << QString::fromLocal8Bit("电机关闭");
  return sendCommand(cmd);
}

bool MotorDriver::cmdMotorStop() {
  auto cmd = motoStop();
  qDebug() << QString::fromLocal8Bit("电机停止");
  return sendCommand(cmd);
}

bool MotorDriver::cmdMotorRun() {
  auto cmd = motoRun();
  qDebug() << QString::fromLocal8Bit("电机恢复");
  return sendCommand(cmd);
}

bool MotorDriver::cmdSpeedCloseLoopControl(int speed) {
  auto cmd = speedCloseLoopControl(speed);

  qDebug() << "speed: " << speed;
  //    qDebug()<<"cmd: "<<toHexadecimal(cmd);

  return sendCommand(cmd);
}

bool MotorDriver::sendCommand(const QByteArray &cmd) {
  if (serial->isOpen() == false) return false;

  auto len = serial->write(cmd);

  if (len == -1) return false;

  return true;
}

void MotorDriver::parseMotorVel() {
  auto bytes = serial->readAll();

  if (bytes.length() != 13) return;

  auto vel = bytes.mid(8, 2);
  std::reverse(vel.begin(), vel.end());

  auto jiaosudu = SignedHex2Int(vel);        //角速度
  auto xiansudu = jiaosudu * 0.0275 / 57.3;  //线速度

  //    qDebug()<<QString::fromLocal8Bit("电机角速度: ")<<jiaosudu<<" dps";
  //    qDebug()<<QString::fromLocal8Bit("货物线速度: ")<<xiansudu<<" m/s";

  motorV = xiansudu;
}
