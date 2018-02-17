#ifndef DYNAMICCHARTSWINDOW_H
#define DYNAMICCHARTSWINDOW_H

#include <QMainWindow>
#include <QTimer>

namespace Ui {
class DynamicChartsWindow;
}

class DynamicChartsWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit DynamicChartsWindow(QWidget *parent = 0);
    ~DynamicChartsWindow();

public slots:
    void timerFunction();

private:
    Ui::DynamicChartsWindow *ui;
    QTimer* timer;

public:
    int test = 0;
};

#endif // DYNAMICCHARTSWINDOW_H
