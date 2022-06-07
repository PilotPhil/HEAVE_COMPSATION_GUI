#include "curveprop.h"

CurveProp::CurveProp():
    name("new curve"),
    pen(QPen(QBrush(QColor(0,0,0)),1)),
    lineStyle((QCPGraph::LineStyle)1),
    scatterStyle(QCPScatterStyle((QCPScatterStyle::ScatterShape)0,1))
{

}

CurveProp::CurveProp(const QString &_name,const QColor& color):
    name(_name),
    pen(QPen(QBrush(color),1)),
    lineStyle((QCPGraph::LineStyle)1),
    scatterStyle(QCPScatterStyle((QCPScatterStyle::ScatterShape)0,1))
{

}

CurveProp::CurveProp(const QString &_name, const QPen _pen, const QCPGraph::LineStyle &_lineStyle, const QCPScatterStyle &_scatterStyle):
    name(_name),
    pen(_pen),
    lineStyle(_lineStyle),
    scatterStyle(_scatterStyle)
{

}
