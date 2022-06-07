#include "setprint.h"
#include "ui_setprint.h"

#include <QDateTime>
#include <QFileDialog>

SetPrint::SetPrint(const PrintProp& _printProp,QWidget *parent) :
    printProp(_printProp),QDialog(parent),
    ui(new Ui::SetPrint)
{
    ui->setupUi(this);

    ui->doubleSpinBox_scale->setValue(printProp.scale);
    ui->spinBox_quality->setValue(printProp.quality);
    ui->spinBox_resolution->setValue(printProp.resolution);

    QDateTime dateTime(QDateTime::currentDateTime());
    QString qStr = dateTime.toString("yy-MM-dd-hh-mm-ss");
    ui->lineEdit_filename->setText("plot-"+qStr);
    printProp.saveName=ui->lineEdit_filename->text();
    ui->lineEdit_outputPath->setText("C:/Users/Public/Pictures");
    ui->comboBox_outputFormat->setCurrentIndex(printProp.format);
    ui->checkBox_openOutputDir->setChecked(printProp.isOpenOutputFolder);

    setWindowTitle(QString::fromLocal8Bit("打印设置"));
}

SetPrint::~SetPrint()
{
    delete ui;
}

void SetPrint::on_buttonBox_accepted()
{
    printProp.savePath=ui->lineEdit_outputPath->text();
    printProp.saveName=ui->lineEdit_filename->text();
    printProp.format=(PrintFormat)ui->comboBox_outputFormat->currentIndex();
    printProp.scale=ui->doubleSpinBox_scale->value();
    printProp.quality=ui->spinBox_quality->value();
    printProp.resolution=ui->spinBox_resolution->value();
    printProp.isOpenOutputFolder=ui->checkBox_openOutputDir->isChecked();
}


void SetPrint::on_toolButton_selectOutputPath_clicked()
{
    //选择路径
    auto default_path=R"(C:\Users\dwb\Desktop)";
    auto dir=QFileDialog::getExistingDirectory(this,QString::fromLocal8Bit("选择输出文件夹"),
                                 QString::fromStdString(default_path));
    ui->lineEdit_outputPath->setText(dir);
}

