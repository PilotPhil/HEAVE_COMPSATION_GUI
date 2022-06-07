#ifndef PLOTLAYOUT_H
#define PLOTLAYOUT_H

#include <QWidget>
#include "qcustomplot.h"

namespace Ui {
class PlotLayout;
}

class PlotLayout : public QWidget
{
    Q_OBJECT

public:
    explicit PlotLayout(QWidget *parent = nullptr);
    virtual ~PlotLayout();

protected:
    virtual void btn_moveCanvas_clicked(bool isChecked)=0;

    virtual void btn_property_clicked()=0;

    virtual void btn_fullView_clicked()=0;

    virtual void btn_ratioView_clicked()=0;

    virtual void btn_print_clicked()=0;

private slots:
    void on_btn_moveCanvas_clicked();

    void on_btn_property_clicked();

    void on_btn_fullView_clicked();

    void on_btn_ratioView_clicked();

    void on_btn_print_clicked();

private:
    Ui::PlotLayout *ui;

protected:
    QCustomPlot* canvas;
};

#endif // PLOTLAYOUT_H
