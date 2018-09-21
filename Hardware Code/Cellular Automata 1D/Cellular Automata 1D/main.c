/*
 * Shift registe.c
 *
 * Created: 12-Sep-18 5:17:06 PM
 * Author : Om
 */ 

#ifndef F_CPU
#define F_CPU 16000000
#endif

#include <avr/io.h>
#include <stdint.h>
#include <util/delay.h>
#include "pin_def.h"
#include "macros.h"
#include "shiftregister.h"
#include "led_panel.h"
#define rule ^

volatile uint8_t current,next,test;

uint8_t frame_buffer[6]; 
int main(void)
{	
	
	enable_shiftreg();
	
	current=0b11010100; //genration 0
	next=0b00000000;	//succeding generation
	
	
	
	while (1) 
	{	
		for(uint8_t row=1;row<7;row++) //to store each generation in next row
		{
			frame_buffer[row-1]=current;
			for(uint16_t j=0;j<50;j++) //loop to control speed of simulation
			{

				for(int i=1;i<7;i++) //loop to display 1 frame i.e. 6 rows all at once
				{

					grid_panel(frame_buffer[i-1],i);
					latch_pulse();
					_delay_ms(1);

				}
			}
			for(uint8_t i=0;i<8;i++) //loop over all cells(7-0)
			{

				switch (i) 
				{
					case 0: //special case to avoid index 0-1 error
					if(0 rule (!!(current & (1<<(i+1)))))
					{
						next|=(1<<i); //set (7-i)th bit 1
					}
					else
					{
						next&=~(1<<i); //set (7-i)th bit 0
					}
					break;

					case 7: //special case to avoid index 7+1 error
					if((!!(current & (1<<(i-1)))) rule 0)
					{
						next|=(1<<i); 
					}
					else
					{

						next&=~(1<<i);
					}
					break;

					default:
					if((!!(current & (1<<(i-1)))) rule (!!(current & (1<<(i+1))))) //check bit i-1 and i+i
					{

						next|=(1<<i);
					}
					else
					{
						next&=~(1<<i);
					}
				}
			}
			current=next; //next gen act as current for the next gen
		}
	}
}
