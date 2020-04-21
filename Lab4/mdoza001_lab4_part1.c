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
enum states{START,ON,OFF,WAIT} state;

void tick(){
    unsigned char temp = PINA & 0x01;
    
 switch(state){
        case START:
        state = ON;
        break;
        
         case ON:
        state = WAIT;
        break;
        
         case OFF:
        state = WAIT;
        break;
        
        case WAIT:
        if(temp){
        if(PORTB == 0x01){state = OFF;}
        else if (PORTB == 0x02) {state = ON;}
        else {state = OFF;} }
        break;
        
        default:
       break;}
       
        switch(state){
        case START:
        PORTB = 0x01;
        break;
        case ON:
        PORTB = 0x01;
        break;
        case OFF:
        PORTB = 0x02;
        break;
        case WAIT:
        break;
        default:
        PORTB = 0x01;
         break;}
}

int main(void) {
    /* Insert DDR and PORT initializations */
	 DDRA = 0x00; PORTA = 0xFF;
     DDRB = 0xFF; PORTB = 0x00;
        state = START;
        //PORTB = 0x01;
    /* Insert your solution below */
    while (1) {
	tick();
    }
    return 1;
}
