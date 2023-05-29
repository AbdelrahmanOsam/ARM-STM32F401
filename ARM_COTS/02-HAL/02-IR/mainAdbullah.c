/*
 * main.c
 *
 *  Created on: May 23, 2023
 *      Author: Abd El Rahman
 */



#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "SYSTICK_interface.h"
#include "NVIC_interface.h"
#include "EXTI_interface.h"
#include "IR_interface.h"
#include "SYSCFG_interface.h"

void App_GetFrame(void);
void APP_TakeAction(void);
u8 APP_u8StartEdgeFlag = 0;
u32 APP_ReceivedFrame[50] = {0};
u8 APP_u8EdgeCounter = 0;
u8 APP_u8ButtonData = 0;

void main (void)
{
		/*Initialize RCC */
	MRCC_voidInit();
		/* Initialize GPIO */
	MGPIO_voidInit();
		/* Initialize NVIC */
	MNVIC_voidInit();
		/* Initialize SysTick */
	MSTK_voidInit();
		/* Enable GPIOA peripheral */
	MRCC_voidEnablePeripheralClock(RCC_AHB1,RCC_GPIOA);
		/* Set A0 as input pin */
	MGPIO_voidSetPinMode(GPIO_PORTA,GPIO_PIN0,GPIO_MODE_INPUT);
		/* Set A0 as input pull up*/
	MGPIO_voidSetPinPullMode(GPIO_PORTA,GPIO_PIN0,GPIO_PULL_UP);

	MSTK_voidEnableSTK();
	MSTK_voidEnableInterrupt();
		/* Initialize EXTI */
	//MEXTI_voidInit();
		/* Set falling edge as sense mode */
	MEXTI_ChangeSenseMode(0,MEXTI_FALLING_EDGE);
		/* Select Port a for EXTI line 0 */
	//MSYSCFG_voidSetEXTISourceInput(0,SYSCFG_PORTA);
		/* Set FUNC function in EXTI0 call back function */
	MEXTI_voidSetCallBack(0,&App_GetFrame);
		/* Enable interrupt for EXTI0 */
	MEXTI_voidEnableInterrupt(0);

		/* Enable EXTI0 interrupt */
	MNVIC_voidEnablePeripheralInterrupt(MNVIC_EXTI0);
	while(1)
	{

	}
}

void App_GetFrame(void)
{
	if(APP_u8StartEdgeFlag == 0)
	{
		MSTK_voidSetSingleInterval(700000,&APP_TakeAction);
		APP_u8StartEdgeFlag = 1;
	}
	else
	{
		/* Get the counted time */
		APP_ReceivedFrame[APP_u8EdgeCounter] = MSTK_u32GetElapsedTime();
		/* Reset the timer */
		//MSTK_voidResetSysTick();
		/* Set Preload Value */
		MSTK_voidSetSingleInterval(700000,&APP_TakeAction);
		/* Increment edge counter */
		APP_u8EdgeCounter++;
	}
}
void APP_TakeAction(void)
{
	u8 Local_u8LoopCounter = 0;
	for(Local_u8LoopCounter = 0;Local_u8LoopCounter<8;Local_u8LoopCounter++)
	{
		if((APP_ReceivedFrame[17+Local_u8LoopCounter] >= 1000)&&(APP_ReceivedFrame[17+Local_u8LoopCounter] <=1500))
		{
			CLEAR_BIT(APP_u8ButtonData,Local_u8LoopCounter);
		}
		else
		{
			SET_BIT(APP_u8ButtonData,Local_u8LoopCounter);
		}
	}
}
void APP_voidPlay(void)
{
	switch(APP_u8ButtonData)
	{
		case 24 :
			asm("NOP");
		break;
		case 69 :
			asm("NOP");
		break;
	}
}

