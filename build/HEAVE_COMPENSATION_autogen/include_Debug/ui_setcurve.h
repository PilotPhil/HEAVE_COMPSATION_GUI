/********************************************************************************
** Form generated from reading UI file 'setcurve.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETCURVE_H
#define UI_SETCURVE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_SetCurve
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *label_6;
    QLineEdit *le_curveName;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout;
    QLabel *lb_color;
    QToolButton *pb_setColor;
    QLabel *label_5;
    QSpinBox *spinBox_width;
    QLabel *label_2;
    QComboBox *cbx_linestyle;
    QLabel *label_4;
    QComboBox *cbx_scatter;
    QLabel *label_7;
    QSpinBox *spinBox_scatterSize;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *SetCurve)
    {
        if (SetCurve->objectName().isEmpty())
            SetCurve->setObjectName(QString::fromUtf8("SetCurve"));
        SetCurve->resize(213, 207);
        gridLayout_2 = new QGridLayout(SetCurve);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_6 = new QLabel(SetCurve);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        QFont font;
        font.setFamily(QString::fromUtf8("DejaVu Sans Mono"));
        font.setPointSize(12);
        label_6->setFont(font);

        gridLayout->addWidget(label_6, 0, 0, 1, 1);

        le_curveName = new QLineEdit(SetCurve);
        le_curveName->setObjectName(QString::fromUtf8("le_curveName"));

        gridLayout->addWidget(le_curveName, 0, 1, 1, 1);

        label_3 = new QLabel(SetCurve);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lb_color = new QLabel(SetCurve);
        lb_color->setObjectName(QString::fromUtf8("lb_color"));
        lb_color->setFont(font);
        lb_color->setAutoFillBackground(true);

        horizontalLayout->addWidget(lb_color);

        pb_setColor = new QToolButton(SetCurve);
        pb_setColor->setObjectName(QString::fromUtf8("pb_setColor"));

        horizontalLayout->addWidget(pb_setColor);


        gridLayout->addLayout(horizontalLayout, 1, 1, 1, 1);

        label_5 = new QLabel(SetCurve);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        gridLayout->addWidget(label_5, 2, 0, 1, 1);

        spinBox_width = new QSpinBox(SetCurve);
        spinBox_width->setObjectName(QString::fromUtf8("spinBox_width"));
        spinBox_width->setFont(font);
        spinBox_width->setValue(1);

        gridLayout->addWidget(spinBox_width, 2, 1, 1, 1);

        label_2 = new QLabel(SetCurve);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 3, 0, 1, 1);

        cbx_linestyle = new QComboBox(SetCurve);
        cbx_linestyle->addItem(QString());
        cbx_linestyle->addItem(QString());
        cbx_linestyle->addItem(QString());
        cbx_linestyle->addItem(QString());
        cbx_linestyle->addItem(QString());
        cbx_linestyle->addItem(QString());
        cbx_linestyle->setObjectName(QString::fromUtf8("cbx_linestyle"));
        cbx_linestyle->setFont(font);

        gridLayout->addWidget(cbx_linestyle, 3, 1, 1, 1);

        label_4 = new QLabel(SetCurve);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        gridLayout->addWidget(label_4, 4, 0, 1, 1);

        cbx_scatter = new QComboBox(SetCurve);
        cbx_scatter->addItem(QString());
        cbx_scatter->addItem(QString());
        cbx_scatter->addItem(QString());
        cbx_scatter->addItem(QString());
        cbx_scatter->addItem(QString());
        cbx_scatter->addItem(QString());
        cbx_scatter->addItem(QString());
        cbx_scatter->addItem(QString());
        cbx_scatter->addItem(QString());
        cbx_scatter->addItem(QString());
        cbx_scatter->addItem(QString());
        cbx_scatter->addItem(QString());
        cbx_scatter->addItem(QString());
        cbx_scatter->addItem(QString());
        cbx_scatter->addItem(QString());
        cbx_scatter->addItem(QString());
        cbx_scatter->setObjectName(QString::fromUtf8("cbx_scatter"));
        cbx_scatter->setFont(font);

        gridLayout->addWidget(cbx_scatter, 4, 1, 1, 1);

        label_7 = new QLabel(SetCurve);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font);

        gridLayout->addWidget(label_7, 5, 0, 1, 1);

        spinBox_scatterSize = new QSpinBox(SetCurve);
        spinBox_scatterSize->setObjectName(QString::fromUtf8("spinBox_scatterSize"));
        spinBox_scatterSize->setFont(font);
        spinBox_scatterSize->setValue(1);

        gridLayout->addWidget(spinBox_scatterSize, 5, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(SetCurve);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_2->addWidget(buttonBox, 1, 0, 1, 1);


        retranslateUi(SetCurve);
        QObject::connect(buttonBox, SIGNAL(accepted()), SetCurve, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SetCurve, SLOT(reject()));

        QMetaObject::connectSlotsByName(SetCurve);
    } // setupUi

    void retranslateUi(QDialog *SetCurve)
    {
        SetCurve->setWindowTitle(QApplication::translate("SetCurve", "Dialog", nullptr));
        label_6->setText(QApplication::translate("SetCurve", "\345\220\215\347\247\260", nullptr));
        label_3->setText(QApplication::translate("SetCurve", "\351\242\234\350\211\262", nullptr));
        lb_color->setText(QString());
        pb_setColor->setText(QApplication::translate("SetCurve", "...", nullptr));
        label_5->setText(QApplication::translate("SetCurve", "\347\272\277\345\256\275", nullptr));
        label_2->setText(QApplication::translate("SetCurve", "\347\272\277\345\236\213", nullptr));
        cbx_linestyle->setItemText(0, QApplication::translate("SetCurve", "None", nullptr));
        cbx_linestyle->setItemText(1, QApplication::translate("SetCurve", "Line", nullptr));
        cbx_linestyle->setItemText(2, QApplication::translate("SetCurve", "StepLeft", nullptr));
        cbx_linestyle->setItemText(3, QApplication::translate("SetCurve", "StepRight", nullptr));
        cbx_linestyle->setItemText(4, QApplication::translate("SetCurve", "StepCenter", nullptr));
        cbx_linestyle->setItemText(5, QApplication::translate("SetCurve", "Impulse", nullptr));

        label_4->setText(QApplication::translate("SetCurve", "\347\202\271\345\236\213", nullptr));
        cbx_scatter->setItemText(0, QApplication::translate("SetCurve", "None", nullptr));
        cbx_scatter->setItemText(1, QApplication::translate("SetCurve", "Dot", nullptr));
        cbx_scatter->setItemText(2, QApplication::translate("SetCurve", "Cross", nullptr));
        cbx_scatter->setItemText(3, QApplication::translate("SetCurve", "Plus", nullptr));
        cbx_scatter->setItemText(4, QApplication::translate("SetCurve", "Circle", nullptr));
        cbx_scatter->setItemText(5, QApplication::translate("SetCurve", "Disc", nullptr));
        cbx_scatter->setItemText(6, QApplication::translate("SetCurve", "Square", nullptr));
        cbx_scatter->setItemText(7, QApplication::translate("SetCurve", "Diamond", nullptr));
        cbx_scatter->setItemText(8, QApplication::translate("SetCurve", "Star", nullptr));
        cbx_scatter->setItemText(9, QApplication::translate("SetCurve", "Triangle", nullptr));
        cbx_scatter->setItemText(10, QApplication::translate("SetCurve", "TriangleInverted", nullptr));
        cbx_scatter->setItemText(11, QApplication::translate("SetCurve", "CrossSquare", nullptr));
        cbx_scatter->setItemText(12, QApplication::translate("SetCurve", "PlusSquare", nullptr));
        cbx_scatter->setItemText(13, QApplication::translate("SetCurve", "CrossCircle", nullptr));
        cbx_scatter->setItemText(14, QApplication::translate("SetCurve", "PlusCircle", nullptr));
        cbx_scatter->setItemText(15, QApplication::translate("SetCurve", "Peace", nullptr));

        label_7->setText(QApplication::translate("SetCurve", "\345\244\247\345\260\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SetCurve: public Ui_SetCurve {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETCURVE_H
