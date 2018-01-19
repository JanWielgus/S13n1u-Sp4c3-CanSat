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



void MainWindow::on_CSautoPower_checkBox_clicked()
{
    // Jesli auto sterowanie moca to manualane wylaczone
    if (ui->CSautoPower_checkBox->isChecked())
    {
        ui->CSpowerButtonMode1->setDisabled(true);
        ui->CSpowerButtonMode2->setDisabled(true);
        ui->CSpowerButtonMode3->setDisabled(true);
        ui->CSpowerButtonMode4->setDisabled(true);
    }
    else
    {
        ui->CSpowerButtonMode1->setDisabled(false);
        ui->CSpowerButtonMode2->setDisabled(false);
        ui->CSpowerButtonMode3->setDisabled(false);
        ui->CSpowerButtonMode4->setDisabled(false);
    }
}

void MainWindow::on_GSautoPower_checkBox_clicked()
{
    // Jesli auto sterowanie moca to manualane wylaczone
    if (ui->GSautoPower_checkBox->isChecked())
    {
        ui->GSpowerButtonMode1->setDisabled(true);
        ui->GSpowerButtonMode2->setDisabled(true);
        ui->GSpowerButtonMode3->setDisabled(true);
        ui->GSpowerButtonMode4->setDisabled(true);
    }
    else
    {
        ui->GSpowerButtonMode1->setDisabled(false);
        ui->GSpowerButtonMode2->setDisabled(false);
        ui->GSpowerButtonMode3->setDisabled(false);
        ui->GSpowerButtonMode4->setDisabled(false);
    }
}

void MainWindow::on_chartsShow_pushButton_clicked()
{
    dynCharts = new DynamicChartsWindow;
    dynCharts->show();
}
