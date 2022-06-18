/********************************************************************************
** Form generated from reading UI file 'plotlayout.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLOTLAYOUT_H
#define UI_PLOTLAYOUT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PlotLayout
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_moveCanvas;
    QPushButton *btn_property;
    QPushButton *btn_fullView;
    QPushButton *btn_ratioView;
    QPushButton *btn_print;
    QSpacerItem *horizontalSpacer;
    QWidget *widget_canvas;

    void setupUi(QWidget *PlotLayout)
    {
        if (PlotLayout->objectName().isEmpty())
            PlotLayout->setObjectName(QString::fromUtf8("PlotLayout"));
        PlotLayout->resize(551, 438);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/res/plot_icos/spline-chart.png"), QSize(), QIcon::Normal, QIcon::Off);
        PlotLayout->setWindowIcon(icon);
        PlotLayout->setStyleSheet(QString::fromUtf8("#PlotLayout\n"
"{\n"
"	\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));
        gridLayout = new QGridLayout(PlotLayout);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(6);
        gridLayout->setVerticalSpacing(0);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btn_moveCanvas = new QPushButton(PlotLayout);
        btn_moveCanvas->setObjectName(QString::fromUtf8("btn_moveCanvas"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/move.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_moveCanvas->setIcon(icon1);
        btn_moveCanvas->setIconSize(QSize(20, 20));
        btn_moveCanvas->setCheckable(true);
        btn_moveCanvas->setChecked(false);

        horizontalLayout->addWidget(btn_moveCanvas);

        btn_property = new QPushButton(PlotLayout);
        btn_property->setObjectName(QString::fromUtf8("btn_property"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icons/control.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_property->setIcon(icon2);
        btn_property->setIconSize(QSize(20, 20));

        horizontalLayout->addWidget(btn_property);

        btn_fullView = new QPushButton(PlotLayout);
        btn_fullView->setObjectName(QString::fromUtf8("btn_fullView"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icons/full-screen.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_fullView->setIcon(icon3);
        btn_fullView->setIconSize(QSize(20, 20));

        horizontalLayout->addWidget(btn_fullView);

        btn_ratioView = new QPushButton(PlotLayout);
        btn_ratioView->setObjectName(QString::fromUtf8("btn_ratioView"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icons/golden-ratio.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_ratioView->setIcon(icon4);
        btn_ratioView->setIconSize(QSize(20, 20));

        horizontalLayout->addWidget(btn_ratioView);

        btn_print = new QPushButton(PlotLayout);
        btn_print->setObjectName(QString::fromUtf8("btn_print"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icons/printer.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_print->setIcon(icon5);
        btn_print->setIconSize(QSize(20, 20));

        horizontalLayout->addWidget(btn_print);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        widget_canvas = new QWidget(PlotLayout);
        widget_canvas->setObjectName(QString::fromUtf8("widget_canvas"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget_canvas->sizePolicy().hasHeightForWidth());
        widget_canvas->setSizePolicy(sizePolicy);

        gridLayout->addWidget(widget_canvas, 1, 0, 1, 1);


        retranslateUi(PlotLayout);

        QMetaObject::connectSlotsByName(PlotLayout);
    } // setupUi

    void retranslateUi(QWidget *PlotLayout)
    {
        PlotLayout->setWindowTitle(QApplication::translate("PlotLayout", "\347\273\230\345\233\276", nullptr));
#ifndef QT_NO_TOOLTIP
        btn_moveCanvas->setToolTip(QApplication::translate("PlotLayout", "\347\247\273\345\212\250\347\224\273\345\270\203", nullptr));
#endif // QT_NO_TOOLTIP
        btn_moveCanvas->setText(QString());
#ifndef QT_NO_TOOLTIP
        btn_property->setToolTip(QApplication::translate("PlotLayout", "\345\261\236\346\200\247\350\256\276\347\275\256", nullptr));
#endif // QT_NO_TOOLTIP
        btn_property->setText(QString());
#ifndef QT_NO_TOOLTIP
        btn_fullView->setToolTip(QApplication::translate("PlotLayout", "\351\223\272\346\273\241\350\247\206\345\233\276", nullptr));
#endif // QT_NO_TOOLTIP
        btn_fullView->setText(QString());
#ifndef QT_NO_TOOLTIP
        btn_ratioView->setToolTip(QApplication::translate("PlotLayout", "\347\255\211\346\257\224\350\247\206\345\233\276", nullptr));
#endif // QT_NO_TOOLTIP
        btn_ratioView->setText(QString());
#ifndef QT_NO_TOOLTIP
        btn_print->setToolTip(QApplication::translate("PlotLayout", "\346\211\223\345\215\260\350\276\223\345\207\272", nullptr));
#endif // QT_NO_TOOLTIP
        btn_print->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class PlotLayout: public Ui_PlotLayout {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLOTLAYOUT_H
