#ifndef 	UART_INTERFACE_H_
#define 	UART_INTERFACE_H_


/* Protype of the Function */
void MUSART_voidUsartInit(void);
void MUSART_voidUsartSendChar(u8 copy_u8Data);
u8 	 MUSART_u8UsartReceiveChar(void);
void MUSART_voidUsartSendString(u8 *copy_u8PtrData);
void MUSART_u8UsartReceiveString(u8 *copy_u8PtrStr);

#endif
