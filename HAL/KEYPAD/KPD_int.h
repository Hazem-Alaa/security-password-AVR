/*
 * KPD_int.h
 *
 * Created: 13/08/2024 02:05:55 م
 *  Author: hazem alaa
 */ 


#ifndef KPD_INT_H_
#define KPD_INT_H_

#include "../../lib/BIT_math.h"
#include "../../lib/STD_types.h"

#include "KPD_config.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include <util/delay.h>

void KPD_voidKPDInit();
u8   KPD_u8GetKey();


#endif /* KPD_INT_H_ */