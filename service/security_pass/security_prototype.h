/*
 * security_prototype.h
 *
 * Created: 16 - 9 - 2024 2  :  47  :  35 PM
 *  Author: Abu_El_A7ZaaM
 */ 


#ifndef SECURITY_PROTOTYPE_H_
#define SECURITY_PROTOTYPE_H_

#include "../../MCAL/DIO/DIO_interface.h"
#include "../../service/security_pass/security_prototype.h"
#include "../../LIB/BIT_math.h"
#include "../../LIB/STD_types.h"


void show_result(void);
u16 Getpass(void);
u8 CheckPassword(u16 EnteredPass , u16 CheckPass);


#endif /* SECURITY_PROTOTYPE_H_ */