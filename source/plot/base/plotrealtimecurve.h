﻿#ifndef PLOTREALTIMECURVE_H
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

    /**
     * @brief updateImuData 更新imu数据到canvas上
     * @param value
     */
    void updateImuData(float value);
};

#endif // PLOTREALTIMECURVE_H
