#ifndef SETAXIS_H
#define SETAXIS_H

#include <QDialog>

#include "axisprop.h"

namespace Ui {
class SetAxis;
}

class SetAxis : public QDialog
{
    Q_OBJECT

public:
    explicit SetAxis(const AxisProp& _axisProp,QWidget *parent = nullptr);
    ~SetAxis();

    AxisProp getAxisProp() const { return axisProp; }

private slots:
    void on_buttonBox_accepted();

private:
    Ui::SetAxis *ui;

    AxisProp axisProp;
};

#endif // SETAXIS_H
