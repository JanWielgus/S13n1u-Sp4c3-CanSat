// Supervisor.h
// Created: 11.01.2018r.
// Author: Jan Wielgus

#ifndef _SUPERVISOR_h
#define _SUPERVISOR_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include "config.h"


class SupervisorClass
{
 public:
	void init();
};

extern SupervisorClass superv;

#endif

