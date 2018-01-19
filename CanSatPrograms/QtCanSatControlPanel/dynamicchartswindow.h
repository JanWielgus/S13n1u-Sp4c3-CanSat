#ifndef DYNAMICCHARTSWINDOW_H
#define DYNAMICCHARTSWINDOW_H

#include <QMainWindow>

namespace Ui {
class DynamicChartsWindow;
}

class DynamicChartsWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit DynamicChartsWindow(QWidget *parent = 0);
    ~DynamicChartsWindow();

private:
    Ui::DynamicChartsWindow *ui;
};

#endif // DYNAMICCHARTSWINDOW_H
