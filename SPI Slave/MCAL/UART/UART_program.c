#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "UART_register.h"
#include "UART_config.h"
#include "UART_interface.h"


#define			ENTER_ASCII			13

		/* Caculate the Baud Rate */
#define BAUD_PRESCALE (((F_CPU / (USART_BAUDRATE * 16UL))))*2

/********************************************************************************************************************************
* Parameters:(in) : None
* Parameters:(out): None
* Return value	  : none
* Description	  : Function used to initialize the USART based on the Configuration file
**********************************************************************************************************************************/

void MUSART_voidUsartInit(void)
{
	/* In case of synchronization mode is on */
	#if USART_MODE == SYNC_MODE
		SET_BIT (UCSRC , UMSEL );
	/* In case of Asynchronization mode is on */
	#elif USART_MODE == ASYNC_MODE
		CLR_BIT (UCSRC , UMSEL );
	/* In case of Multiple Process mode is on */	
	#elif USART_MODE == MULTI_PROCESS_MODE 
		SET_BIT (UCSRA , MPCM ) ;
	#endif 
	/* In case of The Transmission Bits is 9 bits */
	#if NUMBER_OF_TRANSMIT_BITS == _9_BITS 
		SET_BIT (UCSRB , UCSZ2 );
		SET_BIT (UCSRC , UCSZ1 );
		SET_BIT (UCSRB , UCSZ0 );
	/* In case of The Transmission Bits is 8 bits */
	#elif NUMBER_OF_TRANSMIT_BITS == _8_BITS
		CLR_BIT (UCSRB , UCSZ2 );
		SET_BIT (UCSRC , UCSZ1 );
		SET_BIT (UCSRB , UCSZ0 );
	/* In case of The Transmission Bits is 7 bits */
	#elif NUMBER_OF_TRANSMIT_BITS == _7_BITS
		CLR_BIT (UCSRB , UCSZ2 );
		SET_BIT (UCSRC , UCSZ1 );
		CLR_BIT (UCSRB , UCSZ0 );
	/* In case of The Transmission Bits is 6 bits */
	#elif NUMBER_OF_TRANSMIT_BITS == _6_BITS
		CLR_BIT (UCSRB , UCSZ2 );
		CLR_BIT (UCSRC , UCSZ1 );
		SET_BIT (UCSRB , UCSZ0 );
	/* In case of The Transmission Bits is 5 bits */
	#elif NUMBER_OF_TRANSMIT_BITS == _5_BITS
		CLR_BIT (UCSRB , UCSZ2 );
		CLR_BIT (UCSRC , UCSZ1 );
		CLR_BIT (UCSRB , UCSZ0 );
	#endif
	/* In case of Parity Mode is Disabled*/
	#if PARITY_MODE == DISABLE
		CLR_BIT (UCSRC , UPM0 );
		CLR_BIT (UCSRC , UPM1 );
	/* In case of Parity Mode is Even Parity */
	#elif PARITY_MODE == EVEN_PARITY
		CLR_BIT (UCSRC , UPM0 );
		SET_BIT (UCSRC , UPM1 );
	/* In case of Parity Mode is Odd Parity*/
	#elif PARITY_MODE == EVEN_PARITY
		SET_BIT (UCSRC , UPM0 );
		SET_BIT (UCSRC , UPM1 );
	#endif 
	/* In case of Number of Stop Bits is 1 bit*/
	#if STOP_BIT == _1_BIT
		CLR_BIT (UCSRC , USBS );
	/* In case of Number of Stop Bits is 2 bits*/
	#elif STOP_BIT == _2_BIT
		SET_BIT (UCSRC , USBS );	
	#endif
	/* In case of Receive Complete Interrupt is Enabled*/
	#if RECEIVE_COMPLETE_INTERRUPT == ENABLE
		SET_BIT (UCSRB , RXCIE );
	/* In case of Receive Complete Interrupt is Disabled*/
	#elif RECEIVE_COMPLETE_INTERRUPT == DISABLE
		CLR_BIT (UCSRB , RXCIE );
	#endif
	/* In case of Transmit Complete Interrupt is Enabled*/
	#if TRANSMIT_COMPLETE_INTERRUPT == ENABLE
		SET_BIT (UCSRB , TXCIE );
	/* In case of Transmit Complete Interrupt is Disabled*/
	#elif TRANSMIT_COMPLETE_INTERRUPT == DISABLE
		CLR_BIT (UCSRB , TXCIE );
	#endif
	/* In case of Data Register Empty Interrupt is Enabled*/
	#if DATA_REGISTERY_EMPTY_INTERRRUPT == ENABLE
		SET_BIT (UCSRB , UDRIE );
	/* In case of Data Register Empty Interrupt is Disabled*/
	#elif DATA_REGISTERY_EMPTY_INTERRRUPT == DISABLE
		CLR_BIT (UCSRB , UDRIE );
	#endif
	/* in Case of USART Receiver is Enabled */
	#if USART_RECEIVER == ENABLE
		SET_BIT (UCSRB , RXEN );
	/* in Case of USART Receiver is DISABLE */	
	#elif USART_RECEIVER == DISABLE
		CLR_BIT (UCSRB , RXEN );
	#endif
	/* in Case of USART Transmitter is Enabled */
	#if USART_TRANSMITTE == ENABLE
		SET_BIT (UCSRB , TXEN );
	/* in Case of USART Transmitter is DISABLED */
	#elif USART_TRANSMITTE == DISABLE
		CLR_BIT (UCSRB , TXEN );
	#endif
	/* Set U2X Bit */
	SET_BIT (UCSRA , U2X );
	/* Load upper 8-bits */
	UBRRH = (BAUD_PRESCALE >> 8);
	/* Load lower 8-bits of the baud rate */
	UBRRL = BAUD_PRESCALE;

}

