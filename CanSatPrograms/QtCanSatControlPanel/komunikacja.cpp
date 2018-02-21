#include "komunikacja.h"
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>
#include <QString>

Komunikacja komun;


void _protOdbierz(const uint8_t* _buffer, size_t _size)
{
    komun.odbierzPriv(_buffer, _size);
}

Komunikacja::Komunikacja()
{
    // nothing
}



void Komunikacja::initialize()
{
    pSerial->setArduinoSerial(arduino);
    pSerial->setPacketHandler(_protOdbierz);
}



void Komunikacja::odbierz()
{
    pSerial->update();
}



void Komunikacja::odbierzPriv(const uint8_t* bufferR, size_t PacketSize)
{
    if (bufferR[1] == KOMUN_RAMKA_ARDU_1_TYPE && PacketSize == KOMUN_RAMKA_ARDU_1_SIZE && sprawdzSumeKontr(bufferR, PacketSize))
    {
        //booleans1.bajt = bufferR[2];
        testowaTemp = bufferR[2];
        booleans2.bajt = bufferR[3];
        booleans3.bajt = bufferR[4];
        temperature = bufferR[5];
        pressure.bajt[0] = bufferR[6];
        pressure.bajt[1] = bufferR[7];
        pressure.bajt[2] = bufferR[8];
        pressure.bajt[3] = bufferR[9];
        gpsX.bajt[0] = bufferR[10];
        gpsX.bajt[1] = bufferR[11];
        gpsX.bajt[2] = bufferR[12];
        gpsX.bajt[3] = bufferR[13];
        gpsY.bajt[0] = bufferR[14];
        gpsY.bajt[1] = bufferR[15];
        gpsY.bajt[2] = bufferR[16];
        gpsY.bajt[3] = bufferR[17];
        carbDiOx = bufferR[18];
        tVOC = bufferR[19];
        humid = bufferR[20];
        ionRadiation = bufferR[21];
        pm25parts = bufferR[22];
        voltage = bufferR[23];
        headingComp = bufferR[24];
        headingComp = bufferR[25];
        radialVelocity = bufferR[26];
        fallingVelocity = bufferR[27];
        roll = bufferR[28];
        pitch = bufferR[29];
        pacPerSec = bufferR[30];
        avPacPerSec = bufferR[31];
        // low and high bytes int16
        estTouchdown = bufferR[36];

        il_odebranych = 37; // ustawić tyle ile odebrano (do obsługi protezy)
        qDebug() << "Rozkodowano ramkę mumer 1 od arduino :)" << bufferR[2] << " " << bufferR[3];

    }

    else if (bufferR[1] == KOMUN_RAMKA_ARDU_2_TYPE && PacketSize == KOMUN_RAMKA_ARDU_2_SIZE && sprawdzSumeKontr(bufferR, PacketSize))
    {
        // costam = bufferR[2];
        // itd...
        // Jeżeli mniej niż ....size to zmniejszyć wielkość ....size
        il_odebranych = 5; // ustawić tyle ile odebrano (do obsługi protezy)
    }
}



void Komunikacja::wyslij(uint8_t typRamki)
{
    buforT[1] = typRamki;

    if (typRamki == KOMUN_RAMKA_PC_1_TYPE)
    {
        buforT[2] = 5;
        buforT[3] = 77;
        buforT[4] = 78;
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



bool Komunikacja::sprawdzSumeKontr(const uint8_t *buffer, size_t PacketSize)
{
    uint8_t suma_kontrolna = buffer[1];
    for(unsigned int i=2; i<PacketSize; i++)
    suma_kontrolna ^= buffer[i];	//xor'owanie kolejnych bajt?w

    if(suma_kontrolna==buffer[0]) return true;
    else return false;
}



uint8_t Komunikacja::liczSumeKontr(const uint8_t *buffer, size_t PacketSize)
{
    uint8_t suma_kontrolna = buffer[1];
    for(unsigned int i=2; i<PacketSize; i++)
    suma_kontrolna ^= buffer[i];	//xor'owanie kolejnych bajt?w

    return suma_kontrolna;
}
