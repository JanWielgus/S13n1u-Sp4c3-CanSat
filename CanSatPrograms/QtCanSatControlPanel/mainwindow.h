#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dynamicchartswindow.h"
#include "komunikacja.h"
#include <QString>

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
    void readSerial();

    //void destroySerial();

    void on_CSautoPower_checkBox_clicked();

    void on_GSautoPower_checkBox_clicked();

    void on_chartsShow_pushButton_clicked();

    void on_searchGS_pushButton_clicked();

    void on_connectGS_pushButton_clicked();

    void on_endConnectGS_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    DynamicChartsWindow* dynCharts;

    QString port_name;

    const QString notConnectedText = "Not connected";
    const QString connectedText = "Connected";
    const QString notFoundText = "Not found";
    const QString foundText = "Found";
};

#endif // MAINWINDOW_H
