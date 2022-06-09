#ifndef PARAMS_H
#define PARAMS_H

#include <QObject>

class Params : public QObject
{
    Q_OBJECT
public:
    static Params* m_Instance;
    static Params* GetInstance();



private:
    explicit Params(QObject *parent = nullptr);

signals:

public:
    float kp=0;
    float ki=0;
    float kd=0;

    float target=0;

    float vel_imu=0;
    float vel_motor=0;

    float speed=0;

    bool isInControl=false;
};

#endif // PARAMS_H
