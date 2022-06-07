#ifndef AXISPROP_H
#define AXISPROP_H

#include <QString>
#include "rangeprop.h"

struct AxisProp
{
    QString label;
    RangeProp range;

    AxisProp();

    AxisProp(const AxisProp& axisProp);

    AxisProp(const QString& _text,const RangeProp& _range);
};

enum axisPosition
{
    atLeft,
    atDown,
    atRight,
    atTop
};

#endif // AXISPROP_H
