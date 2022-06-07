#ifndef MOTORPROTOCOL_H
#define MOTORPROTOCOL_H

#include <QObject>
#include <QByteArray>

class MotorProtocol : public QObject
{
    Q_OBJECT
protected:
    explicit MotorProtocol(char _motorId,QObject *parent = nullptr);

    /**
     * @brief 电机关闭
     * @return
     */
    QByteArray motoOff();

    /**
     * @brief MotoStop 电机停止
     * @return
     */
    QByteArray motoStop();

    /**
     * @brief MotoRun 电机运行（恢复之前的命令）
     * @return
     */
    QByteArray motoRun();


    /**
     * @brief SpeedCloseLoopControl 速度闭环控制命令
     * @param speed 速度
     * @return
     */
    QByteArray speedCloseLoopControl(int speed);

signals:

private:
    char motorId;

    /**
     * @brief HexSum 和校验
     * @param byteArray 要校验的 buffer
     * @param st 起始位
     * @param ed 结束位
     * @return
     */
    char hexSum(const QByteArray& byteArray,const int st=0,const int ed=1);

};

#endif // MOTORPROTOCOL_H
