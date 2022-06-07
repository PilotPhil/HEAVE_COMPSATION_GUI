#ifndef IMUDRIVER_H
#define IMUDRIVER_H

#include <QObject>
#include <QDebug>
#include <QtSerialPort/QSerialPort>
#include "ImuData.h"
#include "crc_table.h"

#define FRAME_HEAD 0xfc
#define FRAME_END 0xfd
#define TYPE_BODY_VEL 0x60
#define BODY_VEL_LEN 0x0c //12

union u_vel{
    float_t v;
    QByteArray bytes[4];
};


class ImuDriver : public QObject
{
    Q_OBJECT
public:
    explicit ImuDriver(const QString& _portName,int _baudRate,QObject *parent = nullptr);

    /**
     * @brief processLoop 处理循环
     */
    void processLoop();

    /**
     * @brief checkCS8
     * @param len
     * @return
     */
    bool checkCS8(int len);

    /**
     * @brief checkCS16
     * @param len
     * @return
     */
    bool checkCS16(int len);

    /**
     * @brief parseVelocity 解析速度
     */
    void parseVelocity();

    QString toHexadecimal(const QByteArray &byteArray)
    {
        QString str;
        for(int i = 0; i< byteArray.length(); i++){
            QString byteStr = QString::number(static_cast<uchar>(byteArray[i]), 16);
            if(byteStr.length() == 1) str += "0" + byteStr;
            else str += byteStr;
        }
        qDebug()<<str;
        return str;
    }

signals:

    void sendVelocityZ(float vel);

private:
    QSerialPort* serial;

    /**
     * @brief BODY_VEL_frame_
     */
    body_vel_frame_read BODY_VEL_frame_;

    /**
     * @brief Byte2Float 转浮点数
     * @param byte
     * @return
     */
    float byte2float(QByteArray& byte);

};

#endif // IMUDRIVER_H
