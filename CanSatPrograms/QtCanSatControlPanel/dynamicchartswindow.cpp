#include "dynamicchartswindow.h"
#include "ui_dynamicchartswindow.h"

DynamicChartsWindow::DynamicChartsWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DynamicChartsWindow)
{
    ui->setupUi(this);
}

DynamicChartsWindow::~DynamicChartsWindow()
{
    delete ui;
}
