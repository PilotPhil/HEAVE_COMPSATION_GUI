#ifndef UTIL_H
#define UTIL_H

#include <QString>
#include <QDebug>

/**
 * @brief toHexadecimal 转为十六进制字符串
 * @param byteArray
 * @return
 */
QString toHexadecimal(const QByteArray &byteArray);


/**
 * @brief Byte2Float 转浮点数
 * @param byte
 * @return
 */
float byte2float(QByteArray& byte);


int SignedHex2Int(QByteArray array);


int bytesToInt(QByteArray bytes);

#endif // UTIL_H
