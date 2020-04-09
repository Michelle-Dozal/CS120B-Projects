/*	Author: mdoza001
 *	Lab Section: 24
 *	Assignmen: Lab #1  Exercise #2
 *	Exercise Description: Garage door system
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif


unsigned char GetBit(unsigned char x, unsigned char k) {
   return ((x & (0x01 << k)) != 0);
}


int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
        DDRC = 0xFF; PORTC = 0x00;
	
	unsigned char temp1, temp2,temp3,temp4;
	unsigned char cntavail;
	
	
  /* Insert your solution below */
    while (1) {
/*	cntavail = 0;
	for(unsigned char i = 0; i < 3; i++){
	if(GetBit(PINA,i)){
	   cntavail++;}
	} */
//	PORTC = cntavail;
	temp1 = PINA & 0x01;
	temp2 = PINA & 0x02;
	temp3 = PINA & 0x04;
	temp4 = PINA & 0x08;

	if(temp1 == 0x01){temp1 = 1;}
	if(temp2 == 0x02){temp2 = 1;}
	if(temp3 == 0x04){temp3 = 1;}
	if(temp4 == 0x08){temp4 = 1;}
	cntavail = temp1+temp2+temp3+temp4;
	PORTC = cntavail;
  	if(cntavail == 4){PORTC = cntavail | 0x80;}
//	PORTC = cntavail;
}
    return 1;
}
