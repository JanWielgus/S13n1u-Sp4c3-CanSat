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
#include "CanSatCommuniaction.h"

//-------Pamiêtaj o zmianie wielkoœci ramek po zmianie protoko³u!!!-------
	#define serialNaPakietyCom Serial
	#define serialPortCom 0	//Serial: 0, Serial1: 1, Serial2: 2, Serial3: 3
	#define COM_BAUD_RATE 9600
	#define COM_MAX_SEND_SIZE 40

// --- ramki ---
	// odbieranie
		#define KOMUN_RAMKA_PC_1_SIZE 4
		#define KOMUN_RAMKA_PC_1_TYPE 0x00

		#define KOMUN_RAMKA_PC_2_SIZE 30
		#define KOMUN_RAMKA_PC_2_TYPE 0x01
	// wysy³anie
		#define KOMUN_RAMKA_ARDU_1_SIZE 37
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
	uint16_t counter1=0;
	
	void wyslij(uint8_t typRamki);
	void odbierz();
	void odbierzPriv(const uint8_t* buffer, size_t size);
	bool sprawdzSumeKontr(const uint8_t* buffer, size_t manipPacketSize);	//xor'owanie
	uint8_t liczSumeKontr(const uint8_t* buffer, size_t manipPacketSize);
	
	
	// calculated
	uint8_t radialVelocity;
	uint8_t fallingVelocity;
	uint8_t pacPerSec;
	uint8_t avPacPerSec;
	uint16_t packetsSent;
	uint16_t packetsReceived;
	uint8_t estTouchdown;
	
	bitByte receivedBooleans1;
	bitByte receivedBooleans2;
};

extern KomunikacjaClass komun;

#endif

