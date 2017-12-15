// komunikacja.h
// Date: 15.12.2017r.
// Author: Jan Wielgus
//

#ifndef _KOMUNIKACJA_h
#define _KOMUNIKACJA_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include <PacketSerial.h>

//-------Pami�taj o zmianie wielko�ci ramek po zmianie protoko�u!!!-------
	#define serialNaPakietyCom Serial
	#define serialPortCom 0	//Serial: 0, Serial1: 1, Serial2: 2, Serial3: 3
	#define COM_BAUD_RATE 9600
	#define COM_MAX_SEND_SIZE 30

// --- ramki ---
	// odbieranie
		#define KOMUN_RAMKA_PC_1_SIZE 5
		#define KOMUN_RAMKA_PC_1_TYPE 0x00

		#define KOMUN_RAMKA_PC_2_SIZE 30
		#define KOMUN_RAMKA_PC_2_TYPE 0x01
	// wysy�anie
		#define KOMUN_RAMKA_ARDU_1_SIZE 5
		#define KOMUN_RAMKA_ARDU_1_TYPE 0x05

		#define KOMUN_RAMKA_ARDU_2_SIZE 30
		#define KOMUN_RAMKA_ARDU_2_TYPE 0x06



class KomunikacjaClass
{
 private:
	PacketSerial pSerial;
	uint8_t buforT[COM_MAX_SEND_SIZE];
	
 public:
	void init();
	
	uint8_t testowa1=0;
	
	void wyslij(uint8_t typRamki);
	void odbierz();
	void odbierzPriv(const uint8_t* buffer, size_t size);
	bool sprawdzSumeKontr(const uint8_t* buffer, size_t manipPacketSize);	//xor'owanie
	uint8_t liczSumeKontr(const uint8_t* buffer, size_t manipPacketSize);
};

extern KomunikacjaClass komun;

#endif

