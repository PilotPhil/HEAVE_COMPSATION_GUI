#ifndef SETPLOT_H
#define SETPLOT_H

#include <QDialog>
#include "plotprop.h"

namespace Ui {
class setPlot;
}

class setPlot : public QDialog
{
    Q_OBJECT

public:
    explicit setPlot(const PlotProp& _plotProp,QWidget *parent = nullptr);
    ~setPlot();

    /**
     * @brief getPlotProp get
     * @return
     */
    PlotProp getPlotProp() const { return plotProp; }

    void setBackgroundColor4Lable(const QColor &color);

    void mousePressEvent(QMouseEvent *e);

    void saveCurveProp();

    void showCurveProp(int curveIndex);

private slots:
    void on_buttonBox_accepted();

    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::setPlot *ui;

    PlotProp plotProp;
};

#endif // SETPLOT_H
