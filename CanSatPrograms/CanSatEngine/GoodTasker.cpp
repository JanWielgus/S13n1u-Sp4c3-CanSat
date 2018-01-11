/* 
* GoodTasker.cpp
*
* Created: 17.02.2017 14:08:45
* Author: Filip
* Ver: 1.0
*/


#include <TimerThree.h>	//only Arduino Mega
#include "GoodTasker.h"


GoodTasker Tasker;	//preinstancja

void GoodTasker_tickSetFunc() //funkcja zrobiona z metody aby da³o siê j¹ przekazaæ jako obs³ugê przerwania zegarowego
{
	//Tasker.tickSetFunc();
	Tasker.tickFlag = true;
}

void GoodTasker::init()
{
	Timer3.initialize(podstawaCzasowa); //okres w mikrosekundach
	Timer3.attachInterrupt(GoodTasker_tickSetFunc);
}

//void GoodTasker::tickSetFunc()	//metoda dla przerwania zegarowego
//{
	//tickFlag = true;
//}

void GoodTasker::wykonajZadania()
{
	if(tickFlag)
	{
		tickFlag = false;

		wykonajHigh();

		if(tickFlag)	//czy podczas wykonywania aktualnych operacji nie powinien wyst¹piæ kolejny cykl
		{
			przeciazenieFlag = true;
			systemNiestabilnyFlag = true;
		}
		else
		przeciazenieFlag = false;
	}
}

void GoodTasker::wykonajHigh()
{
	for(int i=0; i<highTaskIl; i++)
	{
		highTaskArr[i]();
	}

	wykonajMid();
}

void GoodTasker::wykonajMid()
{
	if( (doWykonaniaMid*odstepMid == licznikMid) && odstepMid<=midTaskMax )
	{
		midTaskArr[doWykonaniaMid]();
		doWykonaniaMid++;
	}

	licznikMid++;
	if(licznikMid==midTaskMax)
	{
		licznikMid = 0;
		doWykonaniaMid = 0;
		wykonajLow();
	}
}

void GoodTasker::wykonajLow()
{
	if( (doWykonaniaLow*odstepLow == licznikLow) && odstepLow<=lowTaskMax )
	{
		lowTaskArr[doWykonaniaLow]();
		doWykonaniaLow++;
	}

	licznikLow++;
	if(licznikLow==lowTaskMax)
	{
		licznikLow = 0;
		doWykonaniaLow = 0;
	}
}

void GoodTasker::dodajHighTask(void (*task)())	//dodaje zadanie do tablicy najczêstszych zadañ
{
	highTaskArr[highTaskIl%highTaskMax] = task;
	highTaskIl++;

	if(highTaskIl>highTaskMax) Timer3.stop(); //zatrzymanie akcji serca
}

void GoodTasker::dodajMidTask(void (*task)())
{
	midTaskArr[midTaskIl%midTaskMax] = task;
	midTaskIl++;

	odstepMid = midTaskMax/midTaskIl;	//liczenie co ile minimalnych cykli ma wywo³aæ siê kolejne zadanie

	if(midTaskIl>midTaskMax) Timer3.stop();
}

void GoodTasker::dodajLowTask(void (*task)())
{
	lowTaskArr[lowTaskIl%lowTaskMax] = task;
	lowTaskIl++;

	odstepLow = lowTaskMax/lowTaskIl;

	if(lowTaskIl>lowTaskMax) Timer3.stop();
}


// default constructor
/*GoodTasker::GoodTasker()
{
} //GoodTasker

// default destructor
GoodTasker::~GoodTasker()
{
} //~GoodTasker*/
