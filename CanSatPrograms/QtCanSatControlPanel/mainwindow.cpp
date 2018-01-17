#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::on_autoPower_checkBox_clicked()
{
    if (ui->autoPower_checkBox->isChecked())
    {
        ui->powerButtonMode1->setDisabled(true);
        ui->powerButtonMode2->setDisabled(true);
        ui->powerButtonMode3->setDisabled(true);
        ui->powerButtonMode4->setDisabled(true);
    }
    else
    {
        ui->powerButtonMode1->setDisabled(false);
        ui->powerButtonMode2->setDisabled(false);
        ui->powerButtonMode3->setDisabled(false);
        ui->powerButtonMode4->setDisabled(false);
    }
}
