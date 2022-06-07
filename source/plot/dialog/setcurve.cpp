#include "setcurve.h"
#include "ui_setcurve.h"

SetCurve::SetCurve(const CurveProp& _curveProp,QWidget *parent) :
    curveProp(_curveProp),QDialog(parent),
    ui(new Ui::SetCurve)
{
    ui->setupUi(this);

    ui->lb_color->setAutoFillBackground(true);

    ui->le_curveName->setText(curveProp.name);
    ui->spinBox_width->setValue(curveProp.pen.width());
    ui->cbx_linestyle->setCurrentIndex(curveProp.lineStyle);
    ui->cbx_scatter->setCurrentIndex(curveProp.scatterStyle.shape());
    ui->spinBox_scatterSize->setValue(curveProp.scatterStyle.size());
    setBackgroundColor4Lable(curveProp.pen.color());

    //选择颜色
    connect(ui->pb_setColor,&QToolButton::clicked,this,[&]()
    {
        QColorDialog *m_pColor = new QColorDialog(this);

        auto flag=m_pColor->exec();

        if(flag==QDialog::Accepted)
        {
            curveProp.pen.setColor(m_pColor->selectedColor());
            setBackgroundColor4Lable(m_pColor->selectedColor());
        }
    });

    setWindowTitle(QString::fromLocal8Bit("曲线设置"));
}

SetCurve::~SetCurve()
{
    delete ui;
}

void SetCurve::setBackgroundColor4Lable(const QColor &color)
{
    QPalette palette;
    palette.setColor(QPalette::Background, color);
    ui->lb_color->setPalette(palette);
}

void SetCurve::on_buttonBox_accepted()
{
    curveProp.name=ui->le_curveName->text();
    curveProp.pen=QPen(QBrush(curveProp.pen.color()),ui->spinBox_width->value());
    curveProp.lineStyle=QCPGraph::LineStyle(ui->cbx_linestyle->currentIndex());
    curveProp.scatterStyle=QCPScatterStyle((QCPScatterStyle::ScatterShape)ui->cbx_scatter->currentIndex(),ui->spinBox_scatterSize->value());
}

