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
#include <QtWidgets/QComboBox>
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
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTimeEdit>
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
    QGroupBox *groupBox_3;
    QGroupBox *groupBox_5;
    QLCDNumber *fallingV_lcdNumber;
    QGroupBox *groupBox_8;
    QSlider *altitudeSlider;
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
    QWidget *layoutWidget;
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
    QLineEdit *humid_lineEdit;
    QLineEdit *ionRad_lineEdit;
    QLineEdit *pm_lineEdit;
    QLineEdit *voltage_lineEdit;
    QLabel *label_13;
    QLineEdit *alt_lineEdit;
    QLabel *label_8;
    QLabel *label_24;
    QLineEdit *ang_speed_lineEdit;
    QLabel *label_25;
    QLineEdit *heading_lineEdit;
    QPushButton *chartsShow_pushButton;
    QGroupBox *groupBox_4;
    QGroupBox *groupBox_6;
    QCheckBox *CSautoPower_checkBox;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_11;
    QLineEdit *cansatBaudRate;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *CSpowerButtonMode1;
    QRadioButton *CSpowerButtonMode2;
    QRadioButton *CSpowerButtonMode3;
    QRadioButton *CSpowerButtonMode4;
    QVBoxLayout *verticalLayout_6;
    QRadioButton *cansatPower1;
    QRadioButton *cansatPower2;
    QRadioButton *cansatPower3;
    QRadioButton *cansatPower4;
    QWidget *layoutWidget3;
    QFormLayout *formLayout_4;
    QLabel *label_19;
    QLineEdit *PPS_lineEdit;
    QLabel *label_20;
    QLineEdit *PacketsSent_lineEdit;
    QLabel *label_21;
    QLineEdit *PacketsRecieved_lineEdit;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_7;
    QRadioButton *GSpowerButtonMode1;
    QRadioButton *GSpowerButtonMode2;
    QRadioButton *GSpowerButtonMode3;
    QRadioButton *GSpowerButtonMode4;
    QVBoxLayout *verticalLayout_8;
    QRadioButton *cansatPower1_2;
    QRadioButton *cansatPower2_2;
    QRadioButton *cansatPower3_2;
    QRadioButton *cansatPower4_2;
    QFrame *line_7;
    QLabel *label_12;
    QLabel *label_18;
    QCheckBox *GSautoPower_checkBox;
    QFrame *line_9;
    QFrame *line_10;
    QGroupBox *groupBox_7;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_4;
    QRadioButton *wMode1_button;
    QRadioButton *wMode2_button;
    QRadioButton *wMode3_button;
    QVBoxLayout *verticalLayout_5;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QGroupBox *groupBox_10;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout;
    QCheckBox *flightStage1_checkBox;
    QCheckBox *flightStage2_checkBox;
    QCheckBox *flightStage3_checkBox;
    QCheckBox *flightStage4_checkBox;
    QFrame *line_8;
    QLabel *label_23;
    QCheckBox *failure1_checkBox;
    QCheckBox *failure2_checkBox;
    QGroupBox *groupBox_11;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_9;
    QProgressBar *progressBar;
    QTimeEdit *timeEdit;
    QWidget *tab_2;
    QGroupBox *groupBox;
    QGroupBox *groupBox_2;
    QComboBox *listOfDevicesGS_comboBox;
    QLabel *label_26;
    QPushButton *searchGS_pushButton;
    QPushButton *connectGS_pushButton;
    QLabel *gs_arduino_state_label;
    QPushButton *endConnectGS_pushButton;
    QWidget *layoutWidget4;
    QFormLayout *formLayout;
    QLabel *label_27;
    QLabel *connectionStateGS_label;
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
        Tabs->setGeometry(QRect(7, 43, 931, 871));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout_3 = new QGridLayout(tab);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        groupBox_3 = new QGroupBox(tab);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_5 = new QGroupBox(groupBox_3);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(217, 50, 181, 81));
        fallingV_lcdNumber = new QLCDNumber(groupBox_5);
        fallingV_lcdNumber->setObjectName(QStringLiteral("fallingV_lcdNumber"));
        fallingV_lcdNumber->setGeometry(QRect(10, 20, 161, 51));
        fallingV_lcdNumber->setSmallDecimalPoint(false);
        fallingV_lcdNumber->setSegmentStyle(QLCDNumber::Filled);
        fallingV_lcdNumber->setProperty("value", QVariant(0));
        fallingV_lcdNumber->setProperty("intValue", QVariant(0));
        groupBox_8 = new QGroupBox(groupBox_3);
        groupBox_8->setObjectName(QStringLiteral("groupBox_8"));
        groupBox_8->setGeometry(QRect(217, 140, 121, 221));
        altitudeSlider = new QSlider(groupBox_8);
        altitudeSlider->setObjectName(QStringLiteral("altitudeSlider"));
        altitudeSlider->setEnabled(false);
        altitudeSlider->setGeometry(QRect(20, 24, 22, 191));
        altitudeSlider->setMouseTracking(false);
        altitudeSlider->setAutoFillBackground(false);
        altitudeSlider->setMaximum(3000);
        altitudeSlider->setValue(0);
        altitudeSlider->setTracking(true);
        altitudeSlider->setOrientation(Qt::Vertical);
        altitudeSlider->setInvertedControls(false);
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
        groupBox_9->setGeometry(QRect(10, 50, 191, 421));
        layoutWidget = new QWidget(groupBox_9);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(4, 19, 181, 381));
        formLayout_2 = new QFormLayout(layoutWidget);
        formLayout_2->setSpacing(6);
        formLayout_2->setContentsMargins(11, 11, 11, 11);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label);

        pressure_lineEdit = new QLineEdit(layoutWidget);
        pressure_lineEdit->setObjectName(QStringLiteral("pressure_lineEdit"));
        pressure_lineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        pressure_lineEdit->setReadOnly(true);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, pressure_lineEdit);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_2);

        temp_lineEdit = new QLineEdit(layoutWidget);
        temp_lineEdit->setObjectName(QStringLiteral("temp_lineEdit"));
        temp_lineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        temp_lineEdit->setReadOnly(true);

        formLayout_2->setWidget(2, QFormLayout::FieldRole, temp_lineEdit);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout_2->setWidget(3, QFormLayout::LabelRole, label_3);

        co2_lineEdit = new QLineEdit(layoutWidget);
        co2_lineEdit->setObjectName(QStringLiteral("co2_lineEdit"));
        co2_lineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        co2_lineEdit->setReadOnly(true);

        formLayout_2->setWidget(3, QFormLayout::FieldRole, co2_lineEdit);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout_2->setWidget(4, QFormLayout::LabelRole, label_4);

        tvoc_lineEdit = new QLineEdit(layoutWidget);
        tvoc_lineEdit->setObjectName(QStringLiteral("tvoc_lineEdit"));
        tvoc_lineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        tvoc_lineEdit->setReadOnly(true);

        formLayout_2->setWidget(4, QFormLayout::FieldRole, tvoc_lineEdit);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout_2->setWidget(5, QFormLayout::LabelRole, label_5);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout_2->setWidget(6, QFormLayout::LabelRole, label_6);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout_2->setWidget(7, QFormLayout::LabelRole, label_7);

        humid_lineEdit = new QLineEdit(layoutWidget);
        humid_lineEdit->setObjectName(QStringLiteral("humid_lineEdit"));
        humid_lineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        humid_lineEdit->setReadOnly(true);

        formLayout_2->setWidget(5, QFormLayout::FieldRole, humid_lineEdit);

        ionRad_lineEdit = new QLineEdit(layoutWidget);
        ionRad_lineEdit->setObjectName(QStringLiteral("ionRad_lineEdit"));
        ionRad_lineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        ionRad_lineEdit->setReadOnly(true);

        formLayout_2->setWidget(6, QFormLayout::FieldRole, ionRad_lineEdit);

        pm_lineEdit = new QLineEdit(layoutWidget);
        pm_lineEdit->setObjectName(QStringLiteral("pm_lineEdit"));
        pm_lineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        pm_lineEdit->setReadOnly(true);

        formLayout_2->setWidget(7, QFormLayout::FieldRole, pm_lineEdit);

        voltage_lineEdit = new QLineEdit(layoutWidget);
        voltage_lineEdit->setObjectName(QStringLiteral("voltage_lineEdit"));
        voltage_lineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        voltage_lineEdit->setReadOnly(true);

        formLayout_2->setWidget(8, QFormLayout::FieldRole, voltage_lineEdit);

        label_13 = new QLabel(layoutWidget);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_13);

        alt_lineEdit = new QLineEdit(layoutWidget);
        alt_lineEdit->setObjectName(QStringLiteral("alt_lineEdit"));
        alt_lineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        alt_lineEdit->setReadOnly(true);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, alt_lineEdit);

        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout_2->setWidget(8, QFormLayout::LabelRole, label_8);

        label_24 = new QLabel(layoutWidget);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout_2->setWidget(10, QFormLayout::LabelRole, label_24);

        ang_speed_lineEdit = new QLineEdit(layoutWidget);
        ang_speed_lineEdit->setObjectName(QStringLiteral("ang_speed_lineEdit"));
        ang_speed_lineEdit->setLayoutDirection(Qt::LeftToRight);
        ang_speed_lineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        ang_speed_lineEdit->setReadOnly(true);

        formLayout_2->setWidget(10, QFormLayout::FieldRole, ang_speed_lineEdit);

        label_25 = new QLabel(layoutWidget);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout_2->setWidget(9, QFormLayout::LabelRole, label_25);

        heading_lineEdit = new QLineEdit(layoutWidget);
        heading_lineEdit->setObjectName(QStringLiteral("heading_lineEdit"));
        heading_lineEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        heading_lineEdit->setReadOnly(true);

        formLayout_2->setWidget(9, QFormLayout::FieldRole, heading_lineEdit);

        chartsShow_pushButton = new QPushButton(groupBox_3);
        chartsShow_pushButton->setObjectName(QStringLiteral("chartsShow_pushButton"));
        chartsShow_pushButton->setGeometry(QRect(18, 490, 411, 51));

        gridLayout_3->addWidget(groupBox_3, 0, 0, 1, 1);

        groupBox_4 = new QGroupBox(tab);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_6 = new QGroupBox(groupBox_4);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        groupBox_6->setGeometry(QRect(10, 30, 421, 251));
        CSautoPower_checkBox = new QCheckBox(groupBox_6);
        CSautoPower_checkBox->setObjectName(QStringLiteral("CSautoPower_checkBox"));
        CSautoPower_checkBox->setGeometry(QRect(12, 154, 71, 20));
        layoutWidget1 = new QWidget(groupBox_6);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(12, 190, 111, 51));
        verticalLayout_3 = new QVBoxLayout(layoutWidget1);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_11 = new QLabel(layoutWidget1);
        label_11->setObjectName(QStringLiteral("label_11"));

        verticalLayout_3->addWidget(label_11);

        cansatBaudRate = new QLineEdit(layoutWidget1);
        cansatBaudRate->setObjectName(QStringLiteral("cansatBaudRate"));
        cansatBaudRate->setReadOnly(true);

        verticalLayout_3->addWidget(cansatBaudRate);

        layoutWidget2 = new QWidget(groupBox_6);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 44, 103, 105));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        CSpowerButtonMode1 = new QRadioButton(layoutWidget2);
        CSpowerButtonMode1->setObjectName(QStringLiteral("CSpowerButtonMode1"));

        verticalLayout_2->addWidget(CSpowerButtonMode1);

        CSpowerButtonMode2 = new QRadioButton(layoutWidget2);
        CSpowerButtonMode2->setObjectName(QStringLiteral("CSpowerButtonMode2"));

        verticalLayout_2->addWidget(CSpowerButtonMode2);

        CSpowerButtonMode3 = new QRadioButton(layoutWidget2);
        CSpowerButtonMode3->setObjectName(QStringLiteral("CSpowerButtonMode3"));
        CSpowerButtonMode3->setChecked(false);

        verticalLayout_2->addWidget(CSpowerButtonMode3);

        CSpowerButtonMode4 = new QRadioButton(layoutWidget2);
        CSpowerButtonMode4->setObjectName(QStringLiteral("CSpowerButtonMode4"));
        CSpowerButtonMode4->setChecked(true);

        verticalLayout_2->addWidget(CSpowerButtonMode4);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        cansatPower1 = new QRadioButton(layoutWidget2);
        cansatPower1->setObjectName(QStringLiteral("cansatPower1"));
        cansatPower1->setEnabled(false);

        verticalLayout_6->addWidget(cansatPower1);

        cansatPower2 = new QRadioButton(layoutWidget2);
        cansatPower2->setObjectName(QStringLiteral("cansatPower2"));
        cansatPower2->setEnabled(false);

        verticalLayout_6->addWidget(cansatPower2);

        cansatPower3 = new QRadioButton(layoutWidget2);
        cansatPower3->setObjectName(QStringLiteral("cansatPower3"));
        cansatPower3->setEnabled(false);

        verticalLayout_6->addWidget(cansatPower3);

        cansatPower4 = new QRadioButton(layoutWidget2);
        cansatPower4->setObjectName(QStringLiteral("cansatPower4"));
        cansatPower4->setEnabled(false);

        verticalLayout_6->addWidget(cansatPower4);


        horizontalLayout_2->addLayout(verticalLayout_6);

        layoutWidget3 = new QWidget(groupBox_6);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(222, 44, 191, 89));
        formLayout_4 = new QFormLayout(layoutWidget3);
        formLayout_4->setSpacing(6);
        formLayout_4->setContentsMargins(11, 11, 11, 11);
        formLayout_4->setObjectName(QStringLiteral("formLayout_4"));
        formLayout_4->setContentsMargins(0, 0, 0, 0);
        label_19 = new QLabel(layoutWidget3);
        label_19->setObjectName(QStringLiteral("label_19"));

        formLayout_4->setWidget(0, QFormLayout::LabelRole, label_19);

        PPS_lineEdit = new QLineEdit(layoutWidget3);
        PPS_lineEdit->setObjectName(QStringLiteral("PPS_lineEdit"));
        PPS_lineEdit->setLayoutDirection(Qt::LeftToRight);
        PPS_lineEdit->setReadOnly(true);

        formLayout_4->setWidget(0, QFormLayout::FieldRole, PPS_lineEdit);

        label_20 = new QLabel(layoutWidget3);
        label_20->setObjectName(QStringLiteral("label_20"));

        formLayout_4->setWidget(1, QFormLayout::LabelRole, label_20);

        PacketsSent_lineEdit = new QLineEdit(layoutWidget3);
        PacketsSent_lineEdit->setObjectName(QStringLiteral("PacketsSent_lineEdit"));
        PacketsSent_lineEdit->setReadOnly(true);

        formLayout_4->setWidget(1, QFormLayout::FieldRole, PacketsSent_lineEdit);

        label_21 = new QLabel(layoutWidget3);
        label_21->setObjectName(QStringLiteral("label_21"));

        formLayout_4->setWidget(2, QFormLayout::LabelRole, label_21);

        PacketsRecieved_lineEdit = new QLineEdit(layoutWidget3);
        PacketsRecieved_lineEdit->setObjectName(QStringLiteral("PacketsRecieved_lineEdit"));
        PacketsRecieved_lineEdit->setReadOnly(true);

        formLayout_4->setWidget(2, QFormLayout::FieldRole, PacketsRecieved_lineEdit);

        layoutWidget_2 = new QWidget(groupBox_6);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(116, 44, 99, 105));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        GSpowerButtonMode1 = new QRadioButton(layoutWidget_2);
        GSpowerButtonMode1->setObjectName(QStringLiteral("GSpowerButtonMode1"));

        verticalLayout_7->addWidget(GSpowerButtonMode1);

        GSpowerButtonMode2 = new QRadioButton(layoutWidget_2);
        GSpowerButtonMode2->setObjectName(QStringLiteral("GSpowerButtonMode2"));

        verticalLayout_7->addWidget(GSpowerButtonMode2);

        GSpowerButtonMode3 = new QRadioButton(layoutWidget_2);
        GSpowerButtonMode3->setObjectName(QStringLiteral("GSpowerButtonMode3"));
        GSpowerButtonMode3->setChecked(false);

        verticalLayout_7->addWidget(GSpowerButtonMode3);

        GSpowerButtonMode4 = new QRadioButton(layoutWidget_2);
        GSpowerButtonMode4->setObjectName(QStringLiteral("GSpowerButtonMode4"));
        GSpowerButtonMode4->setChecked(true);

        verticalLayout_7->addWidget(GSpowerButtonMode4);


        horizontalLayout_3->addLayout(verticalLayout_7);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        cansatPower1_2 = new QRadioButton(layoutWidget_2);
        cansatPower1_2->setObjectName(QStringLiteral("cansatPower1_2"));
        cansatPower1_2->setEnabled(false);

        verticalLayout_8->addWidget(cansatPower1_2);

        cansatPower2_2 = new QRadioButton(layoutWidget_2);
        cansatPower2_2->setObjectName(QStringLiteral("cansatPower2_2"));
        cansatPower2_2->setEnabled(false);

        verticalLayout_8->addWidget(cansatPower2_2);

        cansatPower3_2 = new QRadioButton(layoutWidget_2);
        cansatPower3_2->setObjectName(QStringLiteral("cansatPower3_2"));
        cansatPower3_2->setEnabled(false);

        verticalLayout_8->addWidget(cansatPower3_2);

        cansatPower4_2 = new QRadioButton(layoutWidget_2);
        cansatPower4_2->setObjectName(QStringLiteral("cansatPower4_2"));
        cansatPower4_2->setEnabled(false);

        verticalLayout_8->addWidget(cansatPower4_2);


        horizontalLayout_3->addLayout(verticalLayout_8);

        line_7 = new QFrame(groupBox_6);
        line_7->setObjectName(QStringLiteral("line_7"));
        line_7->setGeometry(QRect(102, 26, 20, 111));
        line_7->setFrameShape(QFrame::VLine);
        line_7->setFrameShadow(QFrame::Sunken);
        label_12 = new QLabel(groupBox_6);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(10, 20, 55, 16));
        label_18 = new QLabel(groupBox_6);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(120, 20, 91, 16));
        GSautoPower_checkBox = new QCheckBox(groupBox_6);
        GSautoPower_checkBox->setObjectName(QStringLiteral("GSautoPower_checkBox"));
        GSautoPower_checkBox->setGeometry(QRect(119, 154, 71, 20));
        line_9 = new QFrame(groupBox_6);
        line_9->setObjectName(QStringLiteral("line_9"));
        line_9->setGeometry(QRect(204, 26, 20, 111));
        line_9->setFrameShape(QFrame::VLine);
        line_9->setFrameShadow(QFrame::Sunken);
        line_10 = new QFrame(groupBox_6);
        line_10->setObjectName(QStringLiteral("line_10"));
        line_10->setGeometry(QRect(9, 172, 401, 20));
        line_10->setFrameShape(QFrame::HLine);
        line_10->setFrameShadow(QFrame::Sunken);
        groupBox_7 = new QGroupBox(groupBox_4);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        groupBox_7->setGeometry(QRect(10, 290, 191, 101));
        horizontalLayoutWidget_2 = new QWidget(groupBox_7);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(7, 18, 181, 78));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        wMode1_button = new QRadioButton(horizontalLayoutWidget_2);
        wMode1_button->setObjectName(QStringLiteral("wMode1_button"));

        verticalLayout_4->addWidget(wMode1_button);

        wMode2_button = new QRadioButton(horizontalLayoutWidget_2);
        wMode2_button->setObjectName(QStringLiteral("wMode2_button"));
        wMode2_button->setChecked(true);

        verticalLayout_4->addWidget(wMode2_button);

        wMode3_button = new QRadioButton(horizontalLayoutWidget_2);
        wMode3_button->setObjectName(QStringLiteral("wMode3_button"));

        verticalLayout_4->addWidget(wMode3_button);


        horizontalLayout_4->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        radioButton = new QRadioButton(horizontalLayoutWidget_2);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setEnabled(false);

        verticalLayout_5->addWidget(radioButton);

        radioButton_2 = new QRadioButton(horizontalLayoutWidget_2);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setEnabled(false);

        verticalLayout_5->addWidget(radioButton_2);

        radioButton_3 = new QRadioButton(horizontalLayoutWidget_2);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));
        radioButton_3->setEnabled(false);

        verticalLayout_5->addWidget(radioButton_3);


        horizontalLayout_4->addLayout(verticalLayout_5);

        groupBox_10 = new QGroupBox(groupBox_4);
        groupBox_10->setObjectName(QStringLiteral("groupBox_10"));
        groupBox_10->setGeometry(QRect(250, 290, 181, 251));
        horizontalLayoutWidget_3 = new QWidget(groupBox_10);
        horizontalLayoutWidget_3->setObjectName(QStringLiteral("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(10, 20, 161, 215));
        horizontalLayout_5 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        flightStage1_checkBox = new QCheckBox(horizontalLayoutWidget_3);
        flightStage1_checkBox->setObjectName(QStringLiteral("flightStage1_checkBox"));
        flightStage1_checkBox->setEnabled(false);
        flightStage1_checkBox->setCheckable(true);
        flightStage1_checkBox->setChecked(false);

        verticalLayout->addWidget(flightStage1_checkBox);

        flightStage2_checkBox = new QCheckBox(horizontalLayoutWidget_3);
        flightStage2_checkBox->setObjectName(QStringLiteral("flightStage2_checkBox"));
        flightStage2_checkBox->setEnabled(false);
        flightStage2_checkBox->setCheckable(true);

        verticalLayout->addWidget(flightStage2_checkBox);

        flightStage3_checkBox = new QCheckBox(horizontalLayoutWidget_3);
        flightStage3_checkBox->setObjectName(QStringLiteral("flightStage3_checkBox"));
        flightStage3_checkBox->setEnabled(false);
        flightStage3_checkBox->setCheckable(true);

        verticalLayout->addWidget(flightStage3_checkBox);

        flightStage4_checkBox = new QCheckBox(horizontalLayoutWidget_3);
        flightStage4_checkBox->setObjectName(QStringLiteral("flightStage4_checkBox"));
        flightStage4_checkBox->setEnabled(false);
        flightStage4_checkBox->setCheckable(true);

        verticalLayout->addWidget(flightStage4_checkBox);

        line_8 = new QFrame(horizontalLayoutWidget_3);
        line_8->setObjectName(QStringLiteral("line_8"));
        line_8->setFrameShape(QFrame::HLine);
        line_8->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_8);

        label_23 = new QLabel(horizontalLayoutWidget_3);
        label_23->setObjectName(QStringLiteral("label_23"));

        verticalLayout->addWidget(label_23);

        failure1_checkBox = new QCheckBox(horizontalLayoutWidget_3);
        failure1_checkBox->setObjectName(QStringLiteral("failure1_checkBox"));
        failure1_checkBox->setEnabled(false);
        failure1_checkBox->setCheckable(true);

        verticalLayout->addWidget(failure1_checkBox);

        failure2_checkBox = new QCheckBox(horizontalLayoutWidget_3);
        failure2_checkBox->setObjectName(QStringLiteral("failure2_checkBox"));
        failure2_checkBox->setEnabled(false);
        failure2_checkBox->setCheckable(true);

        verticalLayout->addWidget(failure2_checkBox);


        horizontalLayout_5->addLayout(verticalLayout);

        groupBox_11 = new QGroupBox(groupBox_4);
        groupBox_11->setObjectName(QStringLiteral("groupBox_11"));
        groupBox_11->setEnabled(true);
        groupBox_11->setGeometry(QRect(10, 398, 141, 80));
        verticalLayoutWidget = new QWidget(groupBox_11);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(5, 19, 131, 55));
        verticalLayout_9 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(0, 0, 0, 0);
        progressBar = new QProgressBar(verticalLayoutWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setEnabled(true);
        progressBar->setValue(0);

        verticalLayout_9->addWidget(progressBar);

        timeEdit = new QTimeEdit(verticalLayoutWidget);
        timeEdit->setObjectName(QStringLiteral("timeEdit"));
        timeEdit->setEnabled(true);
        timeEdit->setAlignment(Qt::AlignCenter);
        timeEdit->setReadOnly(true);
        timeEdit->setButtonSymbols(QAbstractSpinBox::NoButtons);

        verticalLayout_9->addWidget(timeEdit);


        gridLayout_3->addWidget(groupBox_4, 0, 1, 1, 1);

        Tabs->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        groupBox = new QGroupBox(tab_2);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 291, 101));
        groupBox_2 = new QGroupBox(tab_2);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 120, 391, 121));
        listOfDevicesGS_comboBox = new QComboBox(groupBox_2);
        listOfDevicesGS_comboBox->setObjectName(QStringLiteral("listOfDevicesGS_comboBox"));
        listOfDevicesGS_comboBox->setGeometry(QRect(100, 25, 201, 22));
        label_26 = new QLabel(groupBox_2);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setGeometry(QRect(8, 28, 91, 16));
        searchGS_pushButton = new QPushButton(groupBox_2);
        searchGS_pushButton->setObjectName(QStringLiteral("searchGS_pushButton"));
        searchGS_pushButton->setGeometry(QRect(104, 56, 93, 28));
        connectGS_pushButton = new QPushButton(groupBox_2);
        connectGS_pushButton->setObjectName(QStringLiteral("connectGS_pushButton"));
        connectGS_pushButton->setGeometry(QRect(6, 56, 93, 28));
        gs_arduino_state_label = new QLabel(groupBox_2);
        gs_arduino_state_label->setObjectName(QStringLiteral("gs_arduino_state_label"));
        gs_arduino_state_label->setGeometry(QRect(309, 28, 61, 16));
        endConnectGS_pushButton = new QPushButton(groupBox_2);
        endConnectGS_pushButton->setObjectName(QStringLiteral("endConnectGS_pushButton"));
        endConnectGS_pushButton->setGeometry(QRect(201, 56, 101, 28));
        layoutWidget4 = new QWidget(groupBox_2);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(10, 90, 151, 18));
        formLayout = new QFormLayout(layoutWidget4);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_27 = new QLabel(layoutWidget4);
        label_27->setObjectName(QStringLiteral("label_27"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_27);

        connectionStateGS_label = new QLabel(layoutWidget4);
        connectionStateGS_label->setObjectName(QStringLiteral("connectionStateGS_label"));

        formLayout->setWidget(0, QFormLayout::FieldRole, connectionStateGS_label);

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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Sieniu_34 CanSat control panel", nullptr));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Measurements", nullptr));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "Falling velocity [m/s]", nullptr));
        groupBox_8->setTitle(QApplication::translate("MainWindow", "CanSat altitude", nullptr));
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
        label_5->setText(QApplication::translate("MainWindow", "Relative humidity:", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "Ionizing radiation:", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "PM 2.5:", nullptr));
        humid_lineEdit->setText(QApplication::translate("MainWindow", "0 %", nullptr));
        ionRad_lineEdit->setText(QApplication::translate("MainWindow", "0 msv/h", nullptr));
        pm_lineEdit->setText(QApplication::translate("MainWindow", "0 \316\274m", nullptr));
        voltage_lineEdit->setText(QApplication::translate("MainWindow", "0 V", nullptr));
        label_13->setText(QApplication::translate("MainWindow", "Altitude:", nullptr));
        alt_lineEdit->setText(QApplication::translate("MainWindow", "0 m", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "Voltage:", nullptr));
        label_24->setText(QApplication::translate("MainWindow", "Angular speed:", nullptr));
        ang_speed_lineEdit->setText(QApplication::translate("MainWindow", "0 \302\260/s", nullptr));
        label_25->setText(QApplication::translate("MainWindow", "Heading:", nullptr));
        heading_lineEdit->setText(QApplication::translate("MainWindow", "0 \302\260", nullptr));
        chartsShow_pushButton->setText(QApplication::translate("MainWindow", "Show dynamic charts", nullptr));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Live settings", nullptr));
        groupBox_6->setTitle(QApplication::translate("MainWindow", "Communication", nullptr));
        CSautoPower_checkBox->setText(QApplication::translate("MainWindow", "CS APC", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "CanSat baud rate:", nullptr));
        cansatBaudRate->setText(QApplication::translate("MainWindow", "1200 kbps", nullptr));
        CSpowerButtonMode1->setText(QApplication::translate("MainWindow", "27 dBm", nullptr));
        CSpowerButtonMode2->setText(QApplication::translate("MainWindow", "24 dBm", nullptr));
        CSpowerButtonMode3->setText(QApplication::translate("MainWindow", "21 dBm", nullptr));
        CSpowerButtonMode4->setText(QApplication::translate("MainWindow", "18 dBm", nullptr));
        cansatPower1->setText(QString());
        cansatPower2->setText(QString());
        cansatPower3->setText(QString());
        cansatPower4->setText(QString());
        label_19->setText(QApplication::translate("MainWindow", "PPS:", nullptr));
        PPS_lineEdit->setText(QApplication::translate("MainWindow", "0", nullptr));
        label_20->setText(QApplication::translate("MainWindow", "Packets sent:", nullptr));
        PacketsSent_lineEdit->setText(QApplication::translate("MainWindow", "0", nullptr));
        label_21->setText(QApplication::translate("MainWindow", "Packets recieved:", nullptr));
        PacketsRecieved_lineEdit->setText(QApplication::translate("MainWindow", "0", nullptr));
        GSpowerButtonMode1->setText(QApplication::translate("MainWindow", "27 dBm", nullptr));
        GSpowerButtonMode2->setText(QApplication::translate("MainWindow", "24 dBm", nullptr));
        GSpowerButtonMode3->setText(QApplication::translate("MainWindow", "21 dBm", nullptr));
        GSpowerButtonMode4->setText(QApplication::translate("MainWindow", "18 dBm", nullptr));
        cansatPower1_2->setText(QString());
        cansatPower2_2->setText(QString());
        cansatPower3_2->setText(QString());
        cansatPower4_2->setText(QString());
        label_12->setText(QApplication::translate("MainWindow", "CanSat", nullptr));
        label_18->setText(QApplication::translate("MainWindow", "Ground station", nullptr));
        GSautoPower_checkBox->setText(QApplication::translate("MainWindow", "GS APC", nullptr));
        groupBox_7->setTitle(QApplication::translate("MainWindow", "Working mode", nullptr));
        wMode1_button->setText(QApplication::translate("MainWindow", "Before start", nullptr));
        wMode2_button->setText(QApplication::translate("MainWindow", "CanSat main mission", nullptr));
        wMode3_button->setText(QApplication::translate("MainWindow", "Searching for CanSat", nullptr));
        radioButton->setText(QString());
        radioButton_2->setText(QString());
        radioButton_3->setText(QString());
        groupBox_10->setTitle(QApplication::translate("MainWindow", "Estimated flight stages", nullptr));
        flightStage1_checkBox->setText(QApplication::translate("MainWindow", "Liftoff", nullptr));
        flightStage2_checkBox->setText(QApplication::translate("MainWindow", "CanSat release", nullptr));
        flightStage3_checkBox->setText(QApplication::translate("MainWindow", "Parachute is working", nullptr));
        flightStage4_checkBox->setText(QApplication::translate("MainWindow", "Touchdown", nullptr));
        label_23->setText(QApplication::translate("MainWindow", "Possible failures:", nullptr));
        failure1_checkBox->setText(QApplication::translate("MainWindow", "Too high falling speed", nullptr));
        failure2_checkBox->setText(QApplication::translate("MainWindow", "Too low falling speed", nullptr));
        groupBox_11->setTitle(QApplication::translate("MainWindow", "Estimated touchdown", nullptr));
        Tabs->setTabText(Tabs->indexOf(tab), QApplication::translate("MainWindow", "General", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "Communication", nullptr));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Connection with ground station", nullptr));
        label_26->setText(QApplication::translate("MainWindow", "List of devices:", nullptr));
        searchGS_pushButton->setText(QApplication::translate("MainWindow", "Search", nullptr));
        connectGS_pushButton->setText(QApplication::translate("MainWindow", "Connect", nullptr));
        gs_arduino_state_label->setText(QApplication::translate("MainWindow", "Not found", nullptr));
        endConnectGS_pushButton->setText(QApplication::translate("MainWindow", "End connection", nullptr));
        label_27->setText(QApplication::translate("MainWindow", "State:", nullptr));
        connectionStateGS_label->setText(QApplication::translate("MainWindow", "Not connected", nullptr));
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
