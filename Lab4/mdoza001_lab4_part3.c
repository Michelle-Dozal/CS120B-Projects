/*	Author: mdoza001
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #4  Exercise #3
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif
unsigned char temp;
enum states{START,WAIT,P,CHECK,Y,LOCK,UNLOCK} state;

void tick(){ //Transitions
        unsigned char Pound = PINA & 0x04;
        unsigned char YYY = PINA & 0x02;
        unsigned char X = PINA & 0x01;
        unsigned char Zero = PINA & 0x00;
        unsigned char Inside = PINA & 0x80;
       
       switch(state){
       case START:
       state = WAIT;
       break;

       case WAIT:
       if(Pound == 0x04){state = P;}
       else if (Inside == 0x80) {state = LOCK;}
       else{state = WAIT;}
       break;

       case P:
       if (Pound == 0x04){state = P;}
       else if (Zero == 0x00){state = CHECK;}
       else{state = WAIT;}
       break;


       case CHECK:
       if(YYY == 0x02){state = LOCK;}
       else if (X == 0x01){state = LOCK;}
       else{state = UNLOCK;}
       break;

       case LOCK:
       state = WAIT;
       break;

       case UNLOCK:
       if(Inside == 0x80){state = LOCK;}
       else{state = UNLOCK;}
        break;

       default:
       //state = START;
       break;}


    switch(state){ //Actions
    case START:
    PORTC = START;
    break;
    case WAIT:
    PORTC = WAIT;
    case P:
    PORTC = P;
    break;
    case CHECK:
    PORTC = CHECK;
    break;
    case Y:
    break;
    case UNLOCK:
    temp = 0x01;
    PORTC = UNLOCK;
    break;
    case LOCK:
    temp = 0x00;
    PORTC = LOCK;
    break;
default: break;}
    }

int main(void) {
    /* Insert DDR and PORT initializations */
	    DDRA = 0x00; PORTA = 0xFF;
        DDRB = 0xFF; PORTB = 0x00;
        DDRC = 0xFF; PORTC = 0x00;
    
        state = START;
    /* Insert your solution below */
    while (1) {
	tick();
        PORTB = temp;
    }
    return 1;
}
