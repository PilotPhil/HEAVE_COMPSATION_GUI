#include "plotrealtimecurve.h"

PlotRealtimeCurve::PlotRealtimeCurve(QWidget *parent):
    PlotDynamicDraw(parent)
{
    timer=new QTimer(this);
    timer->setInterval(20);
    connect(timer,&QTimer::timeout,this,&PlotRealtimeCurve::update);
    timer->start();
}

void PlotRealtimeCurve::makeCurves()
{
}


void PlotRealtimeCurve::makeGraph()
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
                   RangeProp(-0.75,0.75));
    setAxis(yAxis,axisPosition::atLeft);

    showMainAxis(true);
    showSubAxis(true);

    canvas->xAxis->setVisible(false);
    canvas->xAxis2->setVisible(false);

    //3.图例
    showLegend(true);

    //4.曲线
    CurveProp curve_imu("IMU",QColor(255, 0, 0));
//    curve_imu.scatterStyle=QCPScatterStyle((QCPScatterStyle::ScatterShape)2,1);
    addCurve(curve_imu);

    CurveProp curve_motor("Motor",QColor(0, 0, 255));
    curve_motor.lineStyle=QCPGraph::LineStyle(1);
//    curve_motor.scatterStyle=QCPScatterStyle((QCPScatterStyle::ScatterShape)2,1);
    addCurve(curve_motor);
}

void PlotRealtimeCurve::updateImuData(float value)
{
    imu_vel=value;
}

void PlotRealtimeCurve::updateMotorData(float value)
{
    motor_vel=value;
}

void PlotRealtimeCurve::update()
{
    if(canvas->graph(0)==nullptr || canvas->graph(1)==nullptr)
        return;

    static int i=0;
    canvas->graph(0)->addData(i,-1*imu_vel);
    canvas->graph(1)->addData(i,motor_vel);
    canvas->xAxis->setRange(i,1000,Qt::AlignRight);
    canvas->replot();
    i++;
}
