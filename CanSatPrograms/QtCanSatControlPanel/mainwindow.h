#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dynamicchartswindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_CSautoPower_checkBox_clicked();

    void on_GSautoPower_checkBox_clicked();

    void on_chartsShow_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    DynamicChartsWindow* dynCharts;
};

#endif // MAINWINDOW_H
