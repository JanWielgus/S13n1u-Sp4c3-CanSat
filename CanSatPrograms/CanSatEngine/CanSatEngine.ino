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
void run_program();
void recieve();
void send();
void updateSensorsValues();



// variables
bool readyToSend = false; // to send every second function run
uint8_t run_counter = 1;  // to run program 5 times/sec




void setup()
{
	Tasker.init();
	com.init();
	sensor.init();
	
	#ifdef _INO_DEBUG
		Serial.begin(9600);
		Serial.println("Program has just started");
	#endif
	
	Tasker.dodajHighTask(run_program);
}

void loop()
{
	// Code run in background
	
	
	// Run tasker
	Tasker.wykonajZadania();
}

//////////////////////////////////////////////////////////////////////////


void run_program()
{
	// run this functions 5 times/sec
	if (run_counter == 4)
	{
		recieve();
		updateSensorsValues();
		send();
		
		run_counter = 1;
	}
	else run_counter++;
}


void recieve()
{
	// Recieving part ...
	
	
	
	// ... then set everything after
		// like transmit power etc.
	
}


void send()
{
	// Sending every second run of function (2.5 times/s)
	if (readyToSend)
	{
		// Sending part
		
		readyToSend = false;
	}
	else readyToSend = true;
}


void updateSensorsValues()
{
	sensor.readAngles();
	sensor.readPressure();
	sensor.readTemperature();
	sensor.readPosition();
	sensor.readCO2();
	sensor.readtVOC();
	sensor.readRelativeHumid();
	sensor.readIonizingRadiation();
	sensor.readPM25();
	sensor.readVoltage();
	sensor.readHeading();
	
	sensor.saveLogData();
}

