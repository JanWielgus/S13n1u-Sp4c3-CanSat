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
void run_program(); // this function run other functions 5 times/sec
void recieve();
void send();
void updateSensorsValues();



// variables
bool readyToSend = false; // to send every second function run
uint8_t run_counter = 1;  // to run program 5 times/sec




void setup()
{
	#ifdef _INO_DEBUG
		Serial.begin(9600);
		Serial.println("Program has just started");
	#endif
	
	Tasker.init();
	com.init();
	sensor.init();
	
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
		
	com.setTransmitPower();
	
	if (com.connectionState())
	{
		// something if is a connection
		
		com.setWorkingMode(com.switchesR.b4, com.switchesR.b3);
		com.setOTASpeed(com.switchesR.b2);
	}
	else
	{
		// something if isn't
		
		if (com.timeAfterSL > RESTORE_CONNECTION_PARAMS_TIME)
		{
			com.setOTASpeed(0); // 1.2kbps
			com.setFrequency(DEFAULT_FREQUENCY); // 433mHz
		}
	}
	
	com.writeParamsToTransceiver();
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



void send()
{
	// Read needed data before send
	
	com.getOTASpeed(&com.settingsConfirmation.b3);
	com.getTransmitPower(&com.settingsConfirmation.b7, &com.settingsConfirmation.b6);
	com.getWorkingMode(&com.settingsConfirmation.b5, &com.settingsConfirmation.b4);
	
	
	// Sending every second run of function (2.5 times/s)
	if (readyToSend)
	{
		// Sending part
		
		readyToSend = false;
	}
	else readyToSend = true;
}
