/*	Author: mdoza001
 *  Partner(s) Name: 
 ***	Lab Section:
 *	Assignment: Lab #3  Exercise #1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

unsigned char GetBit(unsigned char x, unsigned char y){
        return((x >> y) & 0x01); }

int main(void) {
    /* Insert DDR and PORT initializations */
        DDRA = 0x00; PORTA = 0xFF;
        DDRB = 0x00; PORTB = 0xFF;
        DDRC = 0xFF; PORTC = 0x00;
    /* Insert your solution below */
         /* Insert your solution below */
        unsigned char temp1;
        unsigned char portA;
        unsigned char portB;
        unsigned char i = 0x00;
    while (1) {
        portA = PINA;
        portB = PINB;
       for(i = 0; i < 0x08; i++){

         temp1 += GetBit(portA, i) + GetBit(portB,i);
           
       }

        PORTC = temp1;
        temp1 = 0;


}
        return 1; }
