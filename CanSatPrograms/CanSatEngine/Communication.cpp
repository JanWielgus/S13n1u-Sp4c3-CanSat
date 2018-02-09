// Created: 11.01.2018r.
// Author: Jan Wielgus
// 

#include "Communication.h"

CommunicationClass com;

void _protezaOdbierz(const uint8_t* buffer, size_t _size)
{
	com.odbierzPriv(buffer, _size);
}



CommunicationClass::CommunicationClass()
{
	//defaults:
	lost_packets = 10;
}



void CommunicationClass::init()
{
	pSerial.setPacketHandler(_protezaOdbierz);
	pSerial.begin(BAUD_RATE, serialPort);
	
	// transciever deafult settings
	head        = 0xC0;
	addh        = 0x00;
	addl        = 0x00;
	sped.bajt   = 0x18;
	chan.bajt   = 0x50;
	option.bajt = 0x44;
	
	//default working mode
	workingMode = NORMCOM_MODE; // normal communication
}



void CommunicationClass::odbierz()
{
	if_odbierzPriv = false;
	
	pSerial.update();
	
	// check if connection lost
	if (if_odbierzPriv)
		lost_packets=0;
	else
		lost_packets++;
		
	if (!connectionState()) con_lost_time = millis();
}



void CommunicationClass::odbierzPriv(const uint8_t* bufferR, size_t PacketSize)
{
	//odbieranie do zmiennych
	
	
	if_odbierzPriv = true;
}



void CommunicationClass::wyslij(uint8_t typRamki)
{
	buforT[1] = typRamki;
	
	// zmienne do bufora
	//w kazdym if'ie bufor[0] i send
	
}



bool CommunicationClass::connectionState()
{
	if (lost_packets < MAX_LOST_PACKETS)
		return true;
	timeAfterSL = millis()-con_lost_time;
	return false; // otherwise
}



bool CommunicationClass::sprawdzSumeKontr(const uint8_t* buffer, size_t PacketSize)
{
	uint8_t suma_kontrolna = buffer[1];
	for(int i=2; i<PacketSize; i++)
	suma_kontrolna ^= buffer[i];	//xor'owanie kolejnych bajt?w

	if(suma_kontrolna==buffer[0]) return true;
	else return false;
}



uint8_t CommunicationClass::liczSumeKontr(const uint8_t* buffer, size_t PacketSize)
{
	uint8_t suma_kontrolna = buffer[1];
	for(int i=2; i<PacketSize; i++)
	suma_kontrolna ^= buffer[i];	//xor'owanie kolejnych bajt?w

	return suma_kontrolna;
}



void CommunicationClass::setTransmitPower(bool b1, bool b2)
{
	if (b1 == 1 && b2 == 1)
	{
		// 18dBm
		option.b6 = 1;
		option.b7 = 1;
	}
	
	else if (b1 == 1 && b2 == 0)
	{
		// 21dBm
		option.b6 = 1;
		option.b7 = 0;
	}
	
	else if (b1 == 0 && b2 == 1)
	{
		// 24dBm
		option.b6 = 0;
		option.b7 = 1;
	}
	
	else
	{
		// 27dBm
		option.b6 = 0;
		option.b7 = 0;
	}
}



// overloaded
void CommunicationClass::setTransmitPower(uint8_t power)
{
	switch (power)
	{
		case DBM18:
			setTransmitPower(1, 1);
			break;
		case DBM21:
			setTransmitPower(1, 0);
			break;
		case DBM24:
			setTransmitPower(0, 1);
			break;
		case DBM27:
			setTransmitPower(0, 0);
			break;
		default:
			setTransmitPower(1, 1);
	}
}



// overloaded
void CommunicationClass::setTransmitPower()
{
	if (connectionState())
	{
		if (switchesR.b0 == 0)
		{
			// requested transmission power
			setTransmitPower(switchesR.b6, switchesR.b5);
		}
		else
		{
			// auto transmission power when signal is
			
		}
	}
	else
	{
		// auto transmit power when signal lost
		
		if (timeAfterSL < MP_SET_TIME)      // 0 < x < MP
			setTransmitPower(DBM21);
		else if (timeAfterSL < HP_SET_TIME) // MP < x < HP
			setTransmitPower(DBM24);
		else
			setTransmitPower(DBM27); // HP < x
	}
	
	// always if power save mode set transmit power to lowest
	if (workingMode == POWS_MODE) setTransmitPower(DBM18);
	//else if (workingMode == SEARCHING_MODE) setTransmitPower(DBM27);
}



void CommunicationClass::setWorkingMode(bool b1, bool b2)
{
	if (b1 == 1 && b2 == 1)
	{
		// 4 - Searching for CanSat
		workingMode = SEARCHING_MODE;
	}
	
	else if (b1 == 1 && b2 == 0)
	{
		// 3 - CanSat main mission
		workingMode = MAINMISSION_MODE;
	}
	
	else if (b1 == 0 && b2 == 1)
	{
		// 2 - Normal communication
		workingMode = NORMCOM_MODE;
	}
	
	else
	{
		// 1 - Power save mode
		workingMode = POWS_MODE;
	}
}



void CommunicationClass::setOTASpeed(bool b1)
{
	if (b1)
	{
		// 2.4kbps
		sped.b5 = 0;
		sped.b6 = 0;
		sped.b7 = 1;
	}
	
	else
	{
		// 1.2kbps
		sped.b5 = 0;
		sped.b6 = 0;
		sped.b7 = 0;
	}
}



void CommunicationClass::setFrequency(uint8_t freq)
{
	return;
}



void CommunicationClass::writeParamsToTransceiver()
{
	return;
}



void CommunicationClass::getTransceiverParams()
{
	// power
	settingsConfirmation.b7 = switchesR.b6;
	settingsConfirmation.b6 = switchesR.b5;
	
	// working modes
	settingsConfirmation.b5 = switchesR.b4;
	settingsConfirmation.b4 = switchesR.b3;
	
	// OTA speed
	settingsConfirmation.b3 = switchesR.b2;
}
