
#include <stdint.h>
#include <stdio.h>
#include "stm32f4xx.h"
#include "system_stm32f4xx.h"

#include "led.h"
#include "switch.h"
#include "lcd.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

extern int count;
char scount[15];
int pinState = 0;
int cState = 0;
int pState = 0;

int main(void)
{
	SystemInit();
	LedInit(LED_ORANGE);
	LcdInit();

	SwitchInit(SWITCH);
	while(1)
	{
		while(exti0_flag == 0)
		{
			if(cState == 0)
			{
				if(cState != pState)
				{
					count++;
					pState = cState;
				}
				else if(cState == pState)
				{
					count = count;
				}
			}
			LcdPuts(LCD_LINE1, itoa(count, scount, 10));
		}

		pState = 1;

		//count++;
		LedBlink(LED_ORANGE, 100);
		//LcdPuts(LCD_LINE1, itoa(count, scount, 10));
		exti0_flag = 0;
	}
	return 0;
}


