/*
* DIO_interface.h
*
* Created: 9/8/2024 2:13:52 PM
*  Author: hazem alaa
*/



#include "../MCAL/DIO/DIO_interface.h"
#include "../HAL/KEYPAD/KPD_int.h"
#include "../HAL/LCD/LCD_int.h"
#include "../service/security_pass/security_prototype.h"

int main(void)
{
	
	LCD_voidLCDInit();
	KPD_voidKPDInit();

	while (1)
	{
		show_result();
	}
}