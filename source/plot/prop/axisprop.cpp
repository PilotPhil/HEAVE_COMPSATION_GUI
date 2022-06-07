#include "axisprop.h"

AxisProp::AxisProp()
    :label(""),range(RangeProp())
{

}

AxisProp::AxisProp(const AxisProp &axisProp)
{
    label=axisProp.label;
    range=axisProp.range;
}

AxisProp::AxisProp(const QString &_text, const RangeProp &_range)
    :label(_text),range(_range)
{

}
