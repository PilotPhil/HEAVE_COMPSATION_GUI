#include "pid.h"


PID::PID(float _kp, float _ki, float _kd, QObject *parent):
    kp(_kp),ki(_ki),kd(_kd),QObject(parent)
{
    e = target - actual;
    e_pre = e;
}

float PID::control(float targetValue, float actualValue)
{
    float u;
    target = targetValue; //目标值
    actual = actualValue; //真实值（传感器所测）
    e = target - actual;  // error误差
    integral += e;        //误差累积（积分）
    u = kp * e + ki * integral + kd * (e - e_pre); // pid核心
    e_pre = e;                                     //

    emit sendPidOutput(u);
    return u;
}

float PID::control(float actualValue)
{
    return control(0,actualValue);
}
