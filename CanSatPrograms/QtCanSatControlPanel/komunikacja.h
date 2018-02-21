#ifndef KOMUNIKACJA_H
#define KOMUNIKACJA_H

//#include <QObject>
//#include <QWidget>
#include "PacketSerial.h"
#include <QtSerialPort/QSerialPort>
#include <QByteArray>
#include "typyBitowe.h"


class Komunikacja
{
public:
    Komunikacja();

    QSerialPort* arduino;
    PacketSerial* pSerial;
    uint8_t* buforT;

    static const quint16 arduino_uno_vendor_id = 6790;
    static const quint16 arduino_uno_product_id = 29987;
    unsigned int il_odebranych;

    // --- ramki ---
    // wysylane
    const uint8_t KOMUN_RAMKA_PC_1_SIZE = 4;
    const uint8_t KOMUN_RAMKA_PC_1_TYPE = 0x00;

    const uint8_t KOMUN_RAMKA_PC_2_SIZE = 30;
    const uint8_t KOMUN_RAMKA_PC_2_TYPE = 0x01;
    // odbierane
    const uint8_t KOMUN_RAMKA_ARDU_1_SIZE = 37;
    const uint8_t KOMUN_RAMKA_ARDU_1_TYPE = 0x05;

    const uint8_t KOMUN_RAMKA_ARDU_2_SIZE = 30;
    const uint8_t KOMUN_RAMKA_ARDU_2_TYPE = 0x06;


    void odbierzPriv(const uint8_t* buffer, size_t size);
    void wyslij(uint8_t typRamki);
    bool sprawdzSumeKontr(const uint8_t* buffer, size_t PacketSize);	//xor'owanie
    uint8_t liczSumeKontr(const uint8_t* buffer, size_t PacketSize);
    void initialize(); // inicjalizacja
    void odbierz();

    uint8_t testowaTemp;

    uint8_t pitch;
    uint8_t roll;
    uint8_t yaw;
    floatByte pressure;
    uint16_t pressureComp;         // Compressed version, to send (or send full version)
    uint8_t temperature;
    uint8_t carbDiOx;              // CO2
    uint8_t tVOC;
    uint8_t humid;
    uint8_t ionRadiation;          // Ionizing radiation
    uint8_t pm25parts;             // PM2.5
    uint8_t voltage;
    floatByte heading;
    uint8_t headingComp;           // Compressed version, to send
    floatByte gpsX;
    floatByte gpsY;

    bitByte booleans1;
    bitByte booleans2;
    bitByte booleans3;

    uint8_t radialVelocity;
    uint8_t fallingVelocity;
    uint8_t pacPerSec;
    uint8_t avPacPerSec;
    uint16_t packetsSent;
    uint16_t packetsReceived;
    uint8_t estTouchdown;

    // to send
    bitByte booleansToSend1;
    bitByte booleansToSend2;
};

extern Komunikacja komun;

#endif // KOMUNIKACJA_H
