#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>
#include <QString>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    komun.arduino = new QSerialPort(this);
    komun.pSerial = new PacketSerial;
    komun.buforT = new uint8_t[komun.pSerial->MAX_SEND_SIZE];

    komun.initialize();

    // Nie dziala: QObject::connect(komun.arduino, SIGNAL(destroyed(QObject*)), this, SLOT(destroySerial())); // chodzi o rozlaczanie gdy wyjety kabel
    QObject::connect(komun.arduino, SIGNAL(readyRead()), this, SLOT(readSerial()));
}

MainWindow::~MainWindow()
{
    if (komun.arduino->isOpen())
    {
        komun.arduino->close(); // Close the serial port if it's open.
    }

    delete ui;
}



void MainWindow::readSerial()
{
    if (ui->connectionStateGS_label->text() == connectedText)
    {
        komun.odbierz();
        qDebug() << "Odebrano jakies dane\n";
    }
}


/*
void MainWindow::destroySerial()
{
    ui->listOfDevicesGS_comboBox->clear();
    ui->connectGS_pushButton->setDisabled(false);
    ui->connectionStateGS_label->setText(notConnectedText);
}
*/


void MainWindow::on_CSautoPower_checkBox_clicked()
{
    // Jesli auto sterowanie moca nadawania to manualane wylaczone
    if (ui->CSautoPower_checkBox->isChecked())
    {
        ui->CSpowerButtonMode1->setDisabled(true);
        ui->CSpowerButtonMode2->setDisabled(true);
        ui->CSpowerButtonMode3->setDisabled(true);
        ui->CSpowerButtonMode4->setDisabled(true);
    }
    else
    {
        ui->CSpowerButtonMode1->setDisabled(false);
        ui->CSpowerButtonMode2->setDisabled(false);
        ui->CSpowerButtonMode3->setDisabled(false);
        ui->CSpowerButtonMode4->setDisabled(false);
    }
}

void MainWindow::on_GSautoPower_checkBox_clicked()
{
    // Jesli auto sterowanie moca nadawania to manualane wylaczone
    if (ui->GSautoPower_checkBox->isChecked())
    {
        ui->GSpowerButtonMode1->setDisabled(true);
        ui->GSpowerButtonMode2->setDisabled(true);
        ui->GSpowerButtonMode3->setDisabled(true);
        ui->GSpowerButtonMode4->setDisabled(true);
    }
    else
    {
        ui->GSpowerButtonMode1->setDisabled(false);
        ui->GSpowerButtonMode2->setDisabled(false);
        ui->GSpowerButtonMode3->setDisabled(false);
        ui->GSpowerButtonMode4->setDisabled(false);
    }
}

void MainWindow::on_chartsShow_pushButton_clicked()
{
    dynCharts = new DynamicChartsWindow;
    dynCharts->show();
}

void MainWindow::on_searchGS_pushButton_clicked()
{
    ui->listOfDevicesGS_comboBox->clear();

    bool arduino_is_available = false;

    //  For each available serial port
    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts())
    {
        //  check if the serialport has both a product identifier and a vendor identifier
        if(serialPortInfo.hasProductIdentifier() && serialPortInfo.hasVendorIdentifier())
        {
            port_name = serialPortInfo.portName();
            ui->listOfDevicesGS_comboBox->addItem(port_name);

            //  check if the product ID and the vendor ID match those of the arduino uno
            if((serialPortInfo.productIdentifier() == komun.arduino_uno_product_id) && (serialPortInfo.vendorIdentifier() == komun.arduino_uno_vendor_id))
            {
                arduino_is_available = true; //    arduino uno is available on this port
                ui->gs_arduino_state_label->setText(foundText);
            }
        }
    }

    if (arduino_is_available == false)
        ui->gs_arduino_state_label->setText(notFoundText);
}

void MainWindow::on_connectGS_pushButton_clicked()
{
    // If arduino is not connected, then you can search
    if (ui->connectionStateGS_label->text() == notConnectedText)
    {
        // If something was selected on list of devices
        if (ui->listOfDevicesGS_comboBox->currentText() != "")
        {
            qDebug() << "Found the arduino port...\n";
            komun.arduino->setPortName(port_name);
            komun.arduino->open(QSerialPort::ReadWrite);
            komun.arduino->setBaudRate(QSerialPort::Baud9600);
            komun.arduino->setDataBits(QSerialPort::Data8);
            komun.arduino->setFlowControl(QSerialPort::NoFlowControl);
            komun.arduino->setParity(QSerialPort::NoParity);
            komun.arduino->setStopBits(QSerialPort::OneStop);

            ui->listOfDevicesGS_comboBox->clear();
            ui->gs_arduino_state_label->setText(notFoundText);
            ui->connectionStateGS_label->setText(connectedText);
            ui->connectGS_pushButton->setDisabled(true);
        }
        else
            qDebug() << "You don't have any devices to connect!\n";
    }
}

void MainWindow::on_endConnectGS_pushButton_clicked()
{
    // If is connected and could be closed
    if (ui->connectionStateGS_label->text() == connectedText)
    {
        if (komun.arduino->isOpen())
        {
            komun.arduino->close(); // Close the serial port if it's open.
        }

        ui->connectionStateGS_label->setText(notConnectedText);
        ui->connectGS_pushButton->setDisabled(false);
    }
}
