/*	Author: mdoza001
 *  Partner(s) Name: 
 **	Lab Section:
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

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0x00; PORTB = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;
	
    /* Insert your solution below */
	unsigned char temp1,temp2;
        unsigned char portA = PINA;
        unsigned char portB = PINB;
        unsigned char total1,total2;
        unsigned char a = 0x00;
        unsigned char i = 0x00;
    while (1) {
        temp1 = (portA >> i) &0x01;
        temp2 = (portB >> i) & 0x01;
        
        for(i; i < 8; i++) {
         temp1 = (portA >> i) & 0x01;
          if(temp1 == 0x01){total1 = total1 + 1;}
             }       
                                              
         for(a; a < 8; a++){
            temp2 = (portB >> i) & 0x01;
          if( temp2  == 0x01){total2= total2 + 1;}                                                                              }       
                                                                                       
          PORTC = total1 + total2;
                                                                                                            
}	
	return 1; }
