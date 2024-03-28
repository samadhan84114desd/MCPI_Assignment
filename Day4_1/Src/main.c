#include <stdint.h>
#include <stdio.h>
#include "stm32f4xx.h"
#include "system_stm32f4xx.h"

#include "lcd.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
	SystemInit();
	LcdInit();
	//LcdPuts(LCD_LINE1, "DESD @ SUNBEAM");
	while(1)
	{
		LcdPuts(LCD_LINE2, "krishna          ");
		LcdPuts(LCD_LINE2, "rishna           k");
		LcdPuts(LCD_LINE2, "ishna           kr");
		LcdPuts(LCD_LINE2, "shna           kri");
		LcdPuts(LCD_LINE2, "hna           kris");
		LcdPuts(LCD_LINE2, "na           krish");
		LcdPuts(LCD_LINE2, "a           krishn");
		LcdPuts(LCD_LINE2, "           krishna");
    }
	return 0;
}







