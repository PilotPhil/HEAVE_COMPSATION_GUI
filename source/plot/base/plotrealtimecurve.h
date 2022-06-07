#ifndef PLOTREALTIMECURVE_H
#define PLOTREALTIMECURVE_H

#include "plotdynamicdraw.h"

class PlotRealtimeCurve : public PlotDynamicDraw
{
public:
    PlotRealtimeCurve(QWidget *parent = nullptr);

    /**
     * @brief makeCurves 制作曲线
     */
    virtual void makeCurves();

    /**
     * @brief makeGraph 制作图层
     */
    virtual void makeGraph();
};

#endif // PLOTREALTIMECURVE_H
