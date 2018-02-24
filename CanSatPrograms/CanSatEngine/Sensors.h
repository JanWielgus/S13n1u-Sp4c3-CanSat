// Sensors.h
// Created: 11.01.2018r.
// Author: Jan Wielgus

#ifndef _SENSORS_h
#define _SENSORS_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include <I2Cdev.h>
#include <Wire.h>
#include <TinyGPS++.h>
#include <SparkFunBME280.h>
#include <SparkFunCCS811.h>
#include "myMPU6050.h"
#include "config.h"
#include "typyBitowe.h"


class SensorsClass
{
// ===== FUNCTIONS & OTHERS =====

 private:
	MyMPU6050Class mpu;
	TinyGPSPlus tGPS;
	CCS811* ccs811;
	BME280 myBME280;
	
 public:
	SensorsClass();
	void init();
	
	// sensors data read
	void readAngles(); // roll, pitch, yaw
	void readPressure();
	void readTemperature();
	void readPosition();
	void readCCS811BME280(); // CO2, tVOC, relative humid in one
	void readIonizingRadiation();
	void readPM25();
	void readVoltage();
	void readHeading();
	
	// OpenLog
	void saveLogData();            // save list of data on sd card as backup
	
	// to send, to save transmitted data
	uint16_t compressPressure(float pres);
	uint8_t compressHeading(float head);
	uint16_t compressOneCoord(float coord);  // parameter: gpsX or gpsY, return: compressed version
	
	
	
// ===== VARIABLES =====    ( IF NOT SEND, LOG IT ON SD CARD !!! )
	
	struct //ypr_angles
	{
		float pitch;
		float roll;
		float yaw;
	}DMPang;
	
	floatByte pressure;
	float pressureBME;
	uint16_t pressureComp;         // Compressed version, to send (or send full version)
	
	uint8_t temperature;           // (send)
	float temperatureFloat;
	
	uint8_t carbDiOx;              // CO2 (send)
	uint16_t CO2int16;             // original size value
	uint8_t tVOC;                  // (send)
	uint16_t tVOCint16;            // original size value
	uint8_t humid;                 // (send)
	float humidFloat;              // original size value
	
	uint8_t ionRadiation;          // Ionizing radiation (send)
	uint8_t pm25parts;             // PM2.5 (send)
	uint8_t voltage;               // (send)
	floatByte heading;
	uint8_t headingComp;           // Compressed version (send)
	floatByte gpsX;                // (send)
	floatByte gpsY;                // (send)
	
	float altitudeGPS;
	float speedGPS;
  
	
 
 
 
// ===== FROM ORIGINAL MPU =====

 public:
	volatile bool mpuInterrupt = false;     // indicates whether MPU interrupt pin has gone high
	
 private:
	// MPU control/status vars
	bool dmpReady = false;  // set true if DMP init was successful
	uint8_t mpuIntStatus;   // holds actual interrupt status byte from MPU
	uint8_t devStatus;      // return status after each device operation (0 = success, !0 = error)
	uint16_t packetSize;    // expected DMP packet size (default is 42 bytes)
	uint16_t fifoCount;     // count of all bytes currently in FIFO
	uint8_t fifoBuffer[64]; // FIFO storage buffer
	
	// orientation/motion vars
	Quaternion q;           // [w, x, y, z]         quaternion container
	VectorFloat gravity;    // [x, y, z]            gravity vector
	float ypr[3];           // [yaw, pitch, roll]   yaw/pitch/roll container and gravity vector
};

extern SensorsClass sensor;

#endif

