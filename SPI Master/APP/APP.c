/*
 * APP.c
 *
 * Created: 9/26/2021 5:55:54 PM
 *  Author: Mohamed El-Kholy
 */ 

#include "APP.h"

/* global Array Holds The Received Value from USART */
u8 global_u8DataStr[256];
u16 global_u16Size ;

void APP_voidInit(void)
{
	/* Initialize The USART */
	MUSART_voidUsartInit();
	/* Initialize SPI */
	MSPI_voidSPIinit();

}
void APP_voidUpdate(void)
{
	/* Receive the Incoming Data */
	MUSART_u8UsartReceiveString(global_u8DataStr,&global_u16Size);

	if (global_u16Size < 255)
	{
		/* Sent The Received Data Through Master SPI */
		MSPI_voidSPISendString(global_u8DataStr);
		
	}
	else 
	{
		/* Send String */
		MUSART_voidUsartSendString("You Mustn't Exceed 255 Char ");
		/* Clear Array Content */
		memset(global_u8DataStr, 0, 256);
		
	}
	

}
