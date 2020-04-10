/*	Author: mdoza001
 *  Partner(s) Name: 
 ***	Lab Section:
 *	Assignment: Lab #3  Exercise #5
 *	Exercise Description: [optional - include for your own benefit]
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
	DDRD = 0x00; PORTD = 0xFF;
	DDRB = 0xFE; PORTB = 0x01;
	
    /* Insert your solution below */
	unsigned char temp1, temp2;
	unsigned short temp3;
	 while (1) {
        temp = (PINB & 0x01);
	temp2 = (temp2 | temp1);
	
	if(temp2 >= 70){ temp3 = 0x02;}
	else if ((temp2 < 70) && (temp2 > 5)){temp3 = 0x04;}

	PORTB = temp3;

}	
	return 1; }
