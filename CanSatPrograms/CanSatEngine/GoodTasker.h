/* 
* GoodTasker.h
*
* Created: 17.02.2017 14:08:45
* Author: Filip
* Ver: 1.0
*/

//------------------------------------------------------------------------------------------------------------------
//Instrukcja u�ycia:
/*
{
1. Czas podstawowy (okres wykonywania najcz�stszych zada� - highTask) nale�y ustawi� w definicji:
   podstawaCzasowa.

2. Niezale�nie ustawia si� r�wnie� maksymaln� ilo�� najcz�stszych zada� w definicji: highTaskMax.

3. W kolejnych stopniach (mid i low) maksymalna ilo�� wykonywanych zada� ograniczona jest
   mno�nikiem okresu - definicje mnoznikMidTask i mnoznikLowTask.
   Aby doda� wi�cej funkcji ni� mno�nik okresu pozwala patrz pkt. 6.

4. Aby u�y� GoodTaskera nale�y korzysta� z gotowej instancji obiektu - Tasker.
   W sekcji setup():
   - Nale�y zainicjowa� Tasker: Tasker.init();
   - Nale�y doda� zadania najcz�stsze (high), rzadsze (mid) i rzadkie (low):
		Tasker.dodajHighTask(nazwaFunkcji);
		Tasker.dodajMidTask(nazwaFunkcji);
		Tasker.dodajLowTask(nazwaFunkcji);
	W sekcji loop():
	- Nale�y u�y� metody automatycznie wywo�uj�cej dodane funkcje:
		Tasker.wykonajZadania();

5. Kolejno�� wykonywania zada� jest zawsze zachowana w ramach jednego stopnia.

6. Zadania musz� by� przekazane jako funkcje, dlatego metody obiekt�w nale�y w pliku, w kt�rym Tasker
   jest u�ywany opakowa� funkcj�, np.:
   
   void protezaCyklKomunikacji()
   {
		obiekt_Komunikacja.cyklKom();
   }
   ...
   Tasker.dodajHighTask(protezaCyklKomunikacji);

7. Za pomoc� jedenej "protezy" mo�na opakowa� wi�cej funkcji, co pozwala na omini�cie ogranicze�
   zwi�zanych z mno�nikiem kolejnych stopni taskera.

8. Kiedy arduino nie nad��a z wykonywaniem zada� z zadan� cz�stotliwo�ci� ustawiana jest flaga:
   bool Tasker.przeciazenieFlag
   Kiedy kolejny cykl zmie�ci si� w zadanych ramach czasowych powy�sza flaga jest zerowana (false).

9. Je�li cho� raz zostanie ustawiona flaga Tasker.przeciazenieFlag, ustawiona zostaje rozwniez flaga
   bool systemNiestabilnyFlag i pozostaje ustawiona a� do ponownego uruchomienia systemu.

10.W przypdaku dodania zbyt du�ej ilo�ci funkcji do wykonania (ograniczenia opisane w pkt. 2 i 3)
   system jest ca�kowicie zatrzymywany.

11.Nale�y unika� u�ywania funkcji/metod synchronicznych, takich jak Serial.println/print.
   W przypdaku u�ycia jakich� funkcji z biblioteki najlepiej sprawdza�, kt�re s� synchroniczne.
   Nie wolno u�ywa� delay() i tym podobnych chyba, �e w wyj�tkowych sytuacjach i tylko bardzo ma�e op�nienia!!!
12.Nie wolno u�ywa� pin�w 2, 3 i 5 jako PWM (analogWrite)!!!
}*/
//------------------------------------------------------------------------------------------------------------------


#ifndef __GOODTASKER_H__
#define __GOODTASKER_H__

#define podstawaCzasowa 50*1000UL	//okres wykonywania cz�stych (high) zada� w us (ms * 1000us)
#define highTaskMax 10	//(0-255) maksymalna ilo�� cz�stych zada�
#define mnoznikMidTask 4	//(2-254) mno�nik dla zada� �rednich (okres midTask = podstawaCzasowa*mnoznikMidTask)
#define midTaskMax mnoznikMidTask
#define mnoznikLowTask 10	//(2-254) mno�nik dla zada� rzadkich (okres lowTask = okres midTask*mnoznikLowTask)
#define lowTaskMax mnoznikLowTask

class GoodTasker
{
//variables
private:
public:
	volatile bool tickFlag = false;	//flaga wyst�pienia przerwania, musi by� publiczna
	bool przeciazenieFlag = false;
	bool systemNiestabilnyFlag = false;

	void (*highTaskArr[highTaskMax])();	//tablica wska�nik�w na funkcj�
	uint8_t highTaskIl = 0;				//ilo�� pod��czonych zada�

	void (*midTaskArr[mnoznikMidTask])();
	uint8_t midTaskIl = 0;
	uint8_t odstepMid = mnoznikMidTask+1;	//odst�p w cyklach podstawowych; +1 �eby nie wykona�o si� �adne zadanie je�li nie jest dodane
	uint8_t doWykonaniaMid = 0;			//zadanie, kt�re ma by� wykonane
	uint8_t licznikMid = 0;				//licznik wykona� cykli podstawowych

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
	void dodajHighTask(void (*task)());	//dodaje zadanie do tablicy najcz�stszych zada�
	void dodajMidTask(void (*task)());	//dodaje zadanie do tablicy �rednio wykonywanych zada�
	void dodajLowTask(void (*task)());	//dodaje zadanie do tablicy rzadkich zada�
	//GoodTasker();
	//~GoodTasker();
private:
	//GoodTasker( const GoodTasker &c );
	//GoodTasker& operator=( const GoodTasker &c );

}; //GoodTasker

extern GoodTasker Tasker;

#endif //__GOODTASKER_H__





//Przyk�ad u�ycia:
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