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
uint8_t lpc_counter = 1; // Low Power Comsumption - to run sending 0.5 time/sec




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
	com.odbierz();
	
	
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
		// something if is no connection
		
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
	// Data read every run
	sensor.readPressure();
	sensor.readTemperature();
	sensor.readVoltage();
	
	uint8_t wmode = com.workingMode;
	
	if (wmode == MAINMISSION_MODE || wmode == NORMCOM_MODE)
	{
		sensor.nowTime = millis();
		sensor.readAngles();
		sensor.readPosition();
		sensor.readCCS811BME280();
		sensor.readIonizingRadiation();
		sensor.readPM25();
		sensor.readHeading();
		
		if (wmode == MAINMISSION_MODE)
			sensor.saveLogData();
	}
	else if (wmode == SEARCHING_MODE)
	{
		sensor.readPosition();
	}
	else // POWS_MODE
	{
		
	}
}



void send()
{
	// Sending every second run of function (2.5 times/s)
	if (readyToSend)
	{
		uint8_t wmode = com.workingMode;
		// Sending part
		if (wmode == POWS_MODE || wmode == SEARCHING_MODE)
		{
			switch (wmode)
			{
				case POWS_MODE:
					if (lpc_counter == 5)
					{
						//com.wyslij(0x02);
						lpc_counter = 1;
					}
					else
						lpc_counter++;
					break;
				
				case SEARCHING_MODE:
					//com.wyslij(0x01);
					break;
			}
				
		}
		else
		{
			com.getTransceiverParams(); // prepare current transceiver parameters to send
			
			// normal sending
			//com.wyslij(0x00);
			// if request for position -> also send(0x01) !!!
		}
		
		readyToSend = false;
	}
	else readyToSend = true;
}
