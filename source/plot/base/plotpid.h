#ifndef PLOTPID_H
#define PLOTPID_H

#include "plotdynamicdraw.h"
#include <QTimer>

class PlotPid : public PlotDynamicDraw
{
public:
    PlotPid(QWidget *parent = nullptr);

    /**
     * @brief makeCurves 制作曲线
     */
    virtual void makeCurves();

    /**
     * @brief makeGraph 制作图层
     */
    virtual void makeGraph();

    /**
     * @brief update 更新曲线
     * @param actual
     */
    void update(float actual);
};

#endif // PLOTPID_H
