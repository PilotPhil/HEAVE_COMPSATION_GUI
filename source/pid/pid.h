#ifndef PID_H
#define PID_H

#include <QObject>

class PID : public QObject
{
    Q_OBJECT
public:
    explicit PID(float _kp,float _ki,float _kd,QObject *parent = nullptr);

    void setTargetValue(float value){target=value;}

    float control(float actualValue);

signals:
    void sendPidOutput(float u);

private:
    float kp=10;       //比例系数
    float ki=0.01;       //积分系数
    float kd=0.01;       //微分系数
    float target=0;   //目标值
    float actual=0;   //实际值
    float e=0;        //误差
    float e_pre=0;    //上一次误差
    float integral=0; //积分项

};

#endif // PID_H
