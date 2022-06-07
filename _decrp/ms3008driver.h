#ifndef MS3008DRIVER_H
#define MS3008DRIVER_H

#include <QObject>
#include <iostream>
#include <QByteArray>

using namespace std;

class pid
{
public:
    pid(){kp=ki=kd=0.0;}

    float kp;
    float ki;
    float kd;
};

class MS3008Driver : public QObject
{
    Q_OBJECT
public:
    explicit MS3008Driver(QObject *parent = nullptr,char _motoId=1);

    char MotoID() const{return this->motoId;}
    pid PidAngle() const{return this->pid_angle;}
    pid PidSpeed() const{return this->pid_speed;}
    pid PidIq() const{return this->pid_iq;}

public:
    char HexSum(const QByteArray& byteArray,const int st=0,const int ed=1);

    //1.读取pid参数命令
    QByteArray ReadPidParams();
    //解析返回pid参数
    int ReceivePidParams(const QByteArray& array);

    //2.写入PID参数至RAM（12bits）
    QByteArray WritePidParams2RAM(const pid& speed_pid,
                                  const pid& angle_pid,
                                  const pid& iq_pid);

    //3.写入PID参数至ROM（12bits）
    QByteArray WritePidParams2ROM(const pid& speed_pid,
                                  const pid& angle_pid,
                                  const pid& iq_pid);

    //4.读取加速度命令
    QByteArray ReadAcc();

    //5.写入加速度到RAM命令
    QByteArray WriteAccParams2RAM(/*---*/);//nimp

    //6.读取编码器命令
    QByteArray ReadEncoder();

    //7.写入编码器值作为电机零点命令
    QByteArray WriteEncoderValueAsZero(/*---*/);//nimp

    //8.写入当前位置到ROM作为电机零点
    QByteArray WriteCurrentAngle2ROMAsZero();

    //9.读取多圈角度命令
    QByteArray ReadMultiLoopAngle();

    //10.读取单圈角度命令
    QByteArray ReadSingleLoopAngle();

    //11.读取电机状态1和错误标志命令
    QByteArray ReadMotoState1andErrorFlag();

    //12.清除电机错误标志命令
    QByteArray ClearMotoErrorFlag();

    //13.读取电机状态2命令
    QByteArray ReadMotoState2();

    //14.读取电机状态3命令
    QByteArray ReadMotoState3();

    //15.关闭电机命令
    QByteArray MotoShutDown();

    //16.电机停止命令
    QByteArray MotoStop();

    //17.电机运行命令
    QByteArray MotoRun();

    //18.开环控制命令
    QByteArray OpenLoopControl(const int power);

    //19.转矩闭环控制命令
    //QByteArray TorqueCloseLoopControl(const int torque);//M-L M-X only

    //20.速度闭环控制命令
    QByteArray SpeedCloseLoopControl(int speed);

    //21.多圈位置闭环控制命令1
    QByteArray MultiLapAngleCloseLoopControl1(int degree);

    //22.多圈位置闭环控制命令2
    QByteArray MultiLapAngleCloseLoopControl2(/*---*/);//nimp

    //23.单圈位置闭环控制命令1
    QByteArray SingleLapCloseLoopControl1(/*---*/);//nimp

    //24.单圈位置闭环控制命令2
    QByteArray SingleLapCloseLoopControl2(/*---*/);//nimp

    //25.增量位置闭环控制命令1
    QByteArray DeltaAngleCloseLoopControl1(/*---*/);//nimp

    //26.增量位置闭环控制命令2
    QByteArray DeltaAngleCloseLoopControl2(/*---*/);//nimp

    //27.读取驱动和电机型号命令
    QByteArray ReadDriverMotoModel();

    QByteArray SpeedClosedLoop(const int speed=100);//


signals:

private:
     char motoId;//电机id
     pid pid_angle,pid_speed,pid_iq;//pid参数

};



#endif // MS3008DRIVER_H
