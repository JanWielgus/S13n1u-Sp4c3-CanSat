/********************************************************************************
** Form generated from reading UI file 'okno.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_okno
{
public:
    QWidget *centralWidget;
    QPushButton *testSendButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *okno)
    {
        if (okno->objectName().isEmpty())
            okno->setObjectName(QStringLiteral("okno"));
        okno->resize(400, 300);
        centralWidget = new QWidget(okno);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        testSendButton = new QPushButton(centralWidget);
        testSendButton->setObjectName(QStringLiteral("testSendButton"));
        testSendButton->setGeometry(QRect(240, 140, 93, 28));
        okno->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(okno);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 26));
        okno->setMenuBar(menuBar);
        mainToolBar = new QToolBar(okno);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        okno->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(okno);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        okno->setStatusBar(statusBar);

        retranslateUi(okno);

        QMetaObject::connectSlotsByName(okno);
    } // setupUi

    void retranslateUi(QMainWindow *okno)
    {
        okno->setWindowTitle(QApplication::translate("okno", "okno", nullptr));
        testSendButton->setText(QApplication::translate("okno", "TestSend", nullptr));
    } // retranslateUi

};

namespace Ui {
    class okno: public Ui_okno {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OKNO_H
