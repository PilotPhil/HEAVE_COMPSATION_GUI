#ifndef SETPRINT_H
#define SETPRINT_H

#include <QDialog>
#include "printprop.h"

namespace Ui {
class SetPrint;
}

class SetPrint : public QDialog
{
    Q_OBJECT

public:
    explicit SetPrint(const PrintProp& _printProp,QWidget *parent = nullptr);
    ~SetPrint();

    PrintProp getPrintProp() const { return printProp; }

private slots:
    void on_buttonBox_accepted();



    void on_toolButton_selectOutputPath_clicked();

private:
    Ui::SetPrint *ui;

    PrintProp printProp;
};

#endif // SETPRINT_H
