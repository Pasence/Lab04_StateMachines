/*	Author: pasen001
 *  Partner(s) Name: Peter John Asence
 *	Lab Section:
 *	Assignment: Lab #4  Exercise #1
 *	Exercise Description: alternating led lights based on button press.
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif
enum LED_States { Start, OFF_rel, On_press, On_rel, OFF_press} LED_State;

void Tick_LED() {
	unsigned char button;
	button = PINA & 0x01;
	switch(LED_State){
	case Start:
		PORTB = 0x01;
		LED_State = OFF_rel;
		break;
	case OFF_rel:
		if ( button == 0x01 ) {
			LED_State = On_press;
			PORTB = 0x02;
		} 
		else LED_State = OFF_rel;
		break;
	case On_press:
		if ( button == 0x00 ) {
			LED_State = On_rel;
		}
		else LED_State = On_press;
		break;
	case On_rel:
		if ( button == 0x01) {
			LED_State = OFF_press;
			PORTB = 0x01;
		}
		else LED_State = On_rel;
		break;
	case OFF_press:
		if (button == 0x00) LED_State = OFF_press;
		else LED_State = OFF_rel;
		break;
	default: 
		LED_State = Start;
		break;	
	}//trasition actions
	switch(LED_State){
	case Start:
		break;
	case OFF_rel:
		break;
	case On_press:
		break;
	case On_rel:
		break;
	case OFF_rel:
		break;
	default:
		break;
	}
}
int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0x00;
	DDRB = 0xFF; PORTB = 0x00;
    /* Insert your solution below */
	LED_State = Start;
    while (1) {
	Tick_LED();	
    }
    return 1;
}
