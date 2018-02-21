// Date: 21.02.2018
// Author: Jan Wielgus
// Sieniu_34 ground staion
//


#include "komunikacja.h"
#include "CanSatCommuniaction.h"


void setup()
{
	komun.init();
	cscom.init();
}

void loop()
{
	delay(1000);
	komun.wyslij(KOMUN_RAMKA_ARDU_1_TYPE);
}
