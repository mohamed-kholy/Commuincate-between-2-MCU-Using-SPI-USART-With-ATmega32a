#ifndef 	UART_CONFIG_H_
#define 	UART_CONFIG_H_

#define F_CPU 8000000UL		/* Define frequency here its 8MHz */

/* OPTIONS

	*ENABLE
	*DISABLE
*/


#define 	USART_RECEIVER		ENABLE
#define 	USART_TRANSMITTE	DISABLE



/* Options 

	*2400
	*4800
	*9600
	*14400
	*19200
	*28800
	*38400
	*57600
	*76800
	*155200
	*230400
	*250000
*/
	
#define USART_BAUDRATE 9600



/* Options 
	*SYNC_MODE
	*ASYNC_MODE
	*MULTI_PROCESS_MODE
*/
#define 	USART_MODE			SYNC_MODE

/* OPTIONS
	*_9_BITS
	*_8_BITS
	*_7_BITS
	*_6_BITS
	*_5_BITS
	*/
#define 	NUMBER_OF_TRANSMIT_BITS			_8_BITS

/* OPTIONS
	* DISABLE
	* EVEN_PARITY
	* ODD_PARITY
*/
#define 	PARITY_MODE			DISABLE

/* OPTIONS
	* _1_BIT
	* _2_BIT
*/
#define 	STOP_BIT			_1_BIT

/* OPTIONS

	*ENABLE
	*DISABLE
*/

#define 	 RECEIVE_COMPLETE_INTERRUPT		   DISABLE
#define 	 TRANSMIT_COMPLETE_INTERRUPT		DISABLE
#define 	 DATA_REGISTERY_EMPTY_INTERRRUPT	DISABLE



#endif
