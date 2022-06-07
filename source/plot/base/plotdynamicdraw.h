#ifndef PLOTDYNAMICDRAW_H
#define PLOTDYNAMICDRAW_H

#include "plotinterication.h"

class PlotDynamicDraw : public PlotInterication
{
public:
    PlotDynamicDraw(QWidget *parent = nullptr);

    virtual ~PlotDynamicDraw();

    /**
     * @brief makeCurves 制作曲线
     */
    virtual void makeCurves()=0;

    /**
     * @brief makeGraph 制作图层
     */
    virtual void makeGraph()=0;

};

#endif // PLOTDYNAMICDRAW_H
