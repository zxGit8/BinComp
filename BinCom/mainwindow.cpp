#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "comptool.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString str1 = ui->plainTextEdit->toPlainText();
    QString str2 = ui->plainTextEdit_2->toPlainText();
    CompTool cTool(str1,str2);
    int nMatchLength = cTool.compare();
    int nOffset = cTool.matchOffset();
    qDebug() << nMatchLength<<"\r\n"<< nOffset;
}

void MainWindow::on_pushButton_2_clicked()
{

}
