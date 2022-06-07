#ifndef PLOTPROP_H
#define PLOTPROP_H

#include "axisprop.h"
#include "curveprop.h"
#include "titleprop.h"

struct PlotProp
{
    AxisProp xaxisProp;
    AxisProp yaxisProp;
    QList<CurveProp> curveProps;
    TitleProp titleProp;

    bool showMainAxis=true;
    bool showSubAxis=true;
    bool showTitle=true;
    bool showLegend=true;

    PlotProp();

    PlotProp(const AxisProp& _xaxisProp,const AxisProp& _yaxisProp,
             const QList<CurveProp>& _curveProps,
             const TitleProp& _titleProp);
};

#endif // PLOTPROP_H
