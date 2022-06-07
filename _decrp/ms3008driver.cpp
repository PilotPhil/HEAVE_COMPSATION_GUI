#include "ms3008driver.h"

MS3008Driver::MS3008Driver(QObject *parent,char _motoId)
    : QObject(parent),motoId(_motoId)
{

}

char MS3008Driver::HexSum(const QByteArray &byteArray, const int st, const int ed)
{
    char tem=0x00;
    for(int i=st;i<=ed;i++)
    {
        tem+=byteArray[i];
    }
    return tem;
}


QByteArray MS3008Driver::ReadPidParams()
{
    QByteArray array;

    array[0]=0x3E;
    array[1]=0x30;
    array[2]=this->motoId;//电机ID
    array[3]=0x00;
    array[4]=HexSum(array,0,3);//0~3字节校验和

    return array;
}

int MS3008Driver::ReceivePidParams(const QByteArray &array)
{
    if(array[1]!=0x30 && array.length()!=12)
    {
        cout<<"ERROR: Receive Pid Params"<<endl;
        return -1;
    }

    this->pid_angle.kp=array[5];
    this->pid_angle.ki=array[6];

    this->pid_speed.kp=array[7];
    this->pid_speed.ki=array[8];

    this->pid_iq.kp=array[9];
    this->pid_iq.ki=array[10];

    return 0;
}

QByteArray MS3008Driver::WritePidParams2RAM(const pid &speed_pid, const pid &angle_pid, const pid &iq_pid)
{
    QByteArray array;

    array[0]=0x3E;
    array[1]=0x31;
    array[2]=this->motoId;//电机ID
    array[3]=0x06;//电机ID
    array[4]=HexSum(array,0,3);//0~3字节校验和
    array[5]=angle_pid.kp;
    array[6]=angle_pid.ki;
    array[7]=speed_pid.kp;
    array[8]=speed_pid.ki;
    array[9]=iq_pid.kp;
    array[10]=iq_pid.ki;
    array[11]=HexSum(array,5,10);

    return array;
}

QByteArray MS3008Driver::WritePidParams2ROM(const pid &speed_pid, const pid &angle_pid, const pid &iq_pid)
{
    QByteArray array;

    array[0]=0x3E;
    array[1]=0x32;
    array[2]=this->motoId;//电机ID
    array[3]=0x06;//电机ID
    array[4]=HexSum(array,0,3);//0~3字节校验和
    array[5]=angle_pid.kp;
    array[6]=angle_pid.ki;
    array[7]=speed_pid.kp;
    array[8]=speed_pid.ki;
    array[9]=iq_pid.kp;
    array[10]=iq_pid.ki;
    array[11]=HexSum(array,5,10);

    return array;
}

QByteArray MS3008Driver::ReadAcc()
{
    QByteArray array;

    array[0]=0x3E;
    array[1]=0x33;
    array[2]=this->motoId;//电机ID
    array[3]=0x00;//电机ID
    array[4]=HexSum(array,0,3);//0~3字节校验和

    return array;
}

QByteArray MS3008Driver::ReadEncoder()
{
    QByteArray array;

    array[0]=0x3E;
    array[1]=0x90;
    array[2]=this->motoId;//电机ID
    array[3]=0x00;//电机ID
    array[4]=HexSum(array,0,3);//0~3字节校验和

    return array;
}

QByteArray MS3008Driver::WriteCurrentAngle2ROMAsZero()
{
    QByteArray array;

    array[0]=0x3E;
    array[1]=0x19;
    array[2]=this->motoId;//电机ID
    array[3]=0x00;//电机ID
    array[4]=HexSum(array,0,3);//0~3字节校验和

    return array;
}

QByteArray MS3008Driver::ReadMultiLoopAngle()
{
    QByteArray array;

    array[0]=0x3E;
    array[1]=0x92;
    array[2]=this->motoId;//电机ID
    array[3]=0x00;//电机ID
    array[4]=HexSum(array,0,3);//0~3字节校验和

    return array;
}

QByteArray MS3008Driver::ReadSingleLoopAngle()
{
    QByteArray array;

    array[0]=0x3E;
    array[1]=0x94;
    array[2]=this->motoId;//电机ID
    array[3]=0x00;//电机ID
    array[4]=HexSum(array,0,3);//0~3字节校验和

    return array;
}

QByteArray MS3008Driver::ReadMotoState1andErrorFlag()
{
    QByteArray array;

    array[0]=0x3E;
    array[1]=0x9A;
    array[2]=this->motoId;//电机ID
    array[3]=0x00;//电机ID
    array[4]=HexSum(array,0,3);//0~3字节校验和

    return array;
}

QByteArray MS3008Driver::ClearMotoErrorFlag()
{
    QByteArray array;

    array[0]=0x3E;
    array[1]=0x9B;
    array[2]=this->motoId;//电机ID
    array[3]=0x00;//电机ID
    array[4]=HexSum(array,0,3);//0~3字节校验和

    return array;
}

