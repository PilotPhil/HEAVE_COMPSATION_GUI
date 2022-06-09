#include "plotpid.h"

PlotPid::PlotPid(QWidget *parent):
    PlotDynamicDraw(parent)
{
}

void PlotPid::makeCurves()
{

}

void PlotPid::makeGraph()
{
    //1.标题
//    TitleProp t(QString::fromLocal8Bit(""),
//                QFont("Microsoft YaHei",12,QFont::Bold));
//    addTitle(t);

    //2.坐标轴
    AxisProp xAxis(QString::fromLocal8Bit("时间"),
                   RangeProp(0,500));
    setAxis(xAxis,axisPosition::atDown);

    AxisProp yAxis(QString::fromLocal8Bit("速度 [m/s]"),
                   RangeProp(-0.5,0.5));
    setAxis(yAxis,axisPosition::atLeft);

    showMainAxis(true);
    showSubAxis(true);

    canvas->xAxis->setVisible(false);
    canvas->xAxis2->setVisible(false);

    //3.图例
    showLegend(true);

    //4.曲线
    CurveProp curve_actual(QString::fromLocal8Bit("货物速度"),QColor(255, 0, 0));
    curve_actual.scatterStyle=QCPScatterStyle((QCPScatterStyle::ScatterShape)2,1);
    addCurve(curve_actual);

//    CurveProp curve_error(QString::fromLocal8Bit("误差"),QColor(0, 0, 255));
//    curve_error.lineStyle=QCPGraph::LineStyle(1);
    //    addCurve(curve_error);
}

void PlotPid::update(float actual)
{
    auto speed=actual;
    if(speed<1 && speed>-1)
    {
        qDebug()<<"got it......................................................................."<<speed;
    }

    if(canvas->graph(0)==nullptr)
        return;
    static int i=0;
    canvas->graph(0)->addData(i,actual);
    canvas->xAxis->setRange(i,1000,Qt::AlignRight);
    canvas->replot();
    i++;
}
