#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "comptool.h"
#include <QDebug>
#include <QFileDialog>

#define SAVE_FILE_NAME "Output.txt"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("文本比较"));
    ui->textBrowser->setReadOnly(true);
    ui->textBrowser_2->setReadOnly(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString filename=QFileDialog::getOpenFileName(this,
            tr("Open text File"),"",
            tr("text file (*.txt *.log)"));
    QFile textfile(filename);
    if(textfile.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        QTextStream txtstream(&textfile);
        QString txt = txtstream.readAll();
        ui->textBrowser->setText(txt);
        ui->lineEdit->setText(filename);
    }



}

void MainWindow::on_pushButton_2_clicked()
{
    QString filename=QFileDialog::getOpenFileName(this,
            tr("Open text File"),"",
            tr("text file (*.txt *.log)"));
    QFile textfile(filename);
    if(textfile.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        QTextStream txtstream(&textfile);
        QString txt = txtstream.readAll();
        ui->textBrowser_2->setText(txt);
        ui->lineEdit_2->setText(filename);
    }
}

void MainWindow::on_btn_save_clicked()
{
    QString str1 = ui->textBrowser->toPlainText();
    QString str2 = ui->textBrowser_2->toPlainText();
    CompTool cTool(str1,str2);
    int nMatchLength = cTool.compare();
    int nOffset = cTool.matchOffset();
    if(str1.size() == 0 || str2.size() == 0 || nMatchLength < 0)
    {
        return;
    }
    QString outMsg = tr("当文本1 偏移%1个字节，与文本2可以最大匹配，匹配字符数为%2"
                        ).arg(nOffset).arg(nMatchLength);
    ui->label->setText(outMsg);
    QFile savefile(SAVE_FILE_NAME);
    if(savefile.open(QIODevice::WriteOnly|QIODevice::Text))
    {
        QTextStream stream(&savefile);
        stream << outMsg;
        savefile.close();
    }
}
