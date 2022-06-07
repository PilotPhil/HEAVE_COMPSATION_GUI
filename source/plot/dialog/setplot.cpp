#include "setplot.h"
#include "ui_setplot.h"

setPlot::setPlot(const PlotProp& _plotProp,QWidget *parent) :
    plotProp(_plotProp),QDialog(parent),
    ui(new Ui::setPlot)
{
    ui->setupUi(this);

    setFocusPolicy(Qt::StrongFocus);

    //title
    ui->le_titleLabel->setText(plotProp.titleProp.text);
    ui->fontComboBox_titleFont->setCurrentFont(plotProp.titleProp.font);
    ui->spinBox_titleFontSize->setValue(plotProp.titleProp.font.pointSize());
    ui->checkBox_showTitle->setChecked(plotProp.showTitle);

    //axis
    ui->checkBox_showMainAxis->setChecked(plotProp.showMainAxis);
    ui->checkBox_showSubAxis->setChecked(plotProp.showSubAxis);
    //xaxis
    ui->lineEdit_xaxisName->setText(plotProp.xaxisProp.label);
    ui->spinBox_xaxisMin->setValue(plotProp.xaxisProp.range.min);
    ui->spinBox_xaxisMax->setValue(plotProp.xaxisProp.range.max);
    //yaxis
    ui->lineEdit_yaxisName->setText(plotProp.yaxisProp.label);
    ui->spinBox_yaxisMin->setValue(plotProp.yaxisProp.range.min);
    ui->spinBox_yaxisMax->setValue(plotProp.yaxisProp.range.max);

    for(auto t:plotProp.curveProps)
    {
        ui->comboBox->addItem(t.name);
    }

    ui->lb_color->setAutoFillBackground(true);

    if(plotProp.curveProps.length()>1)
    {
        ui->le_curveName->setText(plotProp.curveProps[0].name);
        ui->spinBox_width->setValue(plotProp.curveProps[0].pen.width());
        ui->cbx_linestyle->setCurrentIndex(plotProp.curveProps[0].lineStyle);
        ui->cbx_scatter->setCurrentIndex(plotProp.curveProps[0].scatterStyle.shape());
        ui->spinBox_scatterSize->setValue(plotProp.curveProps[0].scatterStyle.size());
        setBackgroundColor4Lable(plotProp.curveProps[0].pen.color());
    }

    connect(ui->le_curveName,&QLineEdit::textChanged,this,&setPlot::saveCurveProp);
    connect(ui->spinBox_width, QOverload<int>::of(&QSpinBox::valueChanged),this,&setPlot::saveCurveProp);
    connect(ui->cbx_linestyle,QOverload<int>::of(&QComboBox::currentIndexChanged),this,&setPlot::saveCurveProp);
    connect(ui->cbx_scatter,QOverload<int>::of(&QComboBox::currentIndexChanged),this,&setPlot::saveCurveProp);
    connect(ui->spinBox_scatterSize,QOverload<int>::of(&QSpinBox::valueChanged),this,&setPlot::saveCurveProp);
}

setPlot::~setPlot()
{
    delete ui;
}

void setPlot::setBackgroundColor4Lable(const QColor &color)
{
    QPalette palette;
    palette.setColor(QPalette::Background, color);
    ui->lb_color->setPalette(palette);
}

void setPlot::mousePressEvent(QMouseEvent *e)
{
    qDebug()<<"123";

    if (QComboBox *cbx = qobject_cast<QComboBox*>(sender()))
    {
        qDebug()<<"clicked";
    }
}

void setPlot::saveCurveProp()
{
    int curveIndex=ui->comboBox->currentIndex();

    plotProp.curveProps[curveIndex].name=ui->le_curveName->text();
    plotProp.curveProps[curveIndex].pen=QPen(QBrush(plotProp.curveProps[curveIndex].pen.color()),ui->spinBox_width->value());
    plotProp.curveProps[curveIndex].lineStyle=QCPGraph::LineStyle(ui->cbx_linestyle->currentIndex());
    plotProp.curveProps[curveIndex].scatterStyle=QCPScatterStyle((QCPScatterStyle::ScatterShape)ui->cbx_scatter->currentIndex(),ui->spinBox_scatterSize->value());
}

void setPlot::showCurveProp(int curveIndex)
{
    if(curveIndex>plotProp.curveProps.length())
        return;

    ui->le_curveName->setText(plotProp.curveProps[curveIndex].name);
    ui->spinBox_width->setValue(plotProp.curveProps[curveIndex].pen.width());
    ui->cbx_linestyle->setCurrentIndex(plotProp.curveProps[curveIndex].lineStyle);
    ui->cbx_scatter->setCurrentIndex(plotProp.curveProps[curveIndex].scatterStyle.shape());
    ui->spinBox_scatterSize->setValue(plotProp.curveProps[curveIndex].scatterStyle.size());
    setBackgroundColor4Lable(plotProp.curveProps[curveIndex].pen.color());
}

void setPlot::on_buttonBox_accepted()
{
    //title
    plotProp.titleProp.text=ui->le_titleLabel->text();
    plotProp.titleProp.font=ui->fontComboBox_titleFont->font();
    plotProp.titleProp.font.setPointSize(ui->spinBox_titleFontSize->value());

    //axis
    plotProp.showMainAxis=ui->checkBox_showMainAxis->isChecked();
    plotProp.showSubAxis=ui->checkBox_showSubAxis->isChecked();
    //xaxis
    plotProp.xaxisProp.label=ui->lineEdit_xaxisName->text();
    plotProp.xaxisProp.range.min=ui->spinBox_xaxisMin->value();
    plotProp.xaxisProp.range.max=ui->spinBox_xaxisMax->value();
    //yaxis
    plotProp.yaxisProp.label=ui->lineEdit_yaxisName->text();
    plotProp.yaxisProp.range.min=ui->spinBox_yaxisMin->value();
    plotProp.yaxisProp.range.max=ui->spinBox_yaxisMax->value();

//    auto curveIndex=ui->comboBox->currentIndex();
//    plotProp.curveProps[curveIndex].name=ui->le_curveName->text();
//    plotProp.curveProps[curveIndex].pen=QPen(QBrush(plotProp.curveProps[curveIndex].pen.color()),ui->spinBox_width->value());
//    plotProp.curveProps[curveIndex].lineStyle=QCPGraph::LineStyle(ui->cbx_linestyle->currentIndex());
//    plotProp.curveProps[curveIndex].scatterStyle=QCPScatterStyle((QCPScatterStyle::ScatterShape)ui->cbx_scatter->currentIndex(),ui->spinBox_scatterSize->value());
}


void setPlot::on_comboBox_currentIndexChanged(int index)
{
    showCurveProp(index);
}

