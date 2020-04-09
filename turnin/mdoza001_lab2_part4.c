/*	Author: mdoza001
 *	Lab Section: 24
 *	Assignmen: Lab #1  Exercise #4
 *	Exercise Description: Park Ride
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
	DDRC = 0X00; PORTC = 0XFF;
        DDRD = 0xFF; PORTD = 0x00;
	
	unsigned char weightA, weightB, weightC, temp1,temp2,temp3;
	unsigned short total;
	
 //sol	
  /* Insert your solution below */
    while (1) {

	weightA = PINA;
	weightB = PINB;
	weightC = PINC;
	total = weightA + weightB + weightC;

	if(total > 0x008C){temp1 = 0x01;}
	else {temp1 = 0x00;}
	if((abs(weightA-weightC))> 0x50){temp2 = 0x02;}
	else {temp2 = 0x00;}
	//PORTD = temp1 | temp2;
	total = total & 0xFC;//1111 1100
	PORTD = (total + temp1 + temp2);


}
    return 1;
}
