#include "dynamicchartswindow.h"
#include "ui_dynamicchartswindow.h"
#include <QDebug>

DynamicChartsWindow::DynamicChartsWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DynamicChartsWindow)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(timerFunction()));
    timer->start(400); // 2.5 times/sec
}

DynamicChartsWindow::~DynamicChartsWindow()
{
    delete ui;
}



void DynamicChartsWindow::timerFunction()
{
    if (!DynamicChartsWindow::isVisible()) timer->stop(); // to avoid multiple timers
    qDebug() << "update... " << test++;
}
