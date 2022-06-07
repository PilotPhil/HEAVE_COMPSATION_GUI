#ifndef PLOTSTATICDRAW_H
#define PLOTSTATICDRAW_H


#include <QObject>
#include <QMap>

#include "plotinterication.h"

using CurveShowMap = QMap<QString,bool>;

class PlotStaticDraw : public PlotInterication
{
public:
    PlotStaticDraw(QWidget *parent = nullptr);

    virtual ~PlotStaticDraw();

    /**
     * @brief makeCurves 制作曲线
     */
    virtual void makeCurves()=0;

    /**
     * @brief makeGraph 制作图层
     */
    virtual void makeGraph()=0;
};

#endif // PLOTSTATICDRAW_H
