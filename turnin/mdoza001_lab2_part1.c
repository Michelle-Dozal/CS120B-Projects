/*	Author: mdoza001
 *	Lab Section: 24
 *	Assignment: Lab #1  Exercise #1
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
        DDRB = 0xFF; PORTB = 0x00;
	
	unsigned char temp1, temp2;

    /* Insert your solution below */
    while (1) {
	temp1 = PINA & 0x03;
	temp2 = 0x00;

	if((temp1 == 0x01)){
	PORTB = 0x01;}
	
	else{
	PORTB = temp2;}

    }
    return 1;
}
