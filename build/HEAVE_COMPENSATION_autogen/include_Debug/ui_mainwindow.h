/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_7;
    QFrame *frame;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    QSpinBox *spinBox_kp;
    QSpinBox *spinBox_kd;
    QLabel *label_6;
    QLabel *label_5;
    QPushButton *pushButton_savePidCfg;
    QLabel *label_7;
    QCheckBox *checkBox_controlSwitch;
    QSpinBox *spinBox_ki;
    QLabel *label_8;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_2;
    QSpinBox *spinBox_speedValue;
    QSpinBox *spinBox_degree;
    QComboBox *comboBox_motorDegreeFlag;
    QPushButton *pushButton_cmdMotorSpeed;
    QLabel *label_20;
    QLabel *label_23;
    QComboBox *comboBox_motorSpeedFlag;
    QPushButton *pushButton_cmdMotorDegree;
    QLabel *label_24;
    QCheckBox *checkBox_stopMotor;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QCheckBox *checkBox_serialSwitch;
    QComboBox *comboBox_motorBaudrate;
    QLabel *label;
    QLabel *label_9;
    QLabel *label_10;
    QComboBox *comboBox_imuBaudrate;
    QLabel *label_2;
    QComboBox *comboBox_motorPort;
    QLabel *label_11;
    QComboBox *comboBox_imuPort;
    QLabel *label_4;
    QSpacerItem *verticalSpacer_3;
    QFrame *frame_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(920, 695);
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft YaHei UI"));
        font.setPointSize(10);
        MainWindow->setFont(font);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_7 = new QGridLayout(centralwidget);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);

        gridLayout_7->addWidget(frame, 1, 0, 1, 4);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy1);
        groupBox->setMaximumSize(QSize(16777215, 260));
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        spinBox_kp = new QSpinBox(groupBox);
        spinBox_kp->setObjectName(QString::fromUtf8("spinBox_kp"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(spinBox_kp->sizePolicy().hasHeightForWidth());
        spinBox_kp->setSizePolicy(sizePolicy2);
        spinBox_kp->setFrame(true);
        spinBox_kp->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_kp->setProperty("showGroupSeparator", QVariant(true));
        spinBox_kp->setMaximum(1000000000);
        spinBox_kp->setValue(11000);

        gridLayout_3->addWidget(spinBox_kp, 0, 1, 1, 2);

        spinBox_kd = new QSpinBox(groupBox);
        spinBox_kd->setObjectName(QString::fromUtf8("spinBox_kd"));
        sizePolicy2.setHeightForWidth(spinBox_kd->sizePolicy().hasHeightForWidth());
        spinBox_kd->setSizePolicy(sizePolicy2);
        spinBox_kd->setFrame(true);
        spinBox_kd->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_kd->setProperty("showGroupSeparator", QVariant(true));
        spinBox_kd->setMaximum(1000000000);
        spinBox_kd->setValue(3);

        gridLayout_3->addWidget(spinBox_kd, 2, 1, 1, 2);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_3->addWidget(label_6, 1, 0, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_3->addWidget(label_5, 0, 0, 1, 1);

        pushButton_savePidCfg = new QPushButton(groupBox);
        pushButton_savePidCfg->setObjectName(QString::fromUtf8("pushButton_savePidCfg"));

        gridLayout_3->addWidget(pushButton_savePidCfg, 3, 0, 1, 1);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_3->addWidget(label_7, 2, 0, 1, 1);

        checkBox_controlSwitch = new QCheckBox(groupBox);
        checkBox_controlSwitch->setObjectName(QString::fromUtf8("checkBox_controlSwitch"));
        checkBox_controlSwitch->setStyleSheet(QString::fromUtf8("QCheckBox::indicator:unchecked {\n"
"	image: url(:/icons/switch-off.png);\n"
"}\n"
"QCheckBox::indicator:checked {\n"
"	image: url(:/icons/switch-on.png);\n"
"}\n"
""));

        gridLayout_3->addWidget(checkBox_controlSwitch, 4, 1, 1, 1);

        spinBox_ki = new QSpinBox(groupBox);
        spinBox_ki->setObjectName(QString::fromUtf8("spinBox_ki"));
        sizePolicy2.setHeightForWidth(spinBox_ki->sizePolicy().hasHeightForWidth());
        spinBox_ki->setSizePolicy(sizePolicy2);
        spinBox_ki->setFrame(true);
        spinBox_ki->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_ki->setProperty("showGroupSeparator", QVariant(true));
        spinBox_ki->setMaximum(1000000000);
        spinBox_ki->setValue(1);

        gridLayout_3->addWidget(spinBox_ki, 1, 1, 1, 2);

        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_3->addWidget(label_8, 4, 0, 1, 1);


        gridLayout_7->addWidget(groupBox, 0, 2, 1, 1);

        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(groupBox_4->sizePolicy().hasHeightForWidth());
        groupBox_4->setSizePolicy(sizePolicy3);
        groupBox_4->setMaximumSize(QSize(16777215, 260));
        gridLayout_2 = new QGridLayout(groupBox_4);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        spinBox_speedValue = new QSpinBox(groupBox_4);
        spinBox_speedValue->setObjectName(QString::fromUtf8("spinBox_speedValue"));
        sizePolicy2.setHeightForWidth(spinBox_speedValue->sizePolicy().hasHeightForWidth());
        spinBox_speedValue->setSizePolicy(sizePolicy2);
        spinBox_speedValue->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_speedValue->setMaximum(1000000000);
        spinBox_speedValue->setValue(1000);

        gridLayout_2->addWidget(spinBox_speedValue, 1, 1, 1, 2);

        spinBox_degree = new QSpinBox(groupBox_4);
        spinBox_degree->setObjectName(QString::fromUtf8("spinBox_degree"));
        sizePolicy2.setHeightForWidth(spinBox_degree->sizePolicy().hasHeightForWidth());
        spinBox_degree->setSizePolicy(sizePolicy2);
        spinBox_degree->setButtonSymbols(QAbstractSpinBox::NoButtons);
        spinBox_degree->setMinimum(-1000000000);
        spinBox_degree->setMaximum(1000000000);
        spinBox_degree->setValue(1000);

        gridLayout_2->addWidget(spinBox_degree, 3, 1, 1, 2);

        comboBox_motorDegreeFlag = new QComboBox(groupBox_4);
        comboBox_motorDegreeFlag->addItem(QString());
        comboBox_motorDegreeFlag->addItem(QString());
        comboBox_motorDegreeFlag->setObjectName(QString::fromUtf8("comboBox_motorDegreeFlag"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(comboBox_motorDegreeFlag->sizePolicy().hasHeightForWidth());
        comboBox_motorDegreeFlag->setSizePolicy(sizePolicy4);
        comboBox_motorDegreeFlag->setMaximumSize(QSize(35, 16777215));

        gridLayout_2->addWidget(comboBox_motorDegreeFlag, 3, 0, 1, 1);

        pushButton_cmdMotorSpeed = new QPushButton(groupBox_4);
        pushButton_cmdMotorSpeed->setObjectName(QString::fromUtf8("pushButton_cmdMotorSpeed"));

        gridLayout_2->addWidget(pushButton_cmdMotorSpeed, 0, 1, 1, 1);

        label_20 = new QLabel(groupBox_4);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        gridLayout_2->addWidget(label_20, 0, 0, 1, 1);

        label_23 = new QLabel(groupBox_4);
        label_23->setObjectName(QString::fromUtf8("label_23"));

        gridLayout_2->addWidget(label_23, 2, 0, 1, 1);

        comboBox_motorSpeedFlag = new QComboBox(groupBox_4);
        comboBox_motorSpeedFlag->addItem(QString());
        comboBox_motorSpeedFlag->addItem(QString());
        comboBox_motorSpeedFlag->setObjectName(QString::fromUtf8("comboBox_motorSpeedFlag"));
        sizePolicy4.setHeightForWidth(comboBox_motorSpeedFlag->sizePolicy().hasHeightForWidth());
        comboBox_motorSpeedFlag->setSizePolicy(sizePolicy4);
        comboBox_motorSpeedFlag->setMaximumSize(QSize(35, 16777215));

        gridLayout_2->addWidget(comboBox_motorSpeedFlag, 1, 0, 1, 1);

        pushButton_cmdMotorDegree = new QPushButton(groupBox_4);
        pushButton_cmdMotorDegree->setObjectName(QString::fromUtf8("pushButton_cmdMotorDegree"));

        gridLayout_2->addWidget(pushButton_cmdMotorDegree, 2, 1, 1, 1);

        label_24 = new QLabel(groupBox_4);
        label_24->setObjectName(QString::fromUtf8("label_24"));

        gridLayout_2->addWidget(label_24, 4, 0, 1, 1);

        checkBox_stopMotor = new QCheckBox(groupBox_4);
        checkBox_stopMotor->setObjectName(QString::fromUtf8("checkBox_stopMotor"));
        checkBox_stopMotor->setStyleSheet(QString::fromUtf8("QCheckBox::indicator:unchecked {\n"
"	image: url(:/icons/stop-sign.png);\n"
"}\n"
"QCheckBox::indicator:checked {\n"
"	image: url(:/icons/stop-sign.png);\n"
"}\n"
""));

        gridLayout_2->addWidget(checkBox_stopMotor, 4, 1, 1, 1);


        gridLayout_7->addWidget(groupBox_4, 0, 1, 1, 1);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        sizePolicy3.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy3);
        groupBox_2->setMaximumSize(QSize(16777215, 260));
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 4, 0, 1, 1);

        checkBox_serialSwitch = new QCheckBox(groupBox_2);
        checkBox_serialSwitch->setObjectName(QString::fromUtf8("checkBox_serialSwitch"));
        checkBox_serialSwitch->setStyleSheet(QString::fromUtf8("QCheckBox::indicator:unchecked {\n"
"	image: url(:/icons/switch-off.png);\n"
"}\n"
"QCheckBox::indicator:checked {\n"
"	image: url(:/icons/switch-on.png);\n"
"}\n"
""));

        gridLayout->addWidget(checkBox_serialSwitch, 7, 2, 1, 1);

        comboBox_motorBaudrate = new QComboBox(groupBox_2);
        comboBox_motorBaudrate->addItem(QString());
        comboBox_motorBaudrate->addItem(QString());
        comboBox_motorBaudrate->addItem(QString());
        comboBox_motorBaudrate->addItem(QString());
        comboBox_motorBaudrate->addItem(QString());
        comboBox_motorBaudrate->addItem(QString());
        comboBox_motorBaudrate->addItem(QString());
        comboBox_motorBaudrate->addItem(QString());
        comboBox_motorBaudrate->addItem(QString());
        comboBox_motorBaudrate->addItem(QString());
        comboBox_motorBaudrate->addItem(QString());
        comboBox_motorBaudrate->addItem(QString());
        comboBox_motorBaudrate->addItem(QString());
        comboBox_motorBaudrate->addItem(QString());
        comboBox_motorBaudrate->addItem(QString());
        comboBox_motorBaudrate->addItem(QString());
        comboBox_motorBaudrate->addItem(QString());
        comboBox_motorBaudrate->addItem(QString());
        comboBox_motorBaudrate->addItem(QString());
        comboBox_motorBaudrate->setObjectName(QString::fromUtf8("comboBox_motorBaudrate"));

        gridLayout->addWidget(comboBox_motorBaudrate, 2, 2, 1, 1);

        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 7, 0, 1, 2);

        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout->addWidget(label_10, 0, 0, 1, 1);

        comboBox_imuBaudrate = new QComboBox(groupBox_2);
        comboBox_imuBaudrate->addItem(QString());
        comboBox_imuBaudrate->addItem(QString());
        comboBox_imuBaudrate->addItem(QString());
        comboBox_imuBaudrate->addItem(QString());
        comboBox_imuBaudrate->addItem(QString());
        comboBox_imuBaudrate->addItem(QString());
        comboBox_imuBaudrate->addItem(QString());
        comboBox_imuBaudrate->addItem(QString());
        comboBox_imuBaudrate->addItem(QString());
        comboBox_imuBaudrate->addItem(QString());
        comboBox_imuBaudrate->addItem(QString());
        comboBox_imuBaudrate->addItem(QString());
        comboBox_imuBaudrate->addItem(QString());
        comboBox_imuBaudrate->addItem(QString());
        comboBox_imuBaudrate->addItem(QString());
        comboBox_imuBaudrate->addItem(QString());
        comboBox_imuBaudrate->addItem(QString());
        comboBox_imuBaudrate->addItem(QString());
        comboBox_imuBaudrate->addItem(QString());
        comboBox_imuBaudrate->setObjectName(QString::fromUtf8("comboBox_imuBaudrate"));

        gridLayout->addWidget(comboBox_imuBaudrate, 5, 2, 1, 1);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        comboBox_motorPort = new QComboBox(groupBox_2);
        comboBox_motorPort->setObjectName(QString::fromUtf8("comboBox_motorPort"));

        gridLayout->addWidget(comboBox_motorPort, 1, 2, 1, 1);

        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout->addWidget(label_11, 3, 0, 1, 1);

        comboBox_imuPort = new QComboBox(groupBox_2);
        comboBox_imuPort->setObjectName(QString::fromUtf8("comboBox_imuPort"));

        gridLayout->addWidget(comboBox_imuPort, 4, 2, 1, 1);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 5, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 6, 2, 1, 1);


        gridLayout_7->addWidget(groupBox_2, 0, 0, 1, 1);

        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        sizePolicy.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy);
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);

        gridLayout_7->addWidget(frame_2, 0, 3, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 920, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        comboBox_motorBaudrate->setCurrentIndex(11);
        comboBox_imuBaudrate->setCurrentIndex(17);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\345\215\207\346\262\211\350\241\245\345\201\277\346\216\247\345\210\266\351\235\242\346\235\277", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "\350\241\245\345\201\277\346\216\247\345\210\266", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "ki", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "kp", nullptr));
        pushButton_savePidCfg->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230\345\217\202\346\225\260", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "kd", nullptr));
        checkBox_controlSwitch->setText(QString());
        label_8->setText(QApplication::translate("MainWindow", "\345\220\257\347\224\250\346\216\247\345\210\266", nullptr));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "\347\224\265\346\234\272\346\216\247\345\210\266", nullptr));
        comboBox_motorDegreeFlag->setItemText(0, QApplication::translate("MainWindow", "+", nullptr));
        comboBox_motorDegreeFlag->setItemText(1, QApplication::translate("MainWindow", "-", nullptr));

        pushButton_cmdMotorSpeed->setText(QApplication::translate("MainWindow", "\346\211\247\350\241\214", nullptr));
        label_20->setText(QApplication::translate("MainWindow", "\351\200\237\345\272\246", nullptr));
        label_23->setText(QApplication::translate("MainWindow", "\350\247\222\345\272\246", nullptr));
        comboBox_motorSpeedFlag->setItemText(0, QApplication::translate("MainWindow", "+", nullptr));
        comboBox_motorSpeedFlag->setItemText(1, QApplication::translate("MainWindow", "-", nullptr));

        pushButton_cmdMotorDegree->setText(QApplication::translate("MainWindow", "\346\211\247\350\241\214", nullptr));
        label_24->setText(QApplication::translate("MainWindow", "\347\224\265\346\234\272\346\200\245\345\201\234", nullptr));
        checkBox_stopMotor->setText(QString());
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\351\200\232\344\277\241", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\347\253\257   \345\217\243", nullptr));
        checkBox_serialSwitch->setText(QString());
        comboBox_motorBaudrate->setItemText(0, QApplication::translate("MainWindow", "300", nullptr));
        comboBox_motorBaudrate->setItemText(1, QApplication::translate("MainWindow", "600", nullptr));
        comboBox_motorBaudrate->setItemText(2, QApplication::translate("MainWindow", "1200", nullptr));
        comboBox_motorBaudrate->setItemText(3, QApplication::translate("MainWindow", "2400", nullptr));
        comboBox_motorBaudrate->setItemText(4, QApplication::translate("MainWindow", "4800", nullptr));
        comboBox_motorBaudrate->setItemText(5, QApplication::translate("MainWindow", "9600", nullptr));
        comboBox_motorBaudrate->setItemText(6, QApplication::translate("MainWindow", "14400", nullptr));
        comboBox_motorBaudrate->setItemText(7, QApplication::translate("MainWindow", "19200", nullptr));
        comboBox_motorBaudrate->setItemText(8, QApplication::translate("MainWindow", "38400", nullptr));
        comboBox_motorBaudrate->setItemText(9, QApplication::translate("MainWindow", "56000", nullptr));
        comboBox_motorBaudrate->setItemText(10, QApplication::translate("MainWindow", "57600", nullptr));
        comboBox_motorBaudrate->setItemText(11, QApplication::translate("MainWindow", "115200", nullptr));
        comboBox_motorBaudrate->setItemText(12, QApplication::translate("MainWindow", "128000", nullptr));
        comboBox_motorBaudrate->setItemText(13, QApplication::translate("MainWindow", "256000", nullptr));
        comboBox_motorBaudrate->setItemText(14, QApplication::translate("MainWindow", "460800", nullptr));
        comboBox_motorBaudrate->setItemText(15, QApplication::translate("MainWindow", "512000", nullptr));
        comboBox_motorBaudrate->setItemText(16, QApplication::translate("MainWindow", "750000", nullptr));
        comboBox_motorBaudrate->setItemText(17, QApplication::translate("MainWindow", "921600", nullptr));
        comboBox_motorBaudrate->setItemText(18, QApplication::translate("MainWindow", "1500000", nullptr));

        label->setText(QApplication::translate("MainWindow", "\347\253\257   \345\217\243", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "\344\270\262\345\217\243\345\274\200\345\205\263", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "\347\224\265\346\234\272", nullptr));
        comboBox_imuBaudrate->setItemText(0, QApplication::translate("MainWindow", "300", nullptr));
        comboBox_imuBaudrate->setItemText(1, QApplication::translate("MainWindow", "600", nullptr));
        comboBox_imuBaudrate->setItemText(2, QApplication::translate("MainWindow", "1200", nullptr));
        comboBox_imuBaudrate->setItemText(3, QApplication::translate("MainWindow", "2400", nullptr));
        comboBox_imuBaudrate->setItemText(4, QApplication::translate("MainWindow", "4800", nullptr));
        comboBox_imuBaudrate->setItemText(5, QApplication::translate("MainWindow", "9600", nullptr));
        comboBox_imuBaudrate->setItemText(6, QApplication::translate("MainWindow", "14400", nullptr));
        comboBox_imuBaudrate->setItemText(7, QApplication::translate("MainWindow", "19200", nullptr));
        comboBox_imuBaudrate->setItemText(8, QApplication::translate("MainWindow", "38400", nullptr));
        comboBox_imuBaudrate->setItemText(9, QApplication::translate("MainWindow", "56000", nullptr));
        comboBox_imuBaudrate->setItemText(10, QApplication::translate("MainWindow", "57600", nullptr));
        comboBox_imuBaudrate->setItemText(11, QApplication::translate("MainWindow", "115200", nullptr));
        comboBox_imuBaudrate->setItemText(12, QApplication::translate("MainWindow", "128000", nullptr));
        comboBox_imuBaudrate->setItemText(13, QApplication::translate("MainWindow", "256000", nullptr));
        comboBox_imuBaudrate->setItemText(14, QApplication::translate("MainWindow", "460800", nullptr));
        comboBox_imuBaudrate->setItemText(15, QApplication::translate("MainWindow", "512000", nullptr));
        comboBox_imuBaudrate->setItemText(16, QApplication::translate("MainWindow", "750000", nullptr));
        comboBox_imuBaudrate->setItemText(17, QApplication::translate("MainWindow", "921600", nullptr));
        comboBox_imuBaudrate->setItemText(18, QApplication::translate("MainWindow", "1500000", nullptr));

        label_2->setText(QApplication::translate("MainWindow", "\346\263\242\347\211\271\347\216\207", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "IMU", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\346\263\242\347\211\271\347\216\207", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
