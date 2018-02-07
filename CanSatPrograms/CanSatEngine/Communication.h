// Communication.h
// Created: 11.01.2018r.
// Author: Jan Wielgus

#ifndef _COMMUNICATION_h
#define _COMMUNICATION_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include <PacketSerial.h>
#include "typyBitowe.h"
#include "config.h"


class CommunicationClass
{
// ===== FUNCTIONS & OTHERS =====
	
 private:
	PacketSerial pSerial;
	uint8_t buforT[MAX_SEND_SIZE];
	
 public:
	CommunicationClass();
	void init();
	void odbierz();
	void odbierzPriv(const uint8_t* buffer, size_t size);
	void wyslij(uint8_t typRamki);
	bool connectionState();                                    // true - is; false - isn't
	
	void setTransmitPower(bool b1, bool b2);    // set transmitting power
	void setWorkingMode(bool b1, bool b2);
	void setOTASpeed(bool b1);                      // set the Over The Air spped (in kbps)
	void autoTransmitPower();                       // if CanSat have to decide automaticly
	void writeParamsToTransciever();                // write parameters to transciever
	
 private:
	bool sprawdzSumeKontr(const uint8_t* buffer, size_t manipPacketSize); //xor'owanie
	uint8_t liczSumeKontr(const uint8_t* buffer, size_t manipPacketSize);
	
	
// ===== VARIABLES =====
 public:
	uint8_t head;
	uint8_t addh;
	uint8_t addl;
	bitByte sped;
	bitByte chan;
	bitByte option;
	
	
 private:
	uint16_t lost_packets;
	bool if_odbierzPriv;
};

extern CommunicationClass com;

#endif

