#include "okno.h"
#include "ui_okno.h"
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>
#include <string>
#include <QString>

//okno oknoclass;

void _protOdbierz(const uint8_t* buffer, size_t size)
{
    okno * oknoclass = new okno;
    oknoclass->odbierzPriv(buffer, size);
    delete oknoclass;
}



okno::okno(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::okno)
{
    ui->setupUi(this);

    arduino = new QSerialPort(this);
    pSerial = new PacketSerial; // Ewentualnie dać (this)  !!!
    buforT = new uint8_t[pSerial->MAX_SEND_SIZE];



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
            if((serialPortInfo.productIdentifier() == arduino_uno_product_id) && (serialPortInfo.vendorIdentifier() == arduino_uno_vendor_id))
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
        arduino->setPortName(arduino_uno_port_name);
        arduino->open(QSerialPort::ReadWrite);
        arduino->setBaudRate(QSerialPort::Baud9600);
        arduino->setDataBits(QSerialPort::Data8);
        arduino->setFlowControl(QSerialPort::NoFlowControl);
        arduino->setParity(QSerialPort::NoParity);
        arduino->setStopBits(QSerialPort::OneStop);
        QObject::connect(arduino, SIGNAL(readyRead()), this, SLOT(readSerial()));
    }
    else
    {
        qDebug() << "Couldn't find the correct port for the arduino.\n";
    }

    pSerial->setArduinoSerial(arduino);
    pSerial->setPacketHandler(_protOdbierz);
}

okno::~okno()
{
    if(arduino->isOpen())
    {
        arduino->close(); // Close the serial port if it's open.
    }

    delete ui;
}



void okno::readSerial()
{
    pSerial->update();
}



void okno::odbierzPriv(const uint8_t *bufferR, size_t PacketSize)
{
    qDebug() << "odbierzPriv :)";

    if (bufferR[1] == KOMUN_RAMKA_ARDU_1_TYPE && PacketSize == KOMUN_RAMKA_ARDU_1_SIZE && sprawdzSumeKontr(bufferR, PacketSize))
    {
        // costam = bufferR[2];
        // itd...
        // Jeżeli mniej niż ....size to zmniejszyć wielkość ....size
    }

    else if (bufferR[1] == KOMUN_RAMKA_ARDU_2_TYPE && PacketSize == KOMUN_RAMKA_ARDU_2_SIZE && sprawdzSumeKontr(bufferR, PacketSize))
    {
        // costam = bufferR[2];
        // itd...
        // Jeżeli mniej niż ....size to zmniejszyć wielkość ....size
    }
}



void okno::wyslij(uint8_t typRamki)
{
    buforT[1] = typRamki;

    if (typRamki == KOMUN_RAMKA_PC_1_TYPE)
    {
        // buforT[2] = costam;
        // itd...
        // pamiętać o wielkości!!!

        buforT[0] = liczSumeKontr(buforT, KOMUN_RAMKA_PC_1_SIZE);

        pSerial->send(buforT, KOMUN_RAMKA_PC_1_SIZE);
    }

    else if (typRamki == KOMUN_RAMKA_PC_2_TYPE)
    {
        // buforT[2] = costam;
        // itd...
        // pamiętać o wielkości!!!

        buforT[0] = liczSumeKontr(buforT, KOMUN_RAMKA_PC_1_SIZE);

        pSerial->send(buforT, KOMUN_RAMKA_PC_1_SIZE);
    }
}



bool okno::sprawdzSumeKontr(const uint8_t *buffer, size_t PacketSize)
{
    uint8_t suma_kontrolna = buffer[1];
    for(unsigned int i=2; i<PacketSize; i++)
    suma_kontrolna ^= buffer[i];	//xor'owanie kolejnych bajt?w

    if(suma_kontrolna==buffer[0]) return true;
    else return false;
}



uint8_t okno::liczSumeKontr(const uint8_t *buffer, size_t PacketSize)
{
    uint8_t suma_kontrolna = buffer[1];
    for(unsigned int i=2; i<PacketSize; i++)
    suma_kontrolna ^= buffer[i];	//xor'owanie kolejnych bajt?w

    return suma_kontrolna;
}


