/*
* CFile1.c
*
* Created: 14/08/2024 10:38:08 ص
*  Author: hazem alaa
*/

#include "LCD_int.h"

void LCD_voidSendCMD(u8 u8CMD)//Send Instruction to LCD
{

	DIO_voidSetPinVal(LCD_RS,LOW);	    // set Rs = 0 to send or receive command
	DIO_voidSetPinVal(LCD_RW,LOW);	    // set Rs = 0 to send data to lcd (write)
	DIO_voidSetPortVal(LCD_PORT,u8CMD); //put command on the port
	
	// 	enable high and low to send by high and low in this pin
	DIO_voidSetPinVal(LCD_E,HIGH);
	DIO_voidSetPinVal(LCD_E,LOW);
	_delay_ms(5); // this delay from data sheet 
}


void LCD_voidWriteChar(u8 u8CHAR) //Send data to LCD
{
	DIO_voidSetPinVal(LCD_RS,HIGH);       // set Rs = 0 to send or receive data
	DIO_voidSetPinVal(LCD_RW,LOW);		  // set Rs = 0 to send data to lcd (write)
	DIO_voidSetPortVal(LCD_PORT,u8CHAR);  //put command on the port
	
	// 	enable high and low to send by high and low in this pin
	DIO_voidSetPinVal(LCD_E, HIGH);
	DIO_voidSetPinVal(LCD_E, LOW);
	_delay_ms(5);
}

void LCD_voidLCDInit(){
	
	DIO_voidSetPinDir(LCD_RS,OUTPUT);             //in this line we config the pin
	DIO_voidSetPinDir(LCD_RW,OUTPUT); 			  //in this line we config the pin
	DIO_voidSetPinDir(LCD_E,OUTPUT);			  //in this line we config the pin
	DIO_voidSetPortDir(LCD_PORT,DIO_PORT_OUTPUT);//in this line we config the pin
	
	_delay_ms(31); //this form the data sheet 
	LCD_voidSendCMD(LCD_FUNSET_8BIT); // select (8 - bit mode OR 4 - bit mode)
	_delay_us(40);//this form the data sheet 
	LCD_voidSendCMD(LCD_DISPON_CURON); // display on or off to the cursor 
	_delay_us(40);//this form the data sheet 
	LCD_voidSendCMD(LCD_CLR); // clear the lcd before write 
	_delay_ms(1.54);//this form the data sheet 
	LCD_voidSendCMD(LCD_ENTRY_MODE); // shift data form right to left or reverse 
	_delay_ms(2);//this form the data sheet 

}

void LCD_voidGoTo(u8 X, u8 Y)
{
	if (X>0 && X<=16)
	{
		switch(Y)
		{
			case 1: LCD_voidSendCMD(127+X);break; // adress the first line equal 0x80
			case 2: LCD_voidSendCMD(191+X);break; // adress the first line equal 0xc0
			default:break;
		}
	}
}

/*this function used to clear the data on the lcd */
void LCD_ClrLCD()
{
	LCD_voidSendCMD(LCD_CLR);
	_delay_ms(2);
	
}

// this function used to send string to lcd
void LCD_voidWriteStrig(u8 *ptrStr)
{
	u8 counter=0;
	
	while(ptrStr[counter]!='\0')
	{
		LCD_voidWriteChar(ptrStr[counter]);
		counter++;
	}
	
}

// this function used to send number to lcd
void LCD_voidWriteNum(s32 s32NUM) // put datatype from s32 to receve large number 
{
	u32 temp= 1;
	if(s32NUM==0){
		LCD_voidWriteChar('0');
	}

	if(s32NUM<0){
		LCD_voidWriteChar('-');
		s32NUM*=-1; // s32NUM = s32NUM * -1;
	}
	while(s32NUM!=0)
	{
		temp= (temp*10)+s32NUM%10;
		s32NUM/=10; //s32NUM = s32NUM / 10;
	}
	while(temp !=1)
	{
		LCD_voidWriteChar((temp%10)+48);
		temp/=10;
	}
}

void LCD_voidSaveCustomChar(u8 CGRAMIndex, u8 CustomChar[])
{
	
	LCD_voidSendCMD(LCD_CGRAM_ADDRESS+CGRAMIndex*8);
	
	for(u8 i = 0 ; i<8; i++)
	{
		
		LCD_voidWriteChar(CustomChar[i]);
	}
	
	LCD_voidSendCMD(LCD_DDRAM_SETCURS);
}

void LCD_voidWriteCustomChar(u8 CGRAMIndex)
{
	if(CGRAMIndex)
	{
		LCD_voidWriteChar(CGRAMIndex);
		
	}
}
