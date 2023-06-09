/*******************************************************************
* AUTHOR  : Abdelrahman Osam Khaled
* DATE	  : 23 May , 2023
* SWC 	  : IR
* MC 	  : STM32F401X
* LAYER   : HAL
* VERSION : V1.0
********************************************************************/

#ifndef IR_INTERFACE_H
#define IR_INTERFACE_H

void HIR_voidInit(void);
void HIR_voidGetRemoteFrame(void);
void HIR_voidTakeAction(void);

/* global variable that carry the values of buttons*/
extern u8 Global_u8ButtonData;

#endif
