#ifndef POINT_H
#define POINT_H

#include <QObject>

struct Point
{
    double x=0;
    double y=0;

    Point():x(0),y(0)
    {

    }

    Point(double _x,double _y):x(_x),y(_y)
    {

    }
};

#endif // POINT_H
