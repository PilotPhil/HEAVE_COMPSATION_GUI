#include "plotelements.h"

PlotElements::PlotElements(QWidget *parent):PlotLayout(parent)
{
    _title=new QCPTextElement(canvas);
}

PlotElements::~PlotElements()
{
}

void PlotElements::showMainAxis(bool flag)
{
    canvas->xAxis->setVisible(flag);
    canvas->yAxis->setVisible(flag);

    canvas->replot();
}

void PlotElements::showSubAxis(bool flag)
{
    canvas->xAxis2->setVisible(flag);
    canvas->yAxis2->setVisible(flag);

    canvas->replot();
}

void PlotElements::setAxis(const AxisProp &axis,const axisPosition& posi)
{
    QCPAxis* selectedAxis=nullptr;
    switch (posi) {
    case axisPosition::atLeft:
        selectedAxis=canvas->yAxis;
        break;

    case axisPosition::atDown:
        selectedAxis=canvas->xAxis;
        break;

    case axisPosition::atRight:
        selectedAxis=canvas->yAxis2;
        break;

    case axisPosition::atTop:
        selectedAxis=canvas->xAxis2;

    default:
        break;
    }

    setAxis(axis,selectedAxis);
}

void PlotElements::setAxis(const AxisProp &axis, QCPAxis *selectedAxis)
{
    if(selectedAxis==nullptr)
        return;

    selectedAxis->setLabel(axis.label);
    selectedAxis->setRange(axis.range.min,axis.range.max);

    canvas->replot();
}

void PlotElements::adjustAxisKeepRatio()
{
    auto width=canvas->width();
    auto heigth=canvas->height();

    double a=1.0;
    double b=1.0;

    canvas->xAxis->setRange(-a*width,a*width);
    canvas->yAxis->setRange(-b*heigth,b*heigth);

    canvas->replot();
}

void PlotElements::adjustAxisFullCanvas()
{
    canvas->rescaleAxes();
    canvas->replot();
}

void PlotElements::showLegend(bool flag)
{
    canvas->legend->setVisible(flag);
    canvas->replot();
}

void PlotElements::removeTitle()
{
    //元素仅一个的时候，是绘图区域，不能移除
    if(canvas->plotLayout()->elementCount()>1)
    {
        canvas->plotLayout()->removeAt(canvas->plotLayout()->rowColToIndex(0, 0));
        canvas->plotLayout()->simplify();
        canvas->replot();
    }
}

void PlotElements::addTitle(const TitleProp &title)
{
    canvas->plotLayout()->insertRow(0);

    _title=new QCPTextElement(canvas);
    _title->setText(title.text);
    _title->setFont(title.font);
    canvas->plotLayout()->addElement(0, 0, _title);
    canvas->replot();
}

void PlotElements::addDefaultTitle()
{
    addTitle();
}

void PlotElements::setTitle(const TitleProp &titleProp)
{
    if(canvas->plotLayout()->elementCount()>1)
    {
        removeTitle();
    }
    addTitle(titleProp);
}

void PlotElements::removeAllGraph()
{
    canvas->clearGraphs();
    canvas->replot();
}

void PlotElements::removeGraph(int graphIndex)
{
    auto g=canvas->graph(graphIndex);

    if(g==nullptr)
        return;

    removeGraph(g);
}

void PlotElements::removeGraph(QCPGraph *graph)
{
    if(graph==nullptr)
        return;

    canvas->removeGraph(graph);
}

void PlotElements::setCurve(QCPGraph* g,const CurveProp &curveProp)
{
    if(g==nullptr)
        return;

    g->setName(curveProp.name);
    g->setPen(curveProp.pen);
    g->setLineStyle(curveProp.lineStyle);
    g->setScatterStyle(curveProp.scatterStyle);

    canvas->replot();
}

void PlotElements::setCurve(const QString &curveName, const CurveProp &curveProp)
{
    for(int i=0;i<canvas->graphCount();i++)
    {
        auto g=canvas->graph(i);

        if(g==nullptr)
            return;

        if(g->name()==curveProp.name)
        {
            setCurve(g,curveProp);
        }
    }
}

void PlotElements::setCurve(int graphIndex, const CurveProp &curveProp)
{
    auto g=canvas->graph(graphIndex);

    if(g==nullptr)
        return;

    setCurve(g,curveProp);
}

void PlotElements::updateCurve(QCPGraph *g, const QVector<double> &xx, const QVector<double> &yy)
{
    g->data().clear();
    g->setData(xx,yy);
    canvas->replot();
    adjustAxisFullCanvas();
}

void PlotElements::updateCurve(int graphIndex, const QVector<double> &xx, const QVector<double> &yy)
{
    auto g=canvas->graph(graphIndex);

    if(g==nullptr)
    {
        return;
    }

    updateCurve(g,xx,yy);
}

void PlotElements::addCurve(const CurveProp &curveProp)
{
    auto g=canvas->addGraph();

    setCurve(g,curveProp);

    g->setData(curveProp.xx,curveProp.yy);
}

void PlotElements::print(const PrintProp& printProp)
{
    auto width=canvas->width();
    auto heigth=canvas->height();
    auto scale=printProp.scale;
    auto quality=printProp.quality;
    auto resl=printProp.resolution;

    auto temPath=printProp.savePath+"/"+printProp.saveName;

    switch (printProp.format) {
    case PrintFormat::BMP:
        canvas->saveBmp(temPath+".bmp",width,heigth,scale,resl);
        break;
    case PrintFormat::JPG:
        canvas->saveJpg(temPath+".jpg",width,heigth,scale,quality,resl);
        break;

    case PrintFormat::PNG:
        canvas->savePng(temPath+".png",width,heigth,scale,quality,resl);
        break;
    default:
        break;
    }

    if(printProp.isOpenOutputFolder==true)
    {
        QDesktopServices::openUrl(QUrl(printProp.savePath, QUrl::TolerantMode));
    }
}
