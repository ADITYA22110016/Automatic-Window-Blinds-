#include <avr/io.h>
#include <util/delay.h>
#define F_CPU16000000UL;

int main(void)
{
	DDRD=0xFF;  
	DDRC=0x00;  
	DDRB=0xFF; 
	
	 
	TCCR0A |= (1<<WGM01)|(1<<WGM00);  
	TCCR0B &= (~(1<<WGM02));
	
	
	TCCR0A |= (1<<COM0A1);
	TCCR0A &= (~(1<<COM0A0));
	TCCR0A |= (1<<COM0B1);
	TCCR0A &= (~(1<<COM0B0));
	
	
	TCCR0B |= (1<<CS01)|(CS00);  
	TCCR0B &= (~(1<<CS02));
	
	
	DDRD |= (1<<DDD5) | (1<<DDD6);
	
	
	while (1)
	{
		OCR0A=75;  
		
		if(PINC==0b00000001)    
		{
			PORTB=0b00000001;
			_delay_ms(500);
				
		}
		else
		{
			
			PORTB=0b00000010;
			_delay_ms(500);
		}
		
	}
}