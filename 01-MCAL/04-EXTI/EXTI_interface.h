/*******************************************************************
* AUTHOR  : Abdelrahman Osam Khaled
* DATE	  : 22 May , 2023
* SWC 	  : EXTI
* MC 	  : STM32F401X
* LAYER   : MCAL
* VERSION : V1.0
********************************************************************/

#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

void MEXTI_voidInit(void);
void MEXTI_voidEnableInterrupt(u8 Copy_u8EXTILine);
void MEXTI_voidDisableInterrupt(u8 Copy_u8EXTILine);
void MEXTI_ChangeSenseMode(u8 Copy_u8EXTILine, u8 Copy_u8SenseSignal);
void MEXTI_voidSetCallBack(u8 Copy_u8EXTILine, void (*pvNotificationFunction)(void));

/* Macros for sense modes */
#define MEXTI_RISING_EDGE 		0
#define MEXTI_FALLING_EDGE		1
#define MEXTI_ON_CHANGE			2