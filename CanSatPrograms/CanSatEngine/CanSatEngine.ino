/*
	Created: 11.01.2018r.
	Author: Jan Wielgus
	
	Main program of Sieniu_34 CanSat.
*/

#include "Communication.h"
#include "Sensors.h"
#include "GoodTasker.h"

//HighTask co 50ms	 (max. 10 funkcji)
//MidTask co 200ms	 (max. 10 funkcji)
//LowsTask co 2000ms (max. 4 funkcje)


// function prototypes
void recieve();
void send();
void getSensorsValues();

void setTransmittingPower(bool, bool);  // set transmitting power
void setWorkingMode(bool, bool);
void setOTASpeed(bool);                 // set the Over The Air spped (in kbps)
void autoSetTransmitPower();            // if CanSat have to decide automaticly

void writeParamsToTransciever();        // write parameters to transciever



// variables
bool readyToSend = false; // to send every second function run



// transciever setting bytes
uint8_t head = 0xC0;
uint8_t addh = 0x00;
uint8_t addl = 0x00;
uint8_t sped = 0x18;
uint8_t chan = 0x50;
uint8_t option = 0x44;




void setup()
{
	Tasker.init();
	com.init();
	sensor.init();
	
	#ifdef _INO_DEBUG
		Serial.begin(9600);
	#endif
	
	Tasker.dodajMidTask(recieve);
	Tasker.dodajMidTask(send);
	Tasker.dodajMidTask(getSensorsValues);
}

void loop()
{
	// Code run in background
}

//////////////////////////////////////////////////////////////////////////


void recieve()
{
	// Recieving part ...
	
	
	
	// ... then set everything after
	
	
}


void send()
{
	if (readyToSend)
	{
		// Sending part
		
		readyToSend = false;
	}
	else
	{
		readyToSend = true;
	}
}


void getSensorsValues()
{
	// kod pobiernia danych z czujnikow
}




void setTransmittingPower(bool b1, bool b2)
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


void setWorkingMode(bool b1, bool b2)
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


void setOTASpeed(bool b1)
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


void autoSetTransmitPower()
{
	//...
}


void writeParamsToTransciever()
{
	//...
}
