#ifndef MOTOR_H
#define MOTOR_H

#include <iostream>
#include <vector>

// using byte=char;
using byte=uint8_t;
using bytes=std::vector<byte>;

class MotorProtocolRS485
{
private:
    byte id;

    /**
     * @brief 和校验
     * 
     * @param _bytes 
     * @param start 
     * @param end 
     * @return byte 
     */
    byte hexSumCheck(bytes _bytes,int start,int end);


public:
    /**
     * @brief Construct a new motor object ctor
     * 
     * @param _id 
     */
    MotorProtocolRS485(byte _id=0x01);

    /**
     * @brief Destroy the motor object dtor
     * 
     */
    ~MotorProtocolRS485();

    /**
     * @brief 电机停止
     * 
     */
    bytes motoStop();

    /**
     * @brief 点击运行（恢复之前的控制方式）
     * 
     */
    bytes motoRestore();

    /**
     * @brief 电机关闭
     * 
     */
    bytes motoOff();

    /**
     * @brief 闭环速度控制
     * 
     * @param speed 
     */
    bytes speedControlClosedLoop(int speed);

    /**
     * @brief 多圈角度闭环控制
     * 
     * @param degree 
     */
    bytes multiLapAngleCloseLoopControl1(int degree);
};



#endif