#ifndef IMUDRIVER_H
#define IMUDRIVER_H

#include <QObject>
#include <QDebug>
#include <QtSerialPort/QSerialPort>


class ImuDriver : public QObject
{
    Q_OBJECT
public:
    explicit ImuDriver(const QString& _portName,int _baudRate,QObject *parent = nullptr);

    ~ImuDriver();

    /**
     * @brief parseVelocity 解析速度
     */
    void parseVelocity();

    /**
     * @brief getVelZ 获取速度
     * @return
     */
    float getVelZ() const { return velZ; }

signals:
    void sendVelocityZ(float vel);

private:
    QSerialPort* serial;

    /**
     * @brief Byte2Float 转浮点数
     * @param byte
     * @return
     */
    float byte2float(QByteArray& byte);

    /**
     * @brief toHexadecimal 转为十六进制字符串
     * @param byteArray
     * @return
     */
    QString toHexadecimal(const QByteArray &byteArray);

    /**
     * @brief vel_z Z轴速度
     */
    float velZ=0;

};

#endif // IMUDRIVER_H
