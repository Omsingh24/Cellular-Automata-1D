/*
 * shiftregister.c
 *
 * Created: 12-Sep-18 5:17:47 PM
 *  Author: Om
 */ 

#include <stdint.h>
#include "macros.h"
#include "pin_def.h"

void enable_shiftreg()
{
	DDRB |= ((1<<DDB2) | (1<<DDB3) | (1<<DDB4)); //Data direction register set to 1 for output port enable
	DDRD |= ((1<<DDD7) | (1<<DDD2) | (1<<DDD3) |(1<<DDD4) |(1<<DDD5) |(1<<DDD6));//Data direction register set to 1 for output port enable
}


void clock_pulse() //clock pulse to shift register
{
	SETBIT (CLOCK_PORT,CLOCK_PIN);
	CLEARBIT (CLOCK_PORT,CLOCK_PIN);
	
}

void latch_pulse()//latch pulse to shift register
{
	
	SETBIT(LATCH_PORT,LATCH_PIN);
	CLEARBIT(LATCH_PORT,LATCH_PIN);
}



void shift_out(uint8_t value) //shift 8 bits to shift register //note latching is manual
{
	
	uint8_t i;
	
	CLEARBIT(LATCH_PORT,LATCH_PIN);
	
	for (i = 0; i < 8; i++) //loop over 8 bits in integer and shift to register
	 {
		if (!!(value & (1<<(i)))) //checking the ith bit of innteger
		{
			SETBIT(DATA_PORT,DATA_PIN);	//data pin set to 1 if ith  bit is 1
		}
		else
		{
			CLEARBIT(DATA_PORT,DATA_PIN); //data pin set to 0 if ith bit is 0
		}
		clock_pulse(); //shifting 1 bit on clock pulse
	}
}
