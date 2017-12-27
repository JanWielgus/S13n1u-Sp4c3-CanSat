#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "komunikacja.h"

LiquidCrystal_I2C lcd(0x3F, 16, 2);

#define COLS 16
#define ROWS 2


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
	komun.init();
	//pinMode(LED_BUILTIN, OUTPUT);
	lcd.init();
	lcd.backlight();
}

void loop()
{
	if (Serial.available())
	{
		while (Serial.available() > 0)
			napisz(String(Serial.read()));
		delay(300);
		komun.wyslij(KOMUN_RAMKA_ARDU_1_TYPE);
	}
	//komun.wyslij(KOMUN_RAMKA_ARDU_1_TYPE);
	//komun.odbierz();
	//delay(5000);
	//napisz(String(komun.counter1));
	napisz("Czeka...",1);
}

