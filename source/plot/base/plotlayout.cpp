#include "plotlayout.h"
#include "ui_plotlayout.h"

#include <QGridLayout>

PlotLayout::PlotLayout(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PlotLayout)
{
    ui->setupUi(this);

    //为绘图区域canvas设置布局
    canvas=new QCustomPlot(this);
    QGridLayout* gl1=new QGridLayout(this);
    gl1->setMargin(0);
    gl1->addWidget(canvas);
    ui->widget_canvas->setLayout(gl1);
}

PlotLayout::~PlotLayout()
{
   delete ui;
}


void PlotLayout::on_btn_moveCanvas_clicked()
{
    btn_moveCanvas_clicked(ui->btn_moveCanvas->isChecked());
}


void PlotLayout::on_btn_property_clicked()
{
    btn_property_clicked();
}


void PlotLayout::on_btn_fullView_clicked()
{
    btn_fullView_clicked();
}


void PlotLayout::on_btn_ratioView_clicked()
{
    btn_ratioView_clicked();
}


void PlotLayout::on_btn_print_clicked()
{
    btn_print_clicked();
}

