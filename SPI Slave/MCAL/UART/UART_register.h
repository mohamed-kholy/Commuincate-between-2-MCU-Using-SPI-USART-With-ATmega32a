#ifndef 	UART_REGISTER_H_
#define 	UART_REGISTER_H_



/* Define Of the Registers */

#define 		UBRRH			*((volatile u8 *)(0X40))
#define 		UCSRC			*((volatile u8 *)(0X40))
#define 		UDR				*((volatile u8 *)(0X2C))
#define 		UCSRA			*((volatile u8 *)(0X2B))
#define 		UCSRB			*((volatile u8 *)(0X2A))
#define 		UBRRL			*((volatile u8 *)(0X29))

/* UCSRA Registers Bits Definations */
#define			RXC				7
#define			TXC				6
#define			UDRE			5
#define			FE				4
#define			DOR				3
#define			PE				2
#define			U2X				1
#define			MPCM			0
/* UCSRB Registers Bits Definations */
#define			RXCIE			7
#define			TXCIE			6
#define			UDRIE			5
#define			RXEN			4
#define			TXEN			3
#define			UCSZ2			2
#define			RXB8			1
#define			TXB8			0
/* UCSRC Registers Bits Definations */
#define			URSEL			7
#define			UMSEL			6
#define			UPM1			5
#define			UPM0			4
#define			USBS			3
#define			UCSZ1			2
#define			UCSZ0			1
#define			UCPOL			0


/* Macros Definiations */
#define 	ENABLE				1
#define 	DISABLE				0
#define 	_9_BITS				9
#define     _8_BITS				8
#define     _7_BITS				7
#define     _6_BITS				6
#define		_5_BITS				5
#define		_1_BIT				1
#define 	_2_BIT				2
#define 	EVEN_PARITY			1
#define     ODD_PARITY			2
#define		SYNC_MODE			0
#define     ASYNC_MODE			1
#define     MULTI_PROCESS_MODE	2


#endif      