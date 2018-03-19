// Created: 11.01.2018r.
// Author: Jan Wielgus
// 

#include "Sensors.h"

SensorsClass sensor;

void dmpDataReady()
{
	sensor.mpuInterrupt = true;
}


SensorsClass::SensorsClass()
{
	ccs811 = new CCS811(CCS811_ADDRESS); // otherwise not working
	groundPres = 1013.25;
}



void SensorsClass::init()
{
	Wire.begin();
	//Wire.setClock(400000L); // So fast clock is not necessary
	
	// ====== MPU6050 DMP ======
	mpu.initialize();
	pinMode(MPU_INTERRUPT_PIN, INPUT);
	
	devStatus = mpu.dmpInitialize();
	
	// supply your own gyro offsets here, scaled for min sensitivity
	mpu.setXGyroOffset(220);
	mpu.setYGyroOffset(76);
	mpu.setZGyroOffset(-85);
	mpu.setZAccelOffset(1788); // 1688 factory default for my test chip
	
	if (devStatus == 0)
	{
		mpu.setDMPEnabled(true);
		
		attachInterrupt(digitalPinToInterrupt(MPU_INTERRUPT_PIN), dmpDataReady, RISING);
		mpuIntStatus = mpu.getIntStatus();
		
		dmpReady = true;
		
		packetSize = mpu.dmpGetFIFOPacketSize();
	}
	else
	{
		// ERROR!
		// 1 = initial memory load failed
		// 2 = DMP configuration updates failed
		// (if it's going to break, usually the code will be 1)
	}
	
	// ====== MPU6050 ======
	
	
	
	// ====== CCS811 ======
		ccs811->begin();
		
		
	// ====== BME280 ======
		myBME280.settings.commInterface = I2C_MODE;
		myBME280.settings.I2CAddress = 0x77;
		myBME280.settings.runMode = 3;
		myBME280.settings.tStandby = 0;
		myBME280.settings.filter = 4;
		myBME280.settings.tempOverSample = 5;
		myBME280.settings.pressOverSample = 5;
		myBME280.settings.humidOverSample = 5;
		delay(10); //Make sure sensor had enough time to turn on. BME280 requires 2ms to start up.
		myBME280.begin();
	
	
	// ====== PMS5003 ======
	
	
	
	// ====== HTU21 ======
	
	
	
	// ====== HMC5883L ======
	
	
	
	// ====== MS5611 ======
		//instead of while in example code
		for (int i=0;  i<3; i++)
		{
			if (ms5611.begin(MS5611_ULTRA_HIGH_RES))
			{
				groundPres = (float)ms5611.readPressure();
				break;
			}
		}
	
	// ====== UBLOX NEO6M ======
		GPSserial.begin(9600);
	
	
	// ====== OpenLog ======
	
	
}



