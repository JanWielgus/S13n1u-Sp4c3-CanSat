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
		
	}
	
	else if (b1 == 1 && b2 == 0)
	{
		// 21dBm
		
	}
	
	else if (b1 == 0 && b2 == 1)
	{
		// 24dBm
		
	}
	
	else
	{
		// 27dBm
		
	}
}



void CommunicationClass::setWorkingMode(bool b1, bool b2)
{
	if (b1 == 1 && b2 == 1)
	{
		// 4
		
	}
	
	else if (b1 == 1 && b2 == 0)
	{
		// 3
		
	}
	
	else if (b1 == 0 && b2 == 1)
	{
		// 2
		
	}
	
	else
	{
		// 1
		
	}
}



void CommunicationClass::setOTASpeed(bool b1)
{
	if (b1)
	{
		// 2.4kbps
		
	}
	
	else
	{
		// 1.2kbps
		
	}
}



void CommunicationClass::autoTransmitPower()
{
	return;
}



void CommunicationClass::writeParamsToTransciever()
{
	return;
}

