/********************************************************************************
** Form generated from reading UI file 'setprint.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETPRINT_H
#define UI_SETPRINT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_SetPrint
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *label;
    QComboBox *comboBox_outputFormat;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit_outputPath;
    QToolButton *toolButton_selectOutputPath;
    QLabel *label_3;
    QLineEdit *lineEdit_filename;
    QLabel *label_6;
    QDoubleSpinBox *doubleSpinBox_scale;
    QLabel *label_7;
    QSpinBox *spinBox_quality;
    QLabel *label_8;
    QSpinBox *spinBox_resolution;
    QLabel *label_4;
    QCheckBox *checkBox_openOutputDir;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *SetPrint)
    {
        if (SetPrint->objectName().isEmpty())
            SetPrint->setObjectName(QString::fromUtf8("SetPrint"));
        SetPrint->resize(346, 220);
        gridLayout_2 = new QGridLayout(SetPrint);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(SetPrint);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        comboBox_outputFormat = new QComboBox(SetPrint);
        comboBox_outputFormat->addItem(QString());
        comboBox_outputFormat->addItem(QString());
        comboBox_outputFormat->addItem(QString());
        comboBox_outputFormat->setObjectName(QString::fromUtf8("comboBox_outputFormat"));

        gridLayout->addWidget(comboBox_outputFormat, 0, 1, 1, 1);

        label_2 = new QLabel(SetPrint);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lineEdit_outputPath = new QLineEdit(SetPrint);
        lineEdit_outputPath->setObjectName(QString::fromUtf8("lineEdit_outputPath"));

        horizontalLayout->addWidget(lineEdit_outputPath);

        toolButton_selectOutputPath = new QToolButton(SetPrint);
        toolButton_selectOutputPath->setObjectName(QString::fromUtf8("toolButton_selectOutputPath"));

        horizontalLayout->addWidget(toolButton_selectOutputPath);


        gridLayout->addLayout(horizontalLayout, 1, 1, 1, 1);

        label_3 = new QLabel(SetPrint);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        lineEdit_filename = new QLineEdit(SetPrint);
        lineEdit_filename->setObjectName(QString::fromUtf8("lineEdit_filename"));

        gridLayout->addWidget(lineEdit_filename, 2, 1, 1, 1);

        label_6 = new QLabel(SetPrint);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 3, 0, 1, 1);

        doubleSpinBox_scale = new QDoubleSpinBox(SetPrint);
        doubleSpinBox_scale->setObjectName(QString::fromUtf8("doubleSpinBox_scale"));

        gridLayout->addWidget(doubleSpinBox_scale, 3, 1, 1, 1);

        label_7 = new QLabel(SetPrint);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 4, 0, 1, 1);

        spinBox_quality = new QSpinBox(SetPrint);
        spinBox_quality->setObjectName(QString::fromUtf8("spinBox_quality"));
        spinBox_quality->setMinimum(-1);
        spinBox_quality->setMaximum(100);

        gridLayout->addWidget(spinBox_quality, 4, 1, 1, 1);

        label_8 = new QLabel(SetPrint);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 5, 0, 1, 1);

        spinBox_resolution = new QSpinBox(SetPrint);
        spinBox_resolution->setObjectName(QString::fromUtf8("spinBox_resolution"));
        spinBox_resolution->setMinimum(1);
        spinBox_resolution->setMaximum(10000);

        gridLayout->addWidget(spinBox_resolution, 5, 1, 1, 1);

        label_4 = new QLabel(SetPrint);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 6, 0, 1, 1);

        checkBox_openOutputDir = new QCheckBox(SetPrint);
        checkBox_openOutputDir->setObjectName(QString::fromUtf8("checkBox_openOutputDir"));

        gridLayout->addWidget(checkBox_openOutputDir, 6, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(SetPrint);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_2->addWidget(buttonBox, 1, 0, 1, 1);


        retranslateUi(SetPrint);
        QObject::connect(buttonBox, SIGNAL(accepted()), SetPrint, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SetPrint, SLOT(reject()));

        QMetaObject::connectSlotsByName(SetPrint);
    } // setupUi

    void retranslateUi(QDialog *SetPrint)
    {
        SetPrint->setWindowTitle(QApplication::translate("SetPrint", "Dialog", nullptr));
        label->setText(QApplication::translate("SetPrint", "\350\276\223\345\207\272\346\240\274\345\274\217", nullptr));
        comboBox_outputFormat->setItemText(0, QApplication::translate("SetPrint", "PNG", nullptr));
        comboBox_outputFormat->setItemText(1, QApplication::translate("SetPrint", "BMP", nullptr));
        comboBox_outputFormat->setItemText(2, QApplication::translate("SetPrint", "JPG", nullptr));

        label_2->setText(QApplication::translate("SetPrint", "\350\276\223\345\207\272\350\267\257\345\276\204", nullptr));
        toolButton_selectOutputPath->setText(QApplication::translate("SetPrint", "...", nullptr));
        label_3->setText(QApplication::translate("SetPrint", "\346\226\207\344\273\266\345\220\215", nullptr));
        label_6->setText(QApplication::translate("SetPrint", "\347\274\251\346\224\276\346\257\224", nullptr));
        label_7->setText(QApplication::translate("SetPrint", "\350\264\250\351\207\217", nullptr));
        label_8->setText(QApplication::translate("SetPrint", "\345\210\206\350\276\250\347\216\207", nullptr));
        label_4->setText(QApplication::translate("SetPrint", "\346\211\223\345\274\200\350\276\223\345\207\272\346\226\207\344\273\266\345\244\271", nullptr));
        checkBox_openOutputDir->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SetPrint: public Ui_SetPrint {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETPRINT_H
