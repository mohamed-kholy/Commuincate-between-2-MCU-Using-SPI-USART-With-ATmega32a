/*
 * APP.c
 *
 * Created: 9/26/2021 5:55:54 PM
 *  Author: Mohamed El-Kholy
 */ 

#include "APP.h"

/* global Array Holds The Received Value from SPI */
u8 global_u8DataStr[10];

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
	MSPI_voidReceiveString(global_u8DataStr);
	/* Sent The Received Data Through UART */
	MUSART_voidUsartSendString(global_u8DataStr);
	/* Send New Line */
	MUSART_voidUsartSendChar('\r');
}
