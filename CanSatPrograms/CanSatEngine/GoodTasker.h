/* 
* GoodTasker.h
*
* Created: 17.02.2017 14:08:45
* Author: Filip
* Ver: 1.0
*/

//------------------------------------------------------------------------------------------------------------------
//Instrukcja u¿ycia:
/*
{
1. Czas podstawowy (okres wykonywania najczêstszych zadañ - highTask) nale¿y ustawiæ w definicji:
   podstawaCzasowa.

2. Niezale¿nie ustawia siê równie¿ maksymaln¹ iloœæ najczêstszych zadañ w definicji: highTaskMax.

3. W kolejnych stopniach (mid i low) maksymalna iloœæ wykonywanych zadañ ograniczona jest
   mno¿nikiem okresu - definicje mnoznikMidTask i mnoznikLowTask.
   Aby dodaæ wiêcej funkcji ni¿ mno¿nik okresu pozwala patrz pkt. 6.

4. Aby u¿yæ GoodTaskera nale¿y korzystaæ z gotowej instancji obiektu - Tasker.
   W sekcji setup():
   - Nale¿y zainicjowaæ Tasker: Tasker.init();
   - Nale¿y dodaæ zadania najczêstsze (high), rzadsze (mid) i rzadkie (low):
		Tasker.dodajHighTask(nazwaFunkcji);
		Tasker.dodajMidTask(nazwaFunkcji);
		Tasker.dodajLowTask(nazwaFunkcji);
	W sekcji loop():
	- Nale¿y u¿yæ metody automatycznie wywo³uj¹cej dodane funkcje:
		Tasker.wykonajZadania();

5. Kolejnoœæ wykonywania zadañ jest zawsze zachowana w ramach jednego stopnia.

6. Zadania musz¹ byæ przekazane jako funkcje, dlatego metody obiektów nale¿y w pliku, w którym Tasker
   jest u¿ywany opakowaæ funkcj¹, np.:
   
   void protezaCyklKomunikacji()
   {
		obiekt_Komunikacja.cyklKom();
   }
   ...
   Tasker.dodajHighTask(protezaCyklKomunikacji);

7. Za pomoc¹ jedenej "protezy" mo¿na opakowaæ wiêcej funkcji, co pozwala na ominiêcie ograniczeñ
   zwi¹zanych z mno¿nikiem kolejnych stopni taskera.

8. Kiedy arduino nie nad¹¿a z wykonywaniem zadañ z zadan¹ czêstotliwoœci¹ ustawiana jest flaga:
   bool Tasker.przeciazenieFlag
   Kiedy kolejny cykl zmieœci siê w zadanych ramach czasowych powy¿sza flaga jest zerowana (false).

9. Jeœli choæ raz zostanie ustawiona flaga Tasker.przeciazenieFlag, ustawiona zostaje rozwniez flaga
   bool systemNiestabilnyFlag i pozostaje ustawiona a¿ do ponownego uruchomienia systemu.

10.W przypdaku dodania zbyt du¿ej iloœci funkcji do wykonania (ograniczenia opisane w pkt. 2 i 3)
   system jest ca³kowicie zatrzymywany.

11.Nale¿y unikaæ u¿ywania funkcji/metod synchronicznych, takich jak Serial.println/print.
   W przypdaku u¿ycia jakichœ funkcji z biblioteki najlepiej sprawdzaæ, które s¹ synchroniczne.
   Nie wolno u¿ywaæ delay() i tym podobnych chyba, ¿e w wyj¹tkowych sytuacjach i tylko bardzo ma³e opóŸnienia!!!
12.Nie wolno u¿ywaæ pinów 2, 3 i 5 jako PWM (analogWrite)!!!
}*/
//------------------------------------------------------------------------------------------------------------------


#ifndef __GOODTASKER_H__
#define __GOODTASKER_H__

#define podstawaCzasowa 50*1000UL	//okres wykonywania czêstych (high) zadañ w us (ms * 1000us)
#define highTaskMax 10	//(0-255) maksymalna iloœæ czêstych zadañ
#define mnoznikMidTask 4	//(2-254) mno¿nik dla zadañ œrednich (okres midTask = podstawaCzasowa*mnoznikMidTask)
#define midTaskMax mnoznikMidTask
#define mnoznikLowTask 10	//(2-254) mno¿nik dla zadañ rzadkich (okres lowTask = okres midTask*mnoznikLowTask)
#define lowTaskMax mnoznikLowTask

class GoodTasker
{
//variables
private:
public:
	volatile bool tickFlag = false;	//flaga wyst¹pienia przerwania, musi byæ publiczna
	bool przeciazenieFlag = false;
	bool systemNiestabilnyFlag = false;

	void (*highTaskArr[highTaskMax])();	//tablica wskaŸników na funkcjê
	uint8_t highTaskIl = 0;				//iloœæ pod³¹czonych zadañ

	void (*midTaskArr[mnoznikMidTask])();
	uint8_t midTaskIl = 0;
	uint8_t odstepMid = mnoznikMidTask+1;	//odstêp w cyklach podstawowych; +1 ¿eby nie wykona³o siê ¿adne zadanie jeœli nie jest dodane
	uint8_t doWykonaniaMid = 0;			//zadanie, które ma byæ wykonane
	uint8_t licznikMid = 0;				//licznik wykonañ cykli podstawowych

	void (*lowTaskArr[mnoznikLowTask])();
	uint8_t lowTaskIl = 0;
	uint8_t odstepLow = mnoznikLowTask+1;
	uint8_t doWykonaniaLow = 0;
	uint8_t licznikLow = 0;

//functions
public:
	void init();
	void wykonajZadania();
	void wykonajHigh();
	void wykonajMid();
	void wykonajLow();
	void dodajHighTask(void (*task)());	//dodaje zadanie do tablicy najczêstszych zadañ
	void dodajMidTask(void (*task)());	//dodaje zadanie do tablicy œrednio wykonywanych zadañ
	void dodajLowTask(void (*task)());	//dodaje zadanie do tablicy rzadkich zadañ
	//GoodTasker();
	//~GoodTasker();
private:
	//GoodTasker( const GoodTasker &c );
	//GoodTasker& operator=( const GoodTasker &c );

}; //GoodTasker

extern GoodTasker Tasker;

#endif //__GOODTASKER_H__





//Przyk³ad u¿ycia:
/*#include "GoodTasker.h"

void funkcyjkaHigh()
{
	Serial.println("High");
}
void pokazPrzec()
{
	Serial.print("Przeciazenie: ");
	Serial.println(Tasker.przeciazenieFlag);
}
void funkcyjkaMid()
{
	Serial.println("Mid");
}
void funkcyjkaLow()
{
	Serial.println("Low");
}

void setup()
{
	Serial.begin(115200);

	//HighTask co 25ms	 (max. 10 funkcji)
	//MidTask co 250ms	 (max. 10 funkcji)
	//LowsTask co 1000ms (max. 4 funkcje)
	Tasker.init();
	Autonomia.init();
	
	Tasker.dodajHighTask(funkcyjkaHigh);
	Tasker.dodajHighTask(cyklAutonomia);
	Tasker.dodajHighTask(pokazPrzec);
	Tasker.dodajMidTask(funkcyjkaMid);
	Tasker.dodajLowTask(funkcyjkaLow);
}

void loop()
{
	Tasker.wykonajZadania();
}
*/