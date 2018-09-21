/*
 * led_panel.c
 *
 * Created: 14-Sep-18 2:11:10 AM
 *  Author: Om
 */ 

#ifndef F_CPU
#define F_CPU 16000000
#endif

#include <stdint.h>
#include "shiftregister.h"
#include "macros.h"
#include "pin_def.h"
#include <string.h>
#include <util/delay.h>



void grid_panel(uint8_t x,uint8_t y) //x is 8 bit integer with each bit representing a cell
									//y is row to select
{
	SETBIT(GROUND_PORT,y1);    //row gets disabled when +5v
	SETBIT(GROUND_PORT,y2);
	SETBIT(GROUND_PORT,y3);
	SETBIT(GROUND_PORT,y4);
	SETBIT(GROUND_PORT,y5);
	SETBIT(GROUND_PORT,y6);
	shift_out(x); //shifting 8 bits to shift register
	switch (y)
	{
		case 1:
			CLEARBIT(GROUND_PORT,y1); //yth row gets enabled whrn grounded
			break;
		case 2:
			CLEARBIT(GROUND_PORT,y2);
			break;
		case 3:
			CLEARBIT(GROUND_PORT,y3);
			break;
		case 4:
			CLEARBIT(GROUND_PORT,y4);
			break;
		case 5:
			CLEARBIT(GROUND_PORT,y5);
			break;
		case 6:
			CLEARBIT(GROUND_PORT,y6);
			break;	
	}
}

