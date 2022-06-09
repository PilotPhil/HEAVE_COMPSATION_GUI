#include "util.h"



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

float byte2float(QByteArray &byte)
{
    float result = 0;
    int size = byte.size();
    char* data_char = byte.data();
    char* p = (char*)&result;
    for(int index = 0; index < size; index++)
    {
        *(p + index) = *(data_char + size - 1 - index);
    }
    return result;
}

int SignedHex2Int(QByteArray array)
{
       QString qnum =array.toHex().data();
       int num;
       bool ok;
        num = qnum.toInt(&ok,16);
        if(!(qnum.at(0)>='0'&&qnum.at(0)<='7')){//非正数
            num = num & 0x7FFF;       //清除符号位
            num=32768-num;                   //反码
            num = num * -1;                //符号位
        }
      return num;
}

int bytesToInt(QByteArray bytes)
{
    int addr = bytes[0] & 0x000000FF;
    addr |= ((bytes[1] << 8) & 0x0000FF00);
    addr |= ((bytes[2] << 16) & 0x00FF0000);
    addr |= ((bytes[3] << 24) & 0xFF000000);
    return addr;
}
