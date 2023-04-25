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
        if (ui->lineEdit_inputValor->text().isEmpty())
        {
            throw QString("Valor esta vazio");
        }
        if (ui->lineEdit_inputValor->text().toInt() != ui->lineEdit_inputValor->text().toFloat())
        {
            throw QString("Valor nao eh inteiro");
        }
        QString caracter = ui->lineEdit_inputValor->text();
        for (int i = 0; i < caracter.size(); i++)
        {
            if ((caracter[i] < '0' || caracter[i] > '9') && caracter[i] != '-')
            {
                throw QString("So podem ser inseridos numeros");
            }
        }
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


void MainWindow::on_pushButton_inserirFim_clicked()
{
    try {
        if (ui->lineEdit_inputValor->text().isEmpty())
        {
            throw QString("Valor esta vazio");
        }
        if (ui->lineEdit_inputValor->text().toInt() != ui->lineEdit_inputValor->text().toFloat())
        {
            throw QString("Valor nao eh inteiro");
        }
        QString caracter = ui->lineEdit_inputValor->text();
        for (int i = 0; i < caracter.size(); i++)
        {
            if ((caracter[i] < '0' || caracter[i] > '9') && caracter[i] != '-')
            {
                throw QString("So podem ser inseridos numeros");
            }
        }
        lista.inserirFim(ui->lineEdit_inputValor->text().toInt());
        ui->lineEdit_inputValor->clear();
        ui->textEdit_output->setText(lista.obterDados());
    }catch(QString &erro)
    {
        QMessageBox::critical(this, "Erro ", erro);
    }
}


void MainWindow::on_pushButton_acessarFim_clicked()
{
    try {
        ui->lineEdit_inputValor->setText(QString::number(lista.acessarFim()));
    }catch(QString &erro)
    {
        QMessageBox::critical(this, "Erro ", erro);
    }
}


void MainWindow::on_pushButton_retirarFim_clicked()
{
    try {
        ui->lineEdit_inputValor->setText(QString::number(lista.retirarFim()));
        ui->textEdit_output->setText(lista.obterDados());
    }catch(QString &erro)
    {
        QMessageBox::critical(this, "Erro ", erro);
    }
}


void MainWindow::on_pushButton_inserirPosicao_clicked()
{
    try {
        if (ui->lineEdit_inputValor->text().isEmpty())
        {
            throw QString("Valor esta vazio");
        }
        if (ui->lineEdit_inputValor->text().toInt() != ui->lineEdit_inputValor->text().toFloat())
        {
            throw QString("Valor nao eh inteiro");
        }
        QString caracter = ui->lineEdit_inputValor->text();
        for (int i = 0; i < caracter.size(); i++)
        {
            if ((caracter[i] < '0' || caracter[i] > '9') && caracter[i] != '-')
            {
                throw QString("So podem ser inseridos numeros");
            }
        }

        if (ui->lineEdit_inputPosicao->text().isEmpty())
        {
            throw QString("Posicao esta vazio");
        }
        if (ui->lineEdit_inputPosicao->text().toInt() != ui->lineEdit_inputPosicao->text().toFloat())
        {
            throw QString("Valor posicao nao eh inteiro");
        }
        caracter = ui->lineEdit_inputPosicao->text();
        for (int i = 0; i < caracter.size(); i++)
        {
            if ((caracter[i] < '0' || caracter[i] > '9') && caracter[i] != '-')
            {
                throw QString("So podem ser inseridos numeros");
            }
        }
        lista.inserirPosicao(ui->lineEdit_inputPosicao->text().toInt(), ui->lineEdit_inputValor->text().toInt());
        ui->lineEdit_inputPosicao->clear();
        ui->lineEdit_inputValor->clear();
        ui->textEdit_output->setText(lista.obterDados());
    }catch(QString &erro)
    {
        QMessageBox::critical(this, "Erro ", erro);
    }
}


void MainWindow::on_pushButton_acessarPosicao_clicked()
{
    try {
        ui->lineEdit_inputValor->setText(QString::number(lista.acessarPosicao(ui->lineEdit_inputPosicao->text().toInt())));
        ui->lineEdit_inputPosicao->clear();
    }catch(QString &erro)
    {
        QMessageBox::critical(this, "Erro ", erro);
    }
}


void MainWindow::on_pushButton_retirarPosicao_clicked()
{
    try {
        ui->lineEdit_inputValor->setText(QString::number(lista.retirarPosicao(ui->lineEdit_inputPosicao->text().toInt())));
        ui->lineEdit_inputPosicao->clear();
        ui->textEdit_output->setText(lista.obterDados());
    }catch(QString &erro)
    {
        QMessageBox::critical(this, "Erro ", erro);
    }
}

