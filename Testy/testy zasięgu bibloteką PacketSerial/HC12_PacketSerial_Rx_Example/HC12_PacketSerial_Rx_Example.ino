//PacketSoftwareSerial

#include <PacketSerial.h>
#include <SoftwareSerial.h>
#include "typyBitowe.h"


//-------Pami�ta� o zmianie wielko�ci ramek po zmianie protoko�u!!!-------
#define BAUD_RATE 9600
#define MAX_SEND_SIZE 12

#define RAMKA_STER_SIZE 3
#define RAMKA_STER_TYPE 0x00

#define RAMKA_DANE_SIZE 4
#define RAMKA_DANE_TYPE 0x01

#define RAMKA_DRON_SIZE 6 //odebrane

#define tx_pin 2
#define rx_pin 3

PacketSerial pSerial;
uint8_t buforT[MAX_SEND_SIZE];
SoftwareSerial software_serial(tx_pin, rx_pin); // HC-12 TX Pin, HC-12 RX Pin


//odebrane
bitByte pong;
int zmienna1, zmienna2;

//wysy�ane
bitByte ping;

long czas_ostatniego_pong = 1000;
boolean ostatni_pong = false; //stan ostatniego odebranego pongu
boolean stan_sygnalu = false;




void setup()
{
	_init();
	Serial.begin(9600);
}

void loop()
{
	odbierz();
	
	if (pong.b0 != ostatni_pong)
	{
		ostatni_pong = pong.b0;
		czas_ostatniego_pong = millis();
	}
	
	if ((millis() - czas_ostatniego_pong) > 200) stan_sygnalu = false;
	else stan_sygnalu = true;
	
	ping.b0 = !ping.b0;
	
	//wyslij(RAMKA_STER_TYPE);
	
	Serial.print(zmienna1);
	Serial.print("\t");
	Serial.println(stan_sygnalu);
	
	delay(100);
}



void _protOdbierz(const uint8_t* buffer, size_t size)
{
	odbierzPriv(buffer, size);
}


void _init()
{
	pSerial.setPacketHandler(_protOdbierz);
	software_serial.begin(BAUD_RATE);
	pSerial.begin(&software_serial);
}


void odbierz()
{
	pSerial.update();
}


void odbierzPriv(const uint8_t* bufferR, size_t PacketSize)
{
	if (PacketSize == RAMKA_DRON_SIZE && sprawdzSumeKontr(bufferR, PacketSize))
	{
		zmienna1 = word(bufferR[2], bufferR[1]);
		zmienna2 = word(bufferR[4], bufferR[3]);
		pong.bajt = bufferR[5];
	}
}


void wyslij(uint8_t typRamki)
{
	buforT[1] = typRamki;
	
	if (typRamki == RAMKA_STER_TYPE)
	{
		buforT[2] = ping.bajt;
		
		
		buforT[0] = liczSumeKontr(buforT, RAMKA_DRON_SIZE);
		
		pSerial.send(buforT, RAMKA_DRON_SIZE);
	}
	
	else if (typRamki == RAMKA_DANE_TYPE)
	{
		/*
		buforT[2] = jakisOsiemTtx;
		buforT[3] = jakisBitByteTx;
		*/
	}
}


bool sprawdzSumeKontr(const uint8_t* buffer, size_t PacketSize)
{
	uint8_t suma_kontrolna = buffer[1];
	for(int i=2; i<PacketSize; i++)
	suma_kontrolna ^= buffer[i];	//xor'owanie kolejnych bajt�w

	if(suma_kontrolna==buffer[0]) return true;
	else return false;
}

uint8_t liczSumeKontr(const uint8_t* buffer, size_t PacketSize)
{
	uint8_t suma_kontrolna = buffer[1];
	for(int i=2; i<PacketSize; i++)
	suma_kontrolna ^= buffer[i];	//xor'owanie kolejnych bajt�w

	return suma_kontrolna;
}

