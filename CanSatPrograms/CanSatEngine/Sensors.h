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
#include <MS5611.h>
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
	MS5611 ms5611;
	
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
	float getAltitude(float press, float temp);
	void setSeaLevelPressure(float pres);
	
	
	
// ===== VARIABLES =====    ( IF NOT SEND, LOG IT ON SD CARD !!! )
// Pressure from MS5611 is long but from BME280 is float !

	// ====== MPU6050 ======
		struct //ypr_angles
		{
			float pitch;
			float roll;
			float yaw;
		}DMPang;
		// acceleration
		
	// ====== CCS811 ======
		uint16_t CO2;
		uint16_t tVOC;
	
	// ====== PMS5003 ======
		uint8_t pm25parts;             // PM2.5 (send)
		// Will be more variables in idk types
	
	// ====== BME280 ======
		float pressureBME;
		uint8_t temperatureBME;      // compressed
		float temperatureBMEFloat;   // full temperature
		uint8_t humidBME;            // compressed
		float humidBMEFloat;         // original size value
	
	// ====== HMC5883L ======
		floatByte heading;
		uint8_t headingComp; // Compressed version
	
	// ====== MS5611 ======
		int32Byte pressure_main;
		float temperatureBARO; // log
	
	// ====== UBLOX NEO6M ======
		int32Byte gpsX;
		int32Byte gpsY;
		float altitudeGPS;
		float speedGPS;
	
	// ====== ION RAD SENSOR ======
		int16_t ionRad;       // just from analogRead
		uint8_t ionRadComp;   // compressed version to send
	
	// ====== OTHER ======
	
	uint16_t pressureComp; // Compressed version, to send (or send full version)
	float altitude;
	
	int16_t voltageCell1;
	int16_t voltageCell2;
	uint8_t voltage;       // (send)
	
	uint32_t nowTime; // to log
	
	float groundPres; // To measure height
 
 
 
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

