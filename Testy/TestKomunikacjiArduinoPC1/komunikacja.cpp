// Date: 15.12.2017r.
// Author: Jan Wielgus
// 

#include "komunikacja.h"

void _protOdbierz(const uint8_t* buffer, size_t size)
{
	komun.odbierzPriv(buffer, size);
	//komun.wyslij(KOMUN_RAMKA_ARDU_1_TYPE);
}




void KomunikacjaClass::init()
{
	pSerial.setPacketHandler(_protOdbierz);
	pSerial.begin(COM_BAUD_RATE, serialPortCom);
}



void KomunikacjaClass::odbierz()
{
	pSerial.update();
}



void KomunikacjaClass::odbierzPriv(const uint8_t* bufferR, size_t PacketSize)
{
	if (bufferR[1] == KOMUN_RAMKA_PC_1_TYPE && PacketSize == KOMUN_RAMKA_PC_1_SIZE && sprawdzSumeKontr(bufferR, PacketSize))
	{
		// odbieranie kolejnych zmeinnych
	}
	
	else if (bufferR[1] == KOMUN_RAMKA_PC_2_TYPE && PacketSize == KOMUN_RAMKA_PC_2_SIZE && sprawdzSumeKontr(bufferR, PacketSize))
	{
		// odbieranie kolejnych zmeinnych
	}
}



void KomunikacjaClass::wyslij(uint8_t typRamki)
{
	buforT[1] = typRamki;
	
	if (typRamki == KOMUN_RAMKA_ARDU_1_TYPE)
	{
		// przypisanie zmiennych do tablicy buforT
		buforT[2] = 5;
		buforT[3] = 4;
		buforT[4] = 78;
		
		buforT[0] = liczSumeKontr(buforT, KOMUN_RAMKA_ARDU_1_SIZE);
		pSerial.send(buforT, KOMUN_RAMKA_ARDU_1_SIZE);
	}
	
	else if (typRamki == KOMUN_RAMKA_ARDU_2_TYPE)
	{
		// przypisanie zmiennych do tablicy buforT
		
		buforT[0] = liczSumeKontr(buforT, KOMUN_RAMKA_ARDU_2_SIZE);
		pSerial.send(buforT, KOMUN_RAMKA_ARDU_2_SIZE);
	}
}



bool KomunikacjaClass::sprawdzSumeKontr(const uint8_t* buffer, size_t packetSize)
{
	uint8_t suma_kontrolna = buffer[1];
	for(int i=2; i<packetSize; i++)
	suma_kontrolna ^= buffer[i];	//xor'owanie kolejnych bajt?w

	if(suma_kontrolna==buffer[0]) return true;
	else return false;
}



uint8_t KomunikacjaClass::liczSumeKontr(const uint8_t* buffer, size_t packetSize)
{
	uint8_t suma_kontrolna = buffer[1];
	for(int i=2; i<packetSize; i++)
	suma_kontrolna ^= buffer[i];	//xor'owanie kolejnych bajt?w

	return suma_kontrolna;
}


KomunikacjaClass komun;