QByteArray MS3008Driver::ReadMotoState2()
{
    QByteArray array;

    array[0]=0x3E;
    array[1]=0x9C;
    array[2]=this->motoId;//电机ID
    array[3]=0x00;//电机ID
    array[4]=HexSum(array,0,3);//0~3字节校验和

    return array;
}

QByteArray MS3008Driver::ReadMotoState3()
{
    QByteArray array;

    array[0]=0x3E;
    array[1]=0x9D;
    array[2]=this->motoId;//电机ID
    array[3]=0x00;//电机ID
    array[4]=HexSum(array,0,3);//0~3字节校验和

    return array;
}

QByteArray MS3008Driver::MotoShutDown()
{
    QByteArray array;

    array[0]=0x3E;
    array[1]=0x80;
    array[2]=this->motoId;//电机ID
    array[3]=0x00;//电机ID
    array[4]=HexSum(array,0,3);//0~3字节校验和

    return array;
}

QByteArray MS3008Driver::MotoStop()
{
    QByteArray array;

    array[0]=0x3E;
    array[1]=0x81;
    array[2]=this->motoId;//电机ID
    array[3]=0x00;
    array[4]=HexSum(array,0,3);//0~3字节校验和

    return array;
}

QByteArray MS3008Driver::MotoRun()
{
    QByteArray array;

    array[0]=0x3E;
    array[1]=0x88;
    array[2]=this->motoId;//电机ID
    array[3]=0x00;
    array[4]=HexSum(array,0,3);//0~3字节校验和

    return array;
}

QByteArray MS3008Driver::OpenLoopControl(const int power)
{
    QByteArray array;

    array[0]=0x3E;
    array[1]=0xA0;
    array[2]=this->motoId;//电机ID
    array[3]=0x00;
    array[4]=HexSum(array,0,3);//0~3字节校验和
    array[5]=power&0xff;//输出功率控制低字节
    array[6]=power>>8;//输出功率控制高字节
    array[7]=HexSum(array,5,6);

    return array;
}

QByteArray MS3008Driver::SpeedCloseLoopControl(int speed)
{
    char HH=0x00;
    char H=0x00;
    char L=0x00;
    char LL=0x00;

    if(speed>=0 && speed<=500)
    {
        speed*=100;

        L=speed>>8;
        LL=speed&0xff;
    }
    else if(speed<0 && speed>=-500)
    {
        speed*=100;
        HH=speed>>24;
        H=(speed>>16)&0xFF;
        L=(speed>>8)&0xFF;
        LL=speed&0xFF;
    }

    QByteArray array;

    array[0]=0x3E;
    array[1]=0xA2;
    array[2]=this->motoId;//电机ID
    array[3]=0x04;
    array[4]=HexSum(array,0,3);//0~3字节校验和

    array[5]=LL;
    array[6]=L;
    array[7]=H;
    array[8]=HH;
    array[9]=HexSum(array,5,8);

    return array;
}

QByteArray MS3008Driver::MultiLapAngleCloseLoopControl1(int degree)
{
    char c1,c2,c3,c4,c5,c6,c7,c8;
    c1=c2=c3=c4=c5=c6=c7=c8=0x00;

    if(degree>=0 && degree<=360)
    {
        degree*=100;

        c7=degree>>8;
        c8=degree&0xff;
    }
    else if(degree<0 && degree>=-360)
    {
        degree*=100;
        c1=c2=c3=c4=c5=c6=0xFF;

        c7=degree>>8;
        c8=degree&0xFF;
    }

    QByteArray array;

    array[0]=0x3E;
    array[1]=0xA3;
    array[2]=this->motoId;//电机ID
    array[3]=0x08;
    array[4]=HexSum(array,0,3);//0~3字节校验和

    array[5]=c8;
    array[6]=c7;
    array[7]=c6;
    array[8]=c5;
    array[9]=c4;
    array[10]=c3;
    array[11]=c2;
    array[12]=c1;
    array[13]=HexSum(array,5,12);

    return array;
}

QByteArray MS3008Driver::ReadDriverMotoModel()
{
    QByteArray array;

    array[0]=0x3E;
    array[1]=0x12;
    array[2]=this->motoId;//电机ID
    array[3]=0x00;
    array[4]=HexSum(array,0,3);//0~3字节校验和

    return array;
}

QByteArray MS3008Driver::SpeedClosedLoop(const int speed)
{
    QByteArray array;

    array[0]=(0x3E);//头字节
    array[1]=(0xA2);//命令字节
    array[2]=this->motoId;//电机ID
    array[3]=(0x04);//数据长度字节
    array[4]=HexSum(array,0,3);//0~3字节校验和
    array[5]=(0x98);//速度低字节
    array[6]=(0x3A);//速度
    array[7]=(0x00);//速度
    array[8]=(0x00);//速度高字节
    array[9]=HexSum(array,5,8);//5~8字节校验和

    return array;
}







