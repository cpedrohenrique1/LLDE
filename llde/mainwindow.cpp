#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_inserirInicio_clicked()
{
    try{
        lista.inserirInicio(ui->lineEdit_inputValor->text().toInt());
        ui->lineEdit_inputValor->clear();
        ui->textEdit_output->setText(lista.obterDados());
    }catch(QString &erro)
    {
        QMessageBox::critical(this, "Erro ", erro);
    }
}


void MainWindow::on_pushButton_acessarInicio_clicked()
{
    try{
        ui->lineEdit_inputValor->setText(QString::number(lista.acessarInicio()));
    }catch(QString &erro)
    {
        QMessageBox::critical(this, "Erro ", erro);
    }
}


void MainWindow::on_pushButton_retirarInicio_clicked()
{
    try{
        ui->lineEdit_inputValor->setText(QString::number(lista.retirarInicio()));
        ui->textEdit_output->setText(lista.obterDados());
    }catch(QString &erro)
    {
        QMessageBox::critical(this, "Erro ", erro);
    }
}

