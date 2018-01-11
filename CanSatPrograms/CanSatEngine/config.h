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

#define MAX_LOST_PACKETS 2                // If more -> signal lost mode
#define MPU_INTERRUPT_PIN 20      // All interrupt: 2, 3, 18, 19, 20, 21





//<<<<<<<<<=====================     COMMUNIACTION     =====================>>>>>>>>>

	// Remember to change packet sizes after any changes!
	
	// Packets MUST HAVE IDEAL size as needed!!!
	
	#define serialPort 1                      // Serial: 0, Serial1: 1, Serial2: 2, Serial3: 3
	#define BAUD_RATE 9600                    // With transciever
	#define MAX_SEND_SIZE 30                  // Size of the largest packet (could be higher than needed)
	
	// Pattern: nadawca_RAMKA_nazwa_SIZE/TYPE
	
	// -- recieve --
	//...
	
	// -- transmit --
	//...
	
	
	
//<<<<<<<<<=====================     SENSORS     =====================>>>>>>>>>
	
	
	#define PITCH_OFFSET 0            // Offset osi x
	#define ROLL_OFFSET  0            // Offset osi y
	





#endif /* CONFIG_H_ */