void SensorsClass::readAngles()
{
	// if programming failed, don't try to do anything
	if (!dmpReady) return;
	
	// wait for MPU interrupt or extra packet(s) available
	while (!mpuInterrupt && fifoCount < packetSize) {
		// other program behavior stuff here
		
		// if you are really paranoid you can frequently test in between other
		// stuff to see if mpuInterrupt is true, and if so, "break;" from the
		// while() loop to immediately process the MPU data
		
		// EWENTUANIE da? tu break/return !!!
	}
	
	// reset interrupt flag and get INT_STATUS byte
	mpuInterrupt = false;
	mpuIntStatus = mpu.getIntStatus();
	
	// get current FIFO count
	fifoCount = mpu.getFIFOCount();
	
	// check for overflow (this should never happen unless our code is too inefficient)
	if ((mpuIntStatus & 0x10) || fifoCount == 1024)
	{
		mpu.resetFIFO();
	}
	else if (mpuIntStatus & 0x02)
	{
		// wait for correct available data length, should be a VERY short wait
		while (fifoCount < packetSize) fifoCount = mpu.getFIFOCount();

		// read a packet from FIFO
		mpu.getFIFOBytes(fifoBuffer, packetSize);
		
		// track FIFO count here in case there is > 1 packet available
		// (this lets us immediately read more without waiting for an interrupt)
		fifoCount -= packetSize;
		
		//////////////////////////////////////////////////////////////////////////

		int16_t qI[4];
		//if (fifoBuffer == 0) fifoBuffer = mpu.dmpPacketBuffer;
		qI[0] = ((fifoBuffer[0] << 8) | fifoBuffer[1]);
		qI[1] = ((fifoBuffer[4] << 8) | fifoBuffer[5]);
		qI[2] = ((fifoBuffer[8] << 8) | fifoBuffer[9]);
		qI[3] = ((fifoBuffer[12] << 8) | fifoBuffer[13]);
		
		q.w = (float)qI[0] / 16384.0f;
		q.x = (float)qI[1] / 16384.0f;
		q.y = (float)qI[2] / 16384.0f;
		q.z = (float)qI[3] / 16384.0f;
		
		mpu.dmpGetGravity(&gravity, &q);
		mpu.dmpGetYawPitchRoll(ypr, &q, &gravity);
		
		DMPang.pitch = (ypr[1]*(-100))-PITCH_OFFSET;
		DMPang.roll  = (ypr[2]*100)-ROLL_OFFSET;
		DMPang.yaw   = ypr[3];
		
		//////////////////////////////////////////////////////////////////////////
	}
}



uint16_t SensorsClass::compressPressure(float pres)
{
	// compression code
}



uint8_t SensorsClass::compressHeading(float head)
{
	// compression code
}



void SensorsClass::readPressure()
{
	// temperature form baro is replaced with BME temperature
	
	pressure_main.value = ms5611.readPressure();
	altitude = getAltitude((float)pressure_main.value, temperatureBMEFloat);
}


float SensorsClass::getAltitude(float press, float temp)
{
	return ((pow((groundPres / press), 1/5.257) - 1.0) * (temp + 273.15)) / 0.0065;
}


void SensorsClass::setSeaLevelPressure(float pres)
{
	groundPres = pres;
}



void SensorsClass::readTemperature()
{
	float BMEtempC = myBME280.readTempC();
	temperatureBMEFloat = BMEtempC;
	temperatureBME = uint8_t(temperatureBMEFloat); // to change!!!!
}



void SensorsClass::readPosition()
{
	while (GPSserial.available())
		tGPS.encode(GPSserial.read());
	
	gpsX.value = tGPS.location.lat() * 10e7;
	gpsY.value = tGPS.location.lng() * 10e7;
	
	altitudeGPS = tGPS.altitude.meters();
	speedGPS = tGPS.speed.kmph();
}



void SensorsClass::readCCS811BME280()
{
	if (ccs811->dataAvailable())
	{
		ccs811->readAlgorithmResults();
		
		CO2 = ccs811->getCO2();
		tVOC = ccs811->getTVOC();
		
		// Temperature in readTemperature method triggered apart
		
		pressureBME = myBME280.readFloatPressure(); // Pa
		humidBMEFloat = myBME280.readFloatHumidity();
		humidBME = humidBMEFloat/10;
		
		ccs811->setEnvironmentalData(humidBMEFloat, temperatureBMEFloat);
	}
}



void SensorsClass::readIonizingRadiation()
{
	ionRad = analogRead(ION_RAD_PIN);
	ionRadComp = (float)ionRad/4.1; // 0-250
}



void SensorsClass::readPM25()
{
	return;
}



void SensorsClass::readVoltage()
{
	voltageCell1 = analogRead(BATTERY_C1_PIN);
	voltageCell2 = analogRead(BATTERY_C2_PIN);
	voltage = (float)min(voltageCell1, voltageCell2)/4.1; // 0-250, minimum of two cells
}



void SensorsClass::readHeading()
{
	return;
}



void SensorsClass:: saveLogData()
{
	// Log data on sd card
}



