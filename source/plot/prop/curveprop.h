#ifndef GRAPHPROP_H
#define GRAPHPROP_H

#include <QObject>
#include <QString>
#include <QList>
#include <QPen>
#include <qcustomplot.h>

struct CurveProp
{
    QString name;
    QPen pen;
    QCPGraph::LineStyle lineStyle;
    QCPScatterStyle scatterStyle;

    QVector<double> xx;
    QVector<double> yy;

    CurveProp();

    CurveProp(const QString& _name,const QColor& color);

    CurveProp(const QString& _name,const QPen _pen,
              const QCPGraph::LineStyle& _lineStyle,
              const QCPScatterStyle& _scatterStyle);
};

#endif // GRAPHPROP_H
