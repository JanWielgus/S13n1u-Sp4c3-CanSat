#ifndef OKNO_H
#define OKNO_H

#include <QMainWindow>
#include "komunikacja.h"

namespace Ui {
class okno;
}

class okno : public QMainWindow
{
    Q_OBJECT

public:
    explicit okno(QWidget *parent = 0);
    ~okno();


public:
    Ui::okno *ui;


private slots:
    void readSerial();
};

#endif // OKNO_H
