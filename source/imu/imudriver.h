#ifndef IMUDRIVER_H
#define IMUDRIVER_H

#include <QDebug>
#include <QObject>
#include <QtSerialPort/QSerialPort>

class ImuDriver : public QObject {
  Q_OBJECT
 public:
  explicit ImuDriver(const QString& _portName, int _baudRate,
                     QObject* parent = nullptr);

  ~ImuDriver();

  /**
   * @brief getVelZ 获取Z轴速度
   * @return
   */
  float getVelZ() const { return velZ; }

  /**
   * @brief start imu开始读取
   */
  void start();

  /**
   * @brief stop imu停止读取
   */
  void stop();

 signals:

 private:
  QSerialPort* serial;

  /**
   * @brief parseVelocity 解析速度
   */
  void parseVelocity();

  /**
   * @brief vel_z Z轴速度
   */
  float velZ = 0;
};

#endif  // IMUDRIVER_H
