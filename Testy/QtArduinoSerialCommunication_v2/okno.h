#ifndef OKNO_H
#define OKNO_H

#include <QMainWindow>
#include "PacketSerial.h"
#include <QtSerialPort/QSerialPort>
#include <QByteArray>

namespace Ui {
class okno;
}

class okno : public QMainWindow
{
    Q_OBJECT

public:
    explicit okno(QWidget *parent = 0);
    ~okno();


public:
    Ui::okno *ui;

    QSerialPort *arduino;
    PacketSerial *pSerial;
    uint8_t *buforT;

    static const quint16 arduino_uno_vendor_id = 6790;
    static const quint16 arduino_uno_product_id = 29987;

// --- ramki ---
    // wysylane
    const uint8_t KOMUN_RAMKA_PC_1_SIZE = 5;
    const uint8_t KOMUN_RAMKA_PC_1_TYPE = 0x00;

    const uint8_t KOMUN_RAMKA_PC_2_SIZE = 30;
    const uint8_t KOMUN_RAMKA_PC_2_TYPE = 0x01;
    // odbierane
    const uint8_t KOMUN_RAMKA_ARDU_1_SIZE = 5;
    const uint8_t KOMUN_RAMKA_ARDU_1_TYPE = 0x05;

    const uint8_t KOMUN_RAMKA_ARDU_2_SIZE = 30;
    const uint8_t KOMUN_RAMKA_ARDU_2_TYPE = 0x06;


    void odbierzPriv(const uint8_t* buffer, size_t size);
    void wyslij(uint8_t typRamki);
    bool sprawdzSumeKontr(const uint8_t* buffer, size_t PacketSize);	//xor'owanie
    uint8_t liczSumeKontr(const uint8_t* buffer, size_t PacketSize);

private slots:
    void readSerial();
};

#endif // OKNO_H
