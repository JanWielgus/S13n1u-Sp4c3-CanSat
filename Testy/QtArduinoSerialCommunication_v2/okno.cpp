#include "okno.h"
#include "ui_okno.h"
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>
#include <QString>

//okno oknoclass;



okno::okno(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::okno)
{
    ui->setupUi(this);

    komun.arduino = new QSerialPort(this);
    komun.pSerial = new PacketSerial; // Ewentualnie dać (this)  !!!
    komun.buforT = new uint8_t[komun.pSerial->MAX_SEND_SIZE];


    /*
     *  Testing code, prints the description, vendor id, and product id of all ports.
     *  Used it to determine the values for the arduino uno.
     *
    qDebug() << "Number of ports: " << QSerialPortInfo::availablePorts().length() << "\n";
    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts())
    {
        qDebug() << "Description: " << serialPortInfo.description() << "\n";
        qDebug() << "Has vendor id?: " << serialPortInfo.hasVendorIdentifier() << "\n";
        qDebug() << "Vendor ID: " << serialPortInfo.vendorIdentifier() << "\n";
        qDebug() << "Has product id?: " << serialPortInfo.hasProductIdentifier() << "\n";
        qDebug() << "Product ID: " << serialPortInfo.productIdentifier() << "\n";
    }
    */



    bool arduino_is_available = false;
    QString arduino_uno_port_name;
    //
    //  For each available serial port
    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts())
    {
        //  check if the serialport has both a product identifier and a vendor identifier
        if(serialPortInfo.hasProductIdentifier() && serialPortInfo.hasVendorIdentifier())
        {
            //  check if the product ID and the vendor ID match those of the arduino uno
            if((serialPortInfo.productIdentifier() == komun.arduino_uno_product_id) && (serialPortInfo.vendorIdentifier() == komun.arduino_uno_vendor_id))
            {
                arduino_is_available = true; //    arduino uno is available on this port
                arduino_uno_port_name = serialPortInfo.portName();
            }
        }
    }



    /*
     *  Open and configure the arduino port if available
     */
    if(arduino_is_available)
    {
        qDebug() << "Found the arduino port...\n";
        komun.arduino->setPortName(arduino_uno_port_name);
        komun.arduino->open(QSerialPort::ReadWrite);
        komun.arduino->setBaudRate(QSerialPort::Baud9600);
        komun.arduino->setDataBits(QSerialPort::Data8);
        komun.arduino->setFlowControl(QSerialPort::NoFlowControl);
        komun.arduino->setParity(QSerialPort::NoParity);
        komun.arduino->setStopBits(QSerialPort::OneStop);
        QObject::connect(komun.arduino, SIGNAL(readyRead()), this, SLOT(readSerial()));
    }
    else
    {
        qDebug() << "Couldn't find the correct port for the arduino.\n";
    }

    komun.initialize();
}

okno::~okno()
{
    if(komun.arduino->isOpen())
    {
        komun.arduino->close(); // Close the serial port if it's open.
    }

    delete ui;
}



void okno::readSerial()
{
    komun.odbierz();
    qDebug() << "Odebrano jakies dane\n";
}



void okno::on_testSendButton_clicked()
{
    komun.wyslij(komun.KOMUN_RAMKA_PC_1_TYPE);
    qDebug() << "Wyslano ramke testowa\n";
}
