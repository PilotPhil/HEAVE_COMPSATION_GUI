#include "motorprotocol.h"

MotorProtocol::MotorProtocol(char _motorId,QObject *parent) : QObject(parent),motorId(_motorId)
{

}

QByteArray MotorProtocol::motoOff()
{
    QByteArray array;

    array[0]=0x3E;
    array[1]=0x80;
    array[2]=motorId;//电机ID
    array[3]=0x00;//电机ID
    array[4]=hexSum(array,0,3);//0~3字节校验和

    return array;
}

QByteArray MotorProtocol::motoStop()
{
    QByteArray array;

    array[0]=0x3E;
    array[1]=0x81;
    array[2]=motorId;//电机ID
    array[3]=0x00;
    array[4]=hexSum(array,0,3);//0~3字节校验和

    return array;
}

QByteArray MotorProtocol::motoRun()
{
    QByteArray array;

    array[0]=0x3E;
    array[1]=0x88;
    array[2]=motorId;//电机ID
    array[3]=0x00;
    array[4]=hexSum(array,0,3);//0~3字节校验和

    return array;
}

QByteArray MotorProtocol::speedCloseLoopControl(int speed)
{
    char HH=0x00;
    char H=0x00;
    char L=0x00;
    char LL=0x00;


    speed*=100;
    HH=speed>>24;
    H=(speed>>16)&0xFF;
    L=(speed>>8)&0xFF;
    LL=speed&0xFF;

    QByteArray array;

    array[0]=0x3E;
    array[1]=0xA2;
    array[2]=motorId;//电机ID
    array[3]=0x04;
    array[4]=hexSum(array,0,3);//0~3字节校验和

    array[5]=LL;
    array[6]=L;
    array[7]=H;
    array[8]=HH;
    array[9]=hexSum(array,5,8);

    return array;
}

char MotorProtocol::hexSum(const QByteArray &byteArray, const int st, const int ed)
{
    char tem=0x00;
    for(int i=st;i<=ed;i++)
    {
        tem+=byteArray[i];
    }
    return tem;
}
