#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "komunikacja.h"

#define COLS 16
#define ROWS 2

LiquidCrystal_I2C lcd(0x3F, 16, 2);


void napisz(String napis, int rowy=0, int coly=0)
{
	uint8_t dlugosc = napis.length();
	for (int q=0; ((q+coly) < COLS && q < dlugosc); q++)
	{
		lcd.setCursor(q+coly, rowy);
		lcd.print(napis[q]);
	}
}





void setup()
{
	lcd.init();
	komun.init();
	//pinMode(LED_BUILTIN, OUTPUT);
	lcd.backlight();
	delay(500);
	lcd.clear();
	delay(5000);
}

void loop()
{
	komun.wyslij(KOMUN_RAMKA_ARDU_1_TYPE);
	delay(1500);
	lcd.setCursor(0,0);
	lcd.print(komun.testowa1);
	napisz("Czeka...",1);
}

