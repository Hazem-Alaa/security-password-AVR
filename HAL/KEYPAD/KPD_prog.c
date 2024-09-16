/*
 * KPD_prog.c
 *
 * Created: 13/08/2024 02:06:56 م
 *  Author: hazem alaa
 */ 



#include "KPD_int.h"
u8 KPD_GRID[4][4]={
	{7  ,8 , 9 ,'/'}, //R 0
	{4  ,5 , 6 ,'*'}, //R 1
	{1  ,2 , 3 ,'-'}, //R 2
	{'C',0 ,'=','+'}  //R 3
//   C0  C1 C2  C3
};
void KPD_voidKPDInit()
{
DIO_voidSetPortDir(KPD_PORT, 0b00001111);
DIO_voidSetPortVal(KPD_PORT, 0b11111111);		
}


u8   KPD_u8GetKey()
{
	u8 key=255;
	
	for( u8 col =0 ; col <COLNUM; col++)
	{
		
		DIO_voidSetPinVal(KPD_PORT,col, LOW);
		
		for ( u8 row = ROWSNUM ; row < COLNUM+ROWSNUM; row++ ) // 4 -> 7
		{
			
			if ( DIO_u8GetPinVal(KPD_PORT,row) ==LOW)
			{
				key = KPD_GRID [row-ROWSNUM][col];
			}
			
			while(DIO_u8GetPinVal(KPD_PORT,row ) == LOW);
			/*_delay_ms(10);*/
		}
			
		DIO_voidSetPinVal(KPD_PORT,col,HIGH);
	}
	return key;
}
