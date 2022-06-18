/********************************************************************************
** Form generated from reading UI file 'setaxis.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETAXIS_H
#define UI_SETAXIS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_SetAxis
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEdit_name;
    QLabel *label_2;
    QSpinBox *spinBox_min;
    QLabel *label_3;
    QSpinBox *spinBox_max;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *SetAxis)
    {
        if (SetAxis->objectName().isEmpty())
            SetAxis->setObjectName(QString::fromUtf8("SetAxis"));
        SetAxis->resize(174, 119);
        gridLayout = new QGridLayout(SetAxis);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(SetAxis);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit_name = new QLineEdit(SetAxis);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));

        gridLayout->addWidget(lineEdit_name, 0, 1, 1, 1);

        label_2 = new QLabel(SetAxis);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        spinBox_min = new QSpinBox(SetAxis);
        spinBox_min->setObjectName(QString::fromUtf8("spinBox_min"));
        spinBox_min->setMinimum(-100000000);
        spinBox_min->setMaximum(100000000);

        gridLayout->addWidget(spinBox_min, 1, 1, 1, 1);

        label_3 = new QLabel(SetAxis);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        spinBox_max = new QSpinBox(SetAxis);
        spinBox_max->setObjectName(QString::fromUtf8("spinBox_max"));
        spinBox_max->setMinimum(-100000000);
        spinBox_max->setMaximum(100000000);

        gridLayout->addWidget(spinBox_max, 2, 1, 1, 1);

        buttonBox = new QDialogButtonBox(SetAxis);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 3, 0, 1, 2);


        retranslateUi(SetAxis);
        QObject::connect(buttonBox, SIGNAL(accepted()), SetAxis, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SetAxis, SLOT(reject()));

        QMetaObject::connectSlotsByName(SetAxis);
    } // setupUi

    void retranslateUi(QDialog *SetAxis)
    {
        SetAxis->setWindowTitle(QApplication::translate("SetAxis", "Dialog", nullptr));
        label->setText(QApplication::translate("SetAxis", "\345\235\220\346\240\207\350\275\264\345\220\215", nullptr));
        label_2->setText(QApplication::translate("SetAxis", "\346\234\200\345\260\217\345\200\274", nullptr));
        label_3->setText(QApplication::translate("SetAxis", "\346\234\200\345\244\247\345\200\274", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SetAxis: public Ui_SetAxis {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETAXIS_H
