#ifndef IMU_H
#define IMU_H

#include <QObject>

class Imu : public QObject
{
    Q_OBJECT
public:
    explicit Imu(QObject *parent = nullptr);

signals:

};

#endif // IMU_H
