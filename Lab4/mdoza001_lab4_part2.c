/*	Author: mdoza001
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #4  Exercise #2
 *	Exercise Description: [optional - include for your own benefit]
 *
 *  Did recieve some help from a classmate telling me to create a temp variable
 * and to fix up some of my transitions that were confusing
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif
enum states{START,INC,DEC, RES, WAIT, WAIT2} state; //await3
unsigned char temp;

void tick(){
unsigned char button1 = PINA & 0x01;
unsigned char button2 = PINA & 0x02;

    
    switch(state){ //Transitions
    
    
    case START:
    if(!button1 && !button2){state = START;}
    else if (button1 && !button2) {state = INC;}
    else if (!button1 && button2){state = DEC;}
    else {state = RES;}
    break;

    case INC:
    if(button1 && button2) {state = RES;}
    else{state = WAIT2;}
    break;

    case WAIT:
     if(button1 && button2) {state = RES;}
    else if(button1 && !button2) {state = INC;}
    else if(!button1 && button2) {state = DEC;}
    else {state = WAIT;}
  
    break;
   

    case DEC:
    if(button1 && button2) {state = RES;}
    else {state = WAIT2;}
    break;

    case WAIT2:
     if(!button1 && !button2) {state = WAIT;}
    else if(button1 && button2) {state = RES;}
    else {state = WAIT2;}
    break;
    
    case RES:
    if(!button1 && !button2) {state = START;}
    else if(button1 && !button2) {state = INC;}
    else if(!button1 && button2) {state = DEC;}
    else  if(button1 && button2) {state = RES;}
    break;

    }

    switch(state){ //State actions
    case START:
    break;
            
    case WAIT:
    break;

    case INC:
    if(temp < 0x09){temp = temp + 1;}
    else if (temp == 0x09) {temp = 0x09;}
    break;

    case DEC:
    if(temp <= 0x00){temp = 0x00;}
    else {temp = temp - 1;}
    break;

    case RES:
    temp = 0x00;
    break;
    default: break;}

    }

int main(void) {
    /* Insert DDR and PORT initializations */
	    DDRA = 0x00; PORTA = 0xFF;
        DDRC = 0xFF; PORTC = 0x00;
        state = START;
    /* Insert your solution below */
    temp = 0x07;
    while (1) {
	tick();
        PORTC = temp;
    }
    return 1;
}
