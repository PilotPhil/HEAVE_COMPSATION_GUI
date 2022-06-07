#ifndef PRINTPROP_H
#define PRINTPROP_H

#include <QString>

enum PrintFormat
{
    PNG,
    BMP,
    JPG
};

struct PrintProp
{
    QString savePath;
    QString saveName;
    PrintFormat format;
    double scale;
    int quality;
    int resolution;
    bool isOpenOutputFolder;

    PrintProp();
};



#endif // PRINTPROP_H
