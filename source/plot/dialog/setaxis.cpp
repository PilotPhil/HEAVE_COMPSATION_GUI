#include "setaxis.h"
#include "ui_setaxis.h"

SetAxis::SetAxis(const AxisProp& _axisProp,QWidget *parent) :
    axisProp(_axisProp),QDialog(parent),ui(new Ui::SetAxis)
{
    ui->setupUi(this);

    ui->lineEdit_name->setText(axisProp.label);
    ui->spinBox_min->setValue(axisProp.range.min);
    ui->spinBox_max->setValue(axisProp.range.max);

    setWindowTitle(QString::fromLocal8Bit("坐标轴设置"));
}

SetAxis::~SetAxis()
{
    delete ui;
}

void SetAxis::on_buttonBox_accepted()
{
    axisProp.label=ui->lineEdit_name->text();
    axisProp.range.min=ui->spinBox_min->value();
    axisProp.range.max=ui->spinBox_max->value();
}

