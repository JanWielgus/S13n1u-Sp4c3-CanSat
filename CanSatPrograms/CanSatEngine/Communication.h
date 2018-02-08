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
#include "Sensors.h"
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
	
	void setTransmitPower(bool b1, bool b2);        // set transmitting power depending on b1 and b2
	void setTransmitPower(uint8_t power)            // (overloaded) set transmitting power depending on program constans
	void setTransmitPower();                        // (overloaded) set transmit power (decision depending on connection state and request)
	void setWorkingMode(bool b1, bool b2);
	void setOTASpeed(bool b1);                      // set the Over The Air spped (in kbps)
	void setFrequency(uint8_t freq);                // set frequency
	//void autoTransmitPower();                       // if CanSat have to decide automaticly
	//void setDefaultTransceiverSettings();           // set default parameters of transceiver
	
	void writeParamsToTransceiver();                // write parameters to transceiver
	
	void getOTASpeed(bool* b1);
	void getTransmitPower(bool* b1, bool* b2);
	void getWorkingMode(bool* b1, bool* b2);
	
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
	
	uint8_t workingMode;         // 1-PSmode, 2-norm comun, 3-main mission, 4-searching
	
	uint32_t timeAfterSL;        // time form time communication was lost (UPDATED AFTER connectionState() !!!)
	
	
	// == SENT ==
	bitByte settingsConfirmation;        // booleany steruj¹ce
	// rest in Sensors class
	
	// == RECEIVED ==
	bitByte switchesR;                   // prze³¹czniki
	
	
	
 private:
	uint16_t lost_packets;       // number of lost packets
	bool if_odbierzPriv;         // true if odbierzPriv was called
	uint32_t con_lost_time;      // time when communication lost
};

extern CommunicationClass com;

#endif

