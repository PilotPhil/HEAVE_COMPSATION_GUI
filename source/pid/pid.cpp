#include "pid.h"
#include <QDebug>


PID::PID(float _kp, float _ki, float _kd, QObject *parent):
    kp(_kp),ki(_ki),kd(_kd),QObject(parent)
{
    e = target - actual;
    e_pre = e;

}

void PID::setPid(float p, float i, float d)
{
    kp=p;
    ki=i;
    kd=d;
}

float PID::control(float _target, float _actual)
{
    float u=0;
    target=_target;
    actual=_actual;

    e = target - actual;  // error误差
    integral += e;        //误差累积（积分）
    u = kp * e + ki * integral + kd * (e - e_pre); // pid核心
    e_pre = e;                                     //
    return u;
}

