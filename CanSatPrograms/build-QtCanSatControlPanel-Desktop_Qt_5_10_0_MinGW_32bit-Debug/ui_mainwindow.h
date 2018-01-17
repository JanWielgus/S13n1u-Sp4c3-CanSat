/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *Tabs;
    QWidget *tab;
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox_4;
    QGroupBox *groupBox_6;
    QCheckBox *autoPower_checkBox;
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_11;
    QLineEdit *cansatBaudRate;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *powerButtonMode1;
    QRadioButton *powerButtonMode2;
    QRadioButton *powerButtonMode3;
    QRadioButton *powerButtonMode4;
    QVBoxLayout *verticalLayout_6;
    QRadioButton *cansatPower1;
    QRadioButton *cansatPower2;
    QRadioButton *cansatPower3;
    QRadioButton *cansatPower4;
    QGroupBox *groupBox_7;
    QWidget *widget2;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_4;
    QRadioButton *radioButton_6;
    QRadioButton *radioButton_5;
    QRadioButton *radioButton_7;
    QVBoxLayout *verticalLayout_5;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QGroupBox *groupBox_3;
    QGroupBox *groupBox_5;
    QLCDNumber *fallinglcdNumber;
    QGroupBox *groupBox_8;
    QSlider *heightSlider;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_22;
    QFrame *line_2;
    QFrame *line_3;
    QFrame *line_4;
    QFrame *line_5;
    QFrame *line_6;
    QGroupBox *groupBox_9;
    QWidget *widget3;
    QFormLayout *formLayout_2;
    QLabel *label;
    QLineEdit *pressure_lineEdit;
    QLabel *label_2;
    QLineEdit *temp_lineEdit;
    QLabel *label_3;
    QLineEdit *co2_lineEdit;
    QLabel *label_4;
    QLineEdit *tvoc_lineEdit;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *humid_lineEdit;
    QLineEdit *ionRad_lineEdit;
    QLineEdit *pm_lineEdit;
    QLineEdit *voltage_lineEdit;
    QLabel *label_13;
    QLineEdit *alt_lineEdit;
    QWidget *widget4;
    QFormLayout *formLayout_4;
    QLabel *label_19;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label_20;
    QLabel *label_21;
    QLineEdit *lineEdit_3;
    QWidget *tab_2;
    QGroupBox *groupBox;
    QGroupBox *groupBox_2;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_9;
    QLabel *label_10;
    QFrame *line;
    QSpacerItem *horizontalSpacer;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(960, 1000);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Tabs = new QTabWidget(centralWidget);
        Tabs->setObjectName(QStringLiteral("Tabs"));
        Tabs->setGeometry(QRect(7, 43, 931, 551));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout_3 = new QGridLayout(tab);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        groupBox_4 = new QGroupBox(tab);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_6 = new QGroupBox(groupBox_4);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        groupBox_6->setGeometry(QRect(40, 40, 311, 171));
        autoPower_checkBox = new QCheckBox(groupBox_6);
        autoPower_checkBox->setObjectName(QStringLiteral("autoPower_checkBox"));
        autoPower_checkBox->setGeometry(QRect(18, 135, 141, 20));
        widget = new QWidget(groupBox_6);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(150, 20, 111, 51));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_11 = new QLabel(widget);
        label_11->setObjectName(QStringLiteral("label_11"));

        verticalLayout_3->addWidget(label_11);

        cansatBaudRate = new QLineEdit(widget);
        cansatBaudRate->setObjectName(QStringLiteral("cansatBaudRate"));
        cansatBaudRate->setReadOnly(true);

        verticalLayout_3->addWidget(cansatBaudRate);

        widget1 = new QWidget(groupBox_6);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(18, 20, 99, 105));
        horizontalLayout_2 = new QHBoxLayout(widget1);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        powerButtonMode1 = new QRadioButton(widget1);
        powerButtonMode1->setObjectName(QStringLiteral("powerButtonMode1"));

        verticalLayout_2->addWidget(powerButtonMode1);

        powerButtonMode2 = new QRadioButton(widget1);
        powerButtonMode2->setObjectName(QStringLiteral("powerButtonMode2"));

        verticalLayout_2->addWidget(powerButtonMode2);

        powerButtonMode3 = new QRadioButton(widget1);
        powerButtonMode3->setObjectName(QStringLiteral("powerButtonMode3"));
        powerButtonMode3->setChecked(false);

        verticalLayout_2->addWidget(powerButtonMode3);

        powerButtonMode4 = new QRadioButton(widget1);
        powerButtonMode4->setObjectName(QStringLiteral("powerButtonMode4"));
        powerButtonMode4->setChecked(true);

        verticalLayout_2->addWidget(powerButtonMode4);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        cansatPower1 = new QRadioButton(widget1);
        cansatPower1->setObjectName(QStringLiteral("cansatPower1"));
        cansatPower1->setEnabled(false);

        verticalLayout_6->addWidget(cansatPower1);

        cansatPower2 = new QRadioButton(widget1);
        cansatPower2->setObjectName(QStringLiteral("cansatPower2"));
        cansatPower2->setEnabled(false);

        verticalLayout_6->addWidget(cansatPower2);

        cansatPower3 = new QRadioButton(widget1);
        cansatPower3->setObjectName(QStringLiteral("cansatPower3"));
        cansatPower3->setEnabled(false);

        verticalLayout_6->addWidget(cansatPower3);

        cansatPower4 = new QRadioButton(widget1);
        cansatPower4->setObjectName(QStringLiteral("cansatPower4"));
        cansatPower4->setEnabled(false);

        verticalLayout_6->addWidget(cansatPower4);


        horizontalLayout_2->addLayout(verticalLayout_6);

        groupBox_7 = new QGroupBox(groupBox_4);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        groupBox_7->setGeometry(QRect(30, 220, 201, 121));
        widget2 = new QWidget(groupBox_7);
        widget2->setObjectName(QStringLiteral("widget2"));
        widget2->setGeometry(QRect(10, 30, 178, 78));
        horizontalLayout_3 = new QHBoxLayout(widget2);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        radioButton_6 = new QRadioButton(widget2);
        radioButton_6->setObjectName(QStringLiteral("radioButton_6"));

        verticalLayout_4->addWidget(radioButton_6);

        radioButton_5 = new QRadioButton(widget2);
        radioButton_5->setObjectName(QStringLiteral("radioButton_5"));
        radioButton_5->setChecked(true);

        verticalLayout_4->addWidget(radioButton_5);

        radioButton_7 = new QRadioButton(widget2);
        radioButton_7->setObjectName(QStringLiteral("radioButton_7"));

        verticalLayout_4->addWidget(radioButton_7);


        horizontalLayout_3->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        radioButton = new QRadioButton(widget2);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setEnabled(false);

        verticalLayout_5->addWidget(radioButton);

        radioButton_2 = new QRadioButton(widget2);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setEnabled(false);

        verticalLayout_5->addWidget(radioButton_2);

        radioButton_3 = new QRadioButton(widget2);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));
        radioButton_3->setEnabled(false);

        verticalLayout_5->addWidget(radioButton_3);


        horizontalLayout_3->addLayout(verticalLayout_5);


        gridLayout_3->addWidget(groupBox_4, 0, 1, 1, 1);

        groupBox_3 = new QGroupBox(tab);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_5 = new QGroupBox(groupBox_3);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(220, 40, 181, 81));
        fallinglcdNumber = new QLCDNumber(groupBox_5);
        fallinglcdNumber->setObjectName(QStringLiteral("fallinglcdNumber"));
        fallinglcdNumber->setGeometry(QRect(10, 20, 161, 51));
        fallinglcdNumber->setSmallDecimalPoint(false);
        fallinglcdNumber->setSegmentStyle(QLCDNumber::Filled);
        fallinglcdNumber->setProperty("value", QVariant(0));
        fallinglcdNumber->setProperty("intValue", QVariant(0));
        groupBox_8 = new QGroupBox(groupBox_3);
        groupBox_8->setObjectName(QStringLiteral("groupBox_8"));
        groupBox_8->setGeometry(QRect(210, 140, 121, 221));
        heightSlider = new QSlider(groupBox_8);
        heightSlider->setObjectName(QStringLiteral("heightSlider"));
        heightSlider->setEnabled(false);
        heightSlider->setGeometry(QRect(20, 24, 22, 191));
        heightSlider->setMouseTracking(false);
        heightSlider->setAutoFillBackground(false);
        heightSlider->setMaximum(3000);
        heightSlider->setValue(0);
        heightSlider->setTracking(true);
        heightSlider->setOrientation(Qt::Vertical);
        heightSlider->setInvertedControls(false);
        label_14 = new QLabel(groupBox_8);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(70, 200, 21, 16));
        label_15 = new QLabel(groupBox_8);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(70, 21, 41, 16));
        label_16 = new QLabel(groupBox_8);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(70, 81, 55, 16));
        label_17 = new QLabel(groupBox_8);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(70, 140, 55, 16));
        label_22 = new QLabel(groupBox_8);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(70, 170, 55, 16));
        line_2 = new QFrame(groupBox_8);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(45, 201, 16, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(groupBox_8);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(45, 172, 16, 16));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_4 = new QFrame(groupBox_8);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setGeometry(QRect(45, 142, 16, 16));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        line_5 = new QFrame(groupBox_8);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setGeometry(QRect(45, 82, 16, 16));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);
        line_6 = new QFrame(groupBox_8);
        line_6->setObjectName(QStringLiteral("line_6"));
        line_6->setGeometry(QRect(45, 22, 16, 16));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);
        groupBox_9 = new QGroupBox(groupBox_3);
        groupBox_9->setObjectName(QStringLiteral("groupBox_9"));
        groupBox_9->setGeometry(QRect(10, 50, 191, 301));
        widget3 = new QWidget(groupBox_9);
        widget3->setObjectName(QStringLiteral("widget3"));
        widget3->setGeometry(QRect(4, 19, 181, 271));
        formLayout_2 = new QFormLayout(widget3);
        formLayout_2->setSpacing(6);
        formLayout_2->setContentsMargins(11, 11, 11, 11);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget3);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label);

        pressure_lineEdit = new QLineEdit(widget3);
        pressure_lineEdit->setObjectName(QStringLiteral("pressure_lineEdit"));
        pressure_lineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        pressure_lineEdit->setReadOnly(true);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, pressure_lineEdit);

        label_2 = new QLabel(widget3);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_2);

        temp_lineEdit = new QLineEdit(widget3);
        temp_lineEdit->setObjectName(QStringLiteral("temp_lineEdit"));
        temp_lineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        temp_lineEdit->setReadOnly(true);

        formLayout_2->setWidget(2, QFormLayout::FieldRole, temp_lineEdit);

        label_3 = new QLabel(widget3);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout_2->setWidget(3, QFormLayout::LabelRole, label_3);

        co2_lineEdit = new QLineEdit(widget3);
        co2_lineEdit->setObjectName(QStringLiteral("co2_lineEdit"));
        co2_lineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        co2_lineEdit->setReadOnly(true);

        formLayout_2->setWidget(3, QFormLayout::FieldRole, co2_lineEdit);

        label_4 = new QLabel(widget3);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout_2->setWidget(4, QFormLayout::LabelRole, label_4);

        tvoc_lineEdit = new QLineEdit(widget3);
        tvoc_lineEdit->setObjectName(QStringLiteral("tvoc_lineEdit"));
        tvoc_lineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        tvoc_lineEdit->setReadOnly(true);

        formLayout_2->setWidget(4, QFormLayout::FieldRole, tvoc_lineEdit);

        label_5 = new QLabel(widget3);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout_2->setWidget(5, QFormLayout::LabelRole, label_5);

        label_6 = new QLabel(widget3);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout_2->setWidget(6, QFormLayout::LabelRole, label_6);

        label_7 = new QLabel(widget3);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout_2->setWidget(7, QFormLayout::LabelRole, label_7);

        label_8 = new QLabel(widget3);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout_2->setWidget(8, QFormLayout::LabelRole, label_8);

        humid_lineEdit = new QLineEdit(widget3);
        humid_lineEdit->setObjectName(QStringLiteral("humid_lineEdit"));
        humid_lineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        humid_lineEdit->setReadOnly(true);

        formLayout_2->setWidget(5, QFormLayout::FieldRole, humid_lineEdit);

        ionRad_lineEdit = new QLineEdit(widget3);
        ionRad_lineEdit->setObjectName(QStringLiteral("ionRad_lineEdit"));
        ionRad_lineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        ionRad_lineEdit->setReadOnly(true);

        formLayout_2->setWidget(6, QFormLayout::FieldRole, ionRad_lineEdit);

        pm_lineEdit = new QLineEdit(widget3);
        pm_lineEdit->setObjectName(QStringLiteral("pm_lineEdit"));
        pm_lineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        pm_lineEdit->setReadOnly(true);

        formLayout_2->setWidget(7, QFormLayout::FieldRole, pm_lineEdit);

        voltage_lineEdit = new QLineEdit(widget3);
        voltage_lineEdit->setObjectName(QStringLiteral("voltage_lineEdit"));
        voltage_lineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        voltage_lineEdit->setReadOnly(true);

        formLayout_2->setWidget(8, QFormLayout::FieldRole, voltage_lineEdit);

        label_13 = new QLabel(widget3);
        label_13->setObjectName(QStringLiteral("label_13"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_13);

        alt_lineEdit = new QLineEdit(widget3);
        alt_lineEdit->setObjectName(QStringLiteral("alt_lineEdit"));
        alt_lineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        alt_lineEdit->setReadOnly(true);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, alt_lineEdit);

        widget4 = new QWidget(groupBox_3);
        widget4->setObjectName(QStringLiteral("widget4"));
        widget4->setGeometry(QRect(20, 370, 191, 82));
        formLayout_4 = new QFormLayout(widget4);
        formLayout_4->setSpacing(6);
        formLayout_4->setContentsMargins(11, 11, 11, 11);
        formLayout_4->setObjectName(QStringLiteral("formLayout_4"));
        formLayout_4->setContentsMargins(0, 0, 0, 0);
        label_19 = new QLabel(widget4);
        label_19->setObjectName(QStringLiteral("label_19"));

        formLayout_4->setWidget(0, QFormLayout::LabelRole, label_19);

        lineEdit = new QLineEdit(widget4);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        formLayout_4->setWidget(0, QFormLayout::FieldRole, lineEdit);

        lineEdit_2 = new QLineEdit(widget4);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        formLayout_4->setWidget(1, QFormLayout::FieldRole, lineEdit_2);

        label_20 = new QLabel(widget4);
        label_20->setObjectName(QStringLiteral("label_20"));

        formLayout_4->setWidget(1, QFormLayout::LabelRole, label_20);

        label_21 = new QLabel(widget4);
        label_21->setObjectName(QStringLiteral("label_21"));

        formLayout_4->setWidget(2, QFormLayout::LabelRole, label_21);

        lineEdit_3 = new QLineEdit(widget4);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        formLayout_4->setWidget(2, QFormLayout::FieldRole, lineEdit_3);


        gridLayout_3->addWidget(groupBox_3, 0, 0, 1, 1);

        Tabs->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        groupBox = new QGroupBox(tab_2);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 321, 261));
        groupBox_2 = new QGroupBox(tab_2);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(420, 170, 120, 80));
        Tabs->addTab(tab_2, QString());
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(6, 5, 1111, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(horizontalLayoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setEnabled(true);

        horizontalLayout->addWidget(label_9);

        label_10 = new QLabel(horizontalLayoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout->addWidget(label_10);

        line = new QFrame(horizontalLayoutWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 960, 26));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        Tabs->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Live settings", nullptr));
        groupBox_6->setTitle(QApplication::translate("MainWindow", "Communication", nullptr));
        autoPower_checkBox->setText(QApplication::translate("MainWindow", "Auto power control", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "CanSat baud rate:", nullptr));
        cansatBaudRate->setText(QApplication::translate("MainWindow", "1200 kbps", nullptr));
        powerButtonMode1->setText(QApplication::translate("MainWindow", "27 dBm", nullptr));
        powerButtonMode2->setText(QApplication::translate("MainWindow", "24 dBm", nullptr));
        powerButtonMode3->setText(QApplication::translate("MainWindow", "21 dBm", nullptr));
        powerButtonMode4->setText(QApplication::translate("MainWindow", "18 dBm", nullptr));
        cansatPower1->setText(QString());
        cansatPower2->setText(QString());
        cansatPower3->setText(QString());
        cansatPower4->setText(QString());
        groupBox_7->setTitle(QApplication::translate("MainWindow", "Working mode", nullptr));
        radioButton_6->setText(QApplication::translate("MainWindow", "Before start", nullptr));
        radioButton_5->setText(QApplication::translate("MainWindow", "CanSat main mission", nullptr));
        radioButton_7->setText(QApplication::translate("MainWindow", "Searching for CanSat", nullptr));
        radioButton->setText(QString());
        radioButton_2->setText(QString());
        radioButton_3->setText(QString());
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Measurements", nullptr));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "Falling velocity [m/s]", nullptr));
        groupBox_8->setTitle(QApplication::translate("MainWindow", "Estimated height", nullptr));
        label_14->setText(QApplication::translate("MainWindow", "0m", nullptr));
        label_15->setText(QApplication::translate("MainWindow", "3000m", nullptr));
        label_16->setText(QApplication::translate("MainWindow", "2000m", nullptr));
        label_17->setText(QApplication::translate("MainWindow", "1000m", nullptr));
        label_22->setText(QApplication::translate("MainWindow", "500m", nullptr));
        groupBox_9->setTitle(QApplication::translate("MainWindow", "Readings:", nullptr));
        label->setText(QApplication::translate("MainWindow", "Pressure:", nullptr));
        pressure_lineEdit->setText(QApplication::translate("MainWindow", "0 Pa", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Temperature:", nullptr));
        temp_lineEdit->setText(QApplication::translate("MainWindow", "0 \302\260C", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "CO2:", nullptr));
        co2_lineEdit->setText(QApplication::translate("MainWindow", "0 PPM", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "tVOC:", nullptr));
        tvoc_lineEdit->setText(QApplication::translate("MainWindow", "0 PPB", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "Real humidity:", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "Ionizing radiation:", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "PM 2.5:", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "Voltage:", nullptr));
        humid_lineEdit->setText(QApplication::translate("MainWindow", "0 %", nullptr));
        ionRad_lineEdit->setText(QApplication::translate("MainWindow", "0 msv/h", nullptr));
        pm_lineEdit->setText(QApplication::translate("MainWindow", "0 \316\274m", nullptr));
        voltage_lineEdit->setText(QApplication::translate("MainWindow", "0 V", nullptr));
        label_13->setText(QApplication::translate("MainWindow", "Altitude:", nullptr));
        alt_lineEdit->setText(QApplication::translate("MainWindow", "0 m", nullptr));
        label_19->setText(QApplication::translate("MainWindow", "PPS:", nullptr));
        lineEdit->setText(QApplication::translate("MainWindow", "0", nullptr));
        lineEdit_2->setText(QApplication::translate("MainWindow", "0", nullptr));
        label_20->setText(QApplication::translate("MainWindow", "Packets sent:", nullptr));
        label_21->setText(QApplication::translate("MainWindow", "Packets recieved:", nullptr));
        lineEdit_3->setText(QApplication::translate("MainWindow", "0", nullptr));
        Tabs->setTabText(Tabs->indexOf(tab), QApplication::translate("MainWindow", "General", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "Communication", nullptr));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "GroupBox", nullptr));
        Tabs->setTabText(Tabs->indexOf(tab_2), QApplication::translate("MainWindow", "Settings", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "Status:", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "Brak Sygna\305\202u", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
