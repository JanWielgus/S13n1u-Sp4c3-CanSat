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
	// Recieving part
}


void send()
{
	// Sending part
}


void getSensorsValues()
{
	// kod pobiernia danych z czujnikow
}
