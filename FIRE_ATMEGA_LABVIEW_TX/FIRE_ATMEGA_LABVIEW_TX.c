#include<avr/io.h>
#include<util/delay.h>
#include"lcd.h"

void main()
{
	DDRA&=~(1<<0);
	PORTA|=(1<<0);
	USARTInit(51);
	InitLCD(0);
	InitADC();
	LCDClear();
	LCDWriteStringXY(0,0,"LABVIEW GUI");
	LCDWriteStringXY(0,1,"With PROTEUS");
	_delay_ms(1000);
	LCDClear();
	LCDWriteStringXY(0,0,"FIRE M SYSTEM--------");
	_delay_ms(1000);
	while(1)
	{
		if(!(PINA&1))
		{
			uint8_t FSR1=10;
			LCDClear();
			LCDWriteStringXY(0,0,"FIRE DETECTED");			
			USARTWriteChar('a');
			_delay_ms(50);
		}
		else 
		{
			uint8_t FSR1=20;
			LCDClear();
			LCDWriteStringXY(0,0,"FIRE NO DETECTED ");			
			USARTWriteChar('b');
			_delay_ms(50);
		}
	}
}
			

