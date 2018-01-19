/********************************************************************************
** Form generated from reading UI file 'dynamicchartswindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DYNAMICCHARTSWINDOW_H
#define UI_DYNAMICCHARTSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DynamicChartsWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QWidget *PressureChart_widget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *DynamicChartsWindow)
    {
        if (DynamicChartsWindow->objectName().isEmpty())
            DynamicChartsWindow->setObjectName(QStringLiteral("DynamicChartsWindow"));
        DynamicChartsWindow->resize(960, 1000);
        centralwidget = new QWidget(DynamicChartsWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 321, 291));
        PressureChart_widget = new QWidget(groupBox);
        PressureChart_widget->setObjectName(QStringLiteral("PressureChart_widget"));
        PressureChart_widget->setGeometry(QRect(20, 30, 271, 231));
        DynamicChartsWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(DynamicChartsWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 960, 26));
        DynamicChartsWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(DynamicChartsWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        DynamicChartsWindow->setStatusBar(statusbar);

        retranslateUi(DynamicChartsWindow);

        QMetaObject::connectSlotsByName(DynamicChartsWindow);
    } // setupUi

    void retranslateUi(QMainWindow *DynamicChartsWindow)
    {
        DynamicChartsWindow->setWindowTitle(QApplication::translate("DynamicChartsWindow", "MainWindow", nullptr));
        groupBox->setTitle(QApplication::translate("DynamicChartsWindow", "Pressure", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DynamicChartsWindow: public Ui_DynamicChartsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DYNAMICCHARTSWINDOW_H
