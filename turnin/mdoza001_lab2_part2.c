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

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
        DDRC = 0xFF; PORTC = 0x00;
	
	unsigned char temp1, temp2,temp3,temp4;
	unsigned char cntavail;

    /*  Insert your solution below */
    while (1) {
	temp1 = PINA & 0x01;
	temp2 = PINA & 0x02;
	temp3 = PINA & 0x04;
	temp4 = PINA & 0x08;
	if(temp1 == 0x01){temp1 = 1;}
	if(temp2 == 0x02){temp2 = 1;}
	if(temp3 == 0x04){temp3 = 1;}
	if(temp4 == 0x08){temp4 = 1;}
	
	cntavail = 4 - (temp1+temp2+temp3+temp4);
	PORTC = cntavail;
}
    return 1;
}
