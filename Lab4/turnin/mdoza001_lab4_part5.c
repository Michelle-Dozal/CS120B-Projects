/*	Author: mdoza001
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #4  Exercise #1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif
enum states{START,ON,OFF}state;

void tick(){
        unsigned char temp = PINA & 0x01;
        switch(state){
        case START:
        state = ON;
        break;
        case ON:
        if (temp){ state = OFF;}
        else if (!temp) {state = ON;}
        break;
        case OFF:
       if(temp) {state = OFF;}
        else if (!temp) {state = ON;}
        break;
        default:
        state = ON;
        break;}


        switch(state){
        case START:
        PORTB = 0x01;
        break;
        case ON:
        break;
        case OFF:
        PORTB = 0x02;
        break;
        default: break;}
}


int main(void) {
    /* Insert DDR and PORT initializations */
	 DDRA = 0xFF; PORTA = 0x00;
        DDRB = 0x00; PORTB = 0xFF;
        state = START;
        PORTB = 0x01;
    /* Insert your solution below */
    while (1) {
	tick();
    }
    return 1;
}
