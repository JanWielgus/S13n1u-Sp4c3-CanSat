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
#include "myMPU6050.h"
#include "config.h"


class SensorsClass
{
// ===== FUNCTIONS & OTHERS =====

 private:
	MyMPU6050Class mpu;
	
 public:
	void init();
	void readAngles(); // roll, pitch, yaw
	
	// to send, to save transmitted data
	uint16_t compressPressure(float pres);
	uint8_t compressHeading(float head);
	
	
// ===== VARIABLES =====
	
	struct //ypr_angles
	{
		double pitch;
		double roll;
		float  yaw;
	}DMPang;
	
	float pressure;
	uint16_t pressureComp;         // Compressed version, to send
	uint8_t temperature;
	uint8_t carbDiOx;              // CO2
	uint8_t tVOC;
	uint8_t humid;
	uint8_t ionRadiation;          // Ionizing radiation
	uint8_t pm25parts;             // PM2.5
	uint8_t voltage;
	float heading;
	uint8_t headingComp;           // Compressed version, to send
  
	
 
 
 
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

