/*
* Prog.c
*
* Created: 16 - 9 - 2024 2  :  47  :  01 PM
*  Author: Abu_El_A7ZaaM
*/

#include "security_prototype.h"


u8 CheckPassword(u16 EnteredPass , u16 CheckPass)
{
	u16 val=EnteredPass;
	u8 flag=0;
	u8  res=0;
	if(val !=255)
	{
		if(val == CheckPass)
		{
			val=0;
			flag=1;
			res=1;
		}
		
		else if(flag ==0 && val != CheckPass)
		{
			flag=2;
			res = 0;
		}
	}
	return res;
}


u16 Getpass(void)
{
	u16 enterpass=255;
	u16 res=0;
	u8 count=0;
	u8 key=255;
	u8 i=0; // this for counter
	do
	{
		enterpass=KPD_u8GetKey();
		if(enterpass !=255)
		{
			LCD_voidWriteNum(enterpass);
			
			res=enterpass+res;
			key=KPD_u8GetKey();
			count++;
		}
		if(i<3 && enterpass !=255)
		{
			res*=10;
			i++;
		}
		
	}while(key == 255 && count !=4);
	
	_delay_ms(100);
	return res;
}


void show_result(void)
{
	
	u8 res=0;
	u8 count=0;
	u16 checkpass=1234;
	
	u16 enteredpass=Getpass();
	
	res = CheckPassword(enteredpass,checkpass);
	if (res == 1)
	{
		
		LCD_ClrLCD();
		LCD_voidWriteStrig("Correct Password");
		_delay_ms(100);
		LCD_ClrLCD();

	}
	else if (res == 0 && count < 3)
	{
		
		LCD_ClrLCD();
		LCD_voidWriteStrig("faild Password");
		_delay_ms(100);
		LCD_ClrLCD();
		LCD_voidWriteStrig("Re-enter Password");
		_delay_ms(100);
		LCD_ClrLCD();
		count++;
	}
	else if(count ==3)
	{
		LCD_ClrLCD();
		LCD_voidWriteStrig("final");
	}
}


