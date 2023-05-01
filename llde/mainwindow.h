#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "llde.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_inserirInicio_clicked();

    void on_pushButton_acessarInicio_clicked();

    void on_pushButton_retirarInicio_clicked();

    void on_pushButton_inserirFim_clicked();

    void on_pushButton_acessarFim_clicked();

    void on_pushButton_retirarFim_clicked();

    void on_pushButton_inserirPosicao_clicked();

    void on_pushButton_acessarPosicao_clicked();

    void on_pushButton_retirarPosicao_clicked();

    void on_pushButton_inserirOrdenado_clicked();

private:
    Ui::MainWindow *ui;
    Pedro::llde lista;
};
#endif // MAINWINDOW_H
