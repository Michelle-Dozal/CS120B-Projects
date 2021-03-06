/*	Author: mdoza001
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #3  Exercise #3
 **	Exercise Description: [optional - include for your own benefit]
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
	DDRC = 0xFF; PORTC = 0x00;
    /* Insert your solution below */
	unsigned char input;
	unsigned char fuel;
	unsigned char per;
	unsigned char igni;
	unsigned char beltl;
   ///	input = PINA;
	 while (1) {
     input = PINA;
         per = PINA & 0x20;
         igni = PINA & 0x10;
         beltl = PINA & 0x40;
	   if((input & 0x00) == 0x00){fuel = 0x00;}
	 if((input& 0x01) == 0x01){fuel = 0x60;}
	  if((input & 0x02) == 0x02){fuel = 0x60;}
	  if((input & 0x03) == 0x03){fuel = 0x70;}
	  if((input & 0x04) == 0x04){fuel = 0x70;}
	  if((input & 0x05) == 0x05){fuel = 0x38;}
	  if((input & 0x06) == 0x06){fuel = 0x38;}
	  if((input & 0x07) == 0x07){fuel = 0x3C;}
	  if((input & 0x08) == 0x08){fuel = 0x3C;}
	  if((input &  0x09) == 0x09){fuel = 0x3C;}
	  if((input &  0x0A) == 0x0A){fuel = 0x3E;}
	  if((input & 0x0B) == 0x0B){fuel = 0x3E;}
	  if((input &  0x0C) == 0x0C){fuel = 0x3E;}
	  if((input & 0x0D)  == 0x0D){fuel = 0x3F;}
	  if((input &  0x0E) == 0x0E){fuel = 0x3F;}
	  if((input &  0x0F) == 0x0F){fuel = 0x3F;}
		
    if(igni == 0x10){
        if(per != 0x20){
            PORTC = fuel;}
        
    }

    if(igni == 0x10){
        if (per == 0x20){
            if(beltl != 0x40){
                PORTC = fuel | 0x80 | input;}
                else {PORTC = fuel;}
                }
                }
   else { PORTC = fuel;}
    }
    return 1;
}
