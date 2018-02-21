// CanSatCommuniaction.h

#ifndef _CANSATCOMMUNIACTION_h
#define _CANSATCOMMUNIACTION_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include "typyBitowe.h"



class CanSatCommuniactionClass
{
 public:
	void init();
	
	
	
	uint8_t pitch;
	uint8_t roll;
	uint8_t yaw;
	floatByte pressure;
	uint16_t pressureComp;         // Compressed version, to send (or send full version)
	uint8_t temperature;
	uint8_t carbDiOx;              // CO2
	uint8_t tVOC;
	uint8_t humid;
	uint8_t ionRadiation;          // Ionizing radiation
	uint8_t pm25parts;             // PM2.5
	uint8_t voltage;
	floatByte heading;
	uint8_t headingComp;           // Compressed version, to send
	floatByte gpsX;
	floatByte gpsY;
	
	bitByte booleans1;
	bitByte booleans2;
	bitByte booleans3;
};

extern CanSatCommuniactionClass cscom;

#endif

