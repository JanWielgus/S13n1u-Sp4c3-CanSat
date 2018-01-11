/*
	Created: 11.01.2018r.
	Author: Jan Wielgus
	
	Main program of Sieniu_34 CanSat.
*/

#include "Supervisor.h"
#include "Communication.h"
#include "Sensors.h"

//HighTask co 50ms	 (max. 10 funkcji)
//MidTask co 200ms	 (max. 10 funkcji)
//LowsTask co 2000ms (max. 4 funkcje)


void setup()
{
	Tasker.init();
	superv.init();
	com.init();
	sensor.init();
	
	#ifdef _INO_DEBUG
		Serial.begin(9600);
	#endif
	
	Tasker.dodajHighTask(recieve);
	Tasker.dodajHighTask(send);
	Tasker.dodajHighTask(getSensorsValues);
}

void loop()
{
	// Kod wykonywany w tle poza zadaniami
}

//////////////////////////////////////////////////////////////////////////


void recieve()
{
	// kod odbierania
}


void send()
{
	// kod wysylania
}


void getSensorsValues()
{
	// kod pobiernia danych z czujnikow
}
