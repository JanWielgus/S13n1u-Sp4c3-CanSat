/********************************************************************************
** Form generated from reading UI file 'okno.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OKNO_H
#define UI_OKNO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_okno
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *okno)
    {
        if (okno->objectName().isEmpty())
            okno->setObjectName(QStringLiteral("okno"));
        okno->resize(400, 300);
        menuBar = new QMenuBar(okno);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        okno->setMenuBar(menuBar);
        mainToolBar = new QToolBar(okno);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        okno->addToolBar(mainToolBar);
        centralWidget = new QWidget(okno);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        okno->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(okno);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        okno->setStatusBar(statusBar);

        retranslateUi(okno);

        QMetaObject::connectSlotsByName(okno);
    } // setupUi

    void retranslateUi(QMainWindow *okno)
    {
        okno->setWindowTitle(QApplication::translate("okno", "okno", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class okno: public Ui_okno {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OKNO_H
