#ifndef SETCURVE_H
#define SETCURVE_H

#include <QDialog>
#include "curveprop.h"

namespace Ui {
class SetCurve;
}

class SetCurve : public QDialog
{
    Q_OBJECT

public:
    explicit SetCurve(const CurveProp& _curveProp,QWidget *parent = nullptr);
    ~SetCurve();

    CurveProp getCurveProp() const { return curveProp; }

    /**
     * @brief setBackgroundColor4Lable 设置QLabel背景颜色
     * @param color
     */
    void setBackgroundColor4Lable(const QColor& color);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::SetCurve *ui;

    CurveProp curveProp;
};

#endif // SETCURVE_H
