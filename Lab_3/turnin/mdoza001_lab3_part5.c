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
	//unsigned char temp;
	unsigned short lbs;
    unsigned short temp;
    
	 while (1) {
        lbs = (PIND  << 1);
         temp = (PINB & 0x01);
         lbs = lbs | temp;
         //lbs = PINB + PIND;
	
         if(lbs >= 70){ PORTB = 0x02;}
	
         else if ((lbs > 5) && (lbs < 70)) {PORTB = 0x04;}
          else{PORTB = 0x00;}
         //if(lbs == 5){PORTB = 0x00;}



}	
	return 1; }
