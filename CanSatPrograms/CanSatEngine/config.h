/*
 * config.h
 *
 * Created: 11.01.2018 19:26:06
 *  Author: Jan Wielgus
 * 
 * CanSat configuration file
 */ 


#ifndef CONFIG_H_
#define CONFIG_H_

// ===== SWITCHES ===== (To change working mode etc.)

// dubug (only one could be uncommented)
	//#define _INO_DEBUG
	//#define _SENSORS_DEBUG
	//#define _COM_DEBUG // communication
	//#define _SUPER_DEBUG




// ===== CONSTANS ===== (eg. pins)

	#define MAX_LOST_PACKETS 2          // If more -> signal lost mode
	
	// pins
	#define MPU_INTERRUPT_PIN 2         // All interrupt: 2, 3, 18, 19, 20, 21
	#define ION_RAD_PIN A0              // Ionizing radiation analog pin
	#define LED1_PIN 16                 // led 1
	#define LED2_PIN 18                 // led 2
	#define BATTERY_C1_PIN A1           // battery cell 1 volatge analog
	#define BATTERY_C2_PIN A2           // battery cell 2 volatge analog
	
	
	// Working modes
	#define POWS_MODE        1          // Power save mode
	#define NORMCOM_MODE     2          // Normal communication
	#define MAINMISSION_MODE 3          // Main mission
	#define SEARCHING_MODE   4          // Searching for CanSat
	
	// transmission powers
	#define DBM27 4  // 27dBm
	#define DBM24 3  // 24dBm
	#define DBM21 2  // 21dBm
	#define DBM18 1  // 18dBm




//<<<<<<<<<=====================     COMMUNIACTION     =====================>>>>>>>>>

	// Remember to change packet sizes after any changes!
	
	// Packets MUST HAVE IDEAL size as needed!!!
	
	#define serialPort 1                      // Serial: 0, Serial1: 1, Serial2: 2, Serial3: 3
	#define comSerial Serial1                 // Serial with transceiver
	#define BAUD_RATE 9600                    // With transciever
	#define MAX_SEND_SIZE 30                  // Size of the largest packet (could be higher than needed)
	
	// Pattern: nadawca_RAMKA_nazwa_SIZE/TYPE
	
	// -- recieve --
	//...
	
	// -- transmit --
	//...
	
	
	// times [ms] after CanSat set ... power; eg. after x[ms] high power is set
	#define HP_SET_TIME 2500  // High power (27dBm)
	#define MP_SET_TIME 1100  // Medium power (21dBm)
	
	#define  RESTORE_CONNECTION_PARAMS_TIME 3000  // Time after signal lost when OTA speed is set to 1.2kbps
	
	#define DEFAULT_FREQUENCY 0x50
	
	
	
//<<<<<<<<<=====================     SENSORS     =====================>>>>>>>>>
	
	
	#define PITCH_OFFSET 0            // Offset osi x
	#define ROLL_OFFSET  0            // Offset osi y
	
	
	// GPS
	#define GPSserial Serial2         // gps serial
	





#endif /* CONFIG_H_ */