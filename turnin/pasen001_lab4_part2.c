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
enum Cnt_States { Start, Init, inc_Press, inc_Rel, dec_Press, dec_Rel, reset_press, reset_rel} cnt_State;

void Tick_CNT() {
	unsigned char button;
	button = PINA & 0x03;
	switch(cnt_State){
	case Start:
		cnt_State = Init;
		break;
	case Init:
		if ( button == 0x01 ) {
			cnt_State = inc_Press;
			PORTC = PINC + 1;
		} 
		else if (button == 0x02){
			cnt_State = dec_Press;
			PORTC = PINC - 1;
		}
		else if (button == 0x03){
			cnt_State = reset_press;
			PORTC = 0x00;
		}
		else {cnt_State = Init;}
		break;
	// increase actions
	case inc_Press:
		if ( button == 0x00 ) {
			cnt_State = inc_Rel;
		}
		else cnt_State = inc_Press;
		break;
	case inc_Rel:
		cnt_State = Init;
		break;
	// decrease actions
	case dec_Press:
                if ( button == 0x00 ) {
                        cnt_State = dec_Rel;
                }
                else cnt_State = dec_Press;
                break;
        case dec_Rel:
                cnt_State = Init;
                break;
	//reset actions
	case reset_press:
		if (button == 0x00) {
			cnt_State = reset_rel;
		}
		break;
	case reset_rel:
		cnt_State = Init;
		break;
	default: 
		cnt_State = Start;
		break;	
	}//trasition actions
	switch(cnt_State){
	case Start:
		break;
	case Init:
		break;
	case inc_Press:
		break;
	case inc_Rel:
		break;
	case dec_Press:
		break;
	case dec_Rel:
		break;
	case reset_press:
		break;
	case reset_rel:
		break;
	default:
		break;
	}
}
int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0x00;
	DDRC = 0xFF; PORTC = 0x00;
    /* Insert your solution below */
	cnt_State = Start;
	PORTC = 0x07;
    while (1) {
	Tick_CNT();	
    }
    return 1;
}