/********************************************************************************************************************************
* Parameters:(in) : Character Data
* Parameters:(out): None
* Return value	  : none
* Description	  : Function used to send Char Through USART
**********************************************************************************************************************************/
void MUSART_voidUsartSendChar(u8 copy_u8Data)
{
	/* Wait until The Buffer is Empty */
	while (!GET_BIT (UCSRA , UDRE));
	/* Send The Data To UDR */
	UDR = copy_u8Data ;
	
}

/********************************************************************************************************************************
* Parameters:(in) : None
* Parameters:(out): None
* Return value	  : 8 bit unsigned char holds the Received Data from USART
* Description	  : Function used to Receive Char Through USART
**********************************************************************************************************************************/
u8 	 MUSART_u8UsartReceiveChar(void)
{
	/* Wait until The Data Arrived */
	while (!GET_BIT (UCSRA , RXC));
	/* Receive The Data From UDR */
	return UDR ;
}

/********************************************************************************************************************************
* Parameters:(in) : Pointer To 8-bit unsigned Char
* Parameters:(out): None
* Return value	  : None
* Description	  : Function used to Send Stream Of Characters Through USART
**********************************************************************************************************************************/
void MUSART_voidUsartSendString(u8 *copy_u8PtrData)
{
	/* local Variable */
	u8 local_u8Indx = 0 ;
	/* If the incoming Data not Empty */
	while(copy_u8PtrData[local_u8Indx] != '\0')
	{
		/* Send Every Char */
		MUSART_voidUsartSendChar(copy_u8PtrData[local_u8Indx]);
		/* increment The Index */
		local_u8Indx++;
	}
}

/********************************************************************************************************************************
* Parameters:(in) : Pointer To 8-bit unsigned Char
* Parameters:(out): Pointer To 8-bit unsigned Char 
* Return value	  : None
* Description	  : Function used to Receive Stream Of Characters From USART
**********************************************************************************************************************************/
void MUSART_u8UsartReceiveString(u8 *copy_u8PtrStr)
{
	/* local Index */
	u8 local_u8Indx = 0 ;
	/* Receive the First char And Store it in the incoming Array */
	copy_u8PtrStr[local_u8Indx] = MUSART_u8UsartReceiveChar() ;
	/* Stop When the User press Enter */
	while(copy_u8PtrStr[local_u8Indx]  != ENTER_ASCII)
	{
		/* increment the index */	
		local_u8Indx++;
		/* Receive every character and store it in the incoming Array */
		copy_u8PtrStr[local_u8Indx] = MUSART_u8UsartReceiveChar() ;
	
	}
	/* Clear the last Char */
	copy_u8PtrStr[local_u8Indx] ='\0';
}

