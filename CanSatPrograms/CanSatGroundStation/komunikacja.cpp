// Date: 15.12.2017r.
// Author: Jan Wielgus
// 

#include "komunikacja.h"

void _protOdbierz(const uint8_t* buffer, size_t size)
{
	komun.odbierzPriv(buffer, size);
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
		receivedBooleans1.bajt = bufferR[2];
		receivedBooleans2.bajt = bufferR[3];
	}
	
	else if (bufferR[1] == KOMUN_RAMKA_PC_2_TYPE && PacketSize == KOMUN_RAMKA_PC_2_SIZE && sprawdzSumeKontr(bufferR, PacketSize))
	{
		// odbieranie kolejnych zmiennych
	}
}



void KomunikacjaClass::wyslij(uint8_t typRamki)
{
	buforT[1] = typRamki;
	
	if (typRamki == KOMUN_RAMKA_ARDU_1_TYPE)
	{
		//buforT[2] = cscom.booleans1.bajt;
		buforT[2] = 59;
		buforT[3] = cscom.booleans2.bajt;
		buforT[4] = cscom.booleans3.bajt;
		buforT[5] = cscom.temperature;
		buforT[6] = cscom.pressure.bajt[0];
		buforT[7] = cscom.pressure.bajt[1];
		buforT[8] = cscom.pressure.bajt[2];
		buforT[9] = cscom.pressure.bajt[3];
		buforT[10] = cscom.gpsX.bajt[0];
		buforT[11] = cscom.gpsX.bajt[1];
		buforT[12] = cscom.gpsX.bajt[2];
		buforT[13] = cscom.gpsX.bajt[3];
		buforT[14] = cscom.gpsY.bajt[0];
		buforT[15] = cscom.gpsY.bajt[1];
		buforT[16] = cscom.gpsY.bajt[2];
		buforT[17] = cscom.gpsY.bajt[3];
		buforT[18] = cscom.carbDiOx;
		buforT[19] = cscom.tVOC;
		buforT[20] = cscom.humid;
		buforT[21] = cscom.ionRadiation;
		buforT[22] = cscom.pm25parts;
		buforT[23] = cscom.voltage;
		buforT[24] = cscom.headingComp;
		buforT[25] = cscom.headingComp;
		buforT[26] = radialVelocity;
		buforT[27] = fallingVelocity;
		buforT[28] = cscom.roll;
		buforT[29] = cscom.pitch;
		buforT[30] = pacPerSec;
		buforT[31] = avPacPerSec;
		buforT[32] = lowByte(packetsSent);
		buforT[33] = highByte(packetsSent);
		buforT[34] = lowByte(packetsReceived);
		buforT[35] = highByte(packetsReceived);
		buforT[36] = estTouchdown;
		
				
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

