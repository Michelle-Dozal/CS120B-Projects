/*	Author: mdoza001
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #3  Exercise #2
 *	Exercise Description: [optional - include for your own benefit]
 *
 e*	I acknowledge all content contained herein, excluding template or example
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
    /* Insert your solution below */
	unsigned char input, fuel;	
   	//input = PINA;
	 while (1) {
	input = PINA;	
	int temp = 6;
		if(input < 13) {temp--;}
		if(input < 10) {temp--;}
		if(input < 7)  {temp--;}
		if(input < 5) {temp--;}
		if(input < 3) {temp--;}
	switch(temp)
{
	case 6: fuel = 0x3F;break;
	case 5: fuel = 0x3E;break;
	case 4: fuel = 0x3C;break;
	case 3: fuel = 0x38;break;
	case 2: fuel = 0x30;break;
	case 1: fuel = 0x20;break;}
	PORTC = fuel;	

    return 1;
}
