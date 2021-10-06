/*
 * APP.h
 *
 * Created: 9/26/2021 5:56:05 PM
 *  Author: Mohamed El-Kholy
 */ 


#ifndef APP_H_
#define APP_H_

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/SPI/SPI_interface.h"
#include "../MCAL/UART/UART_interface.h"
#include <string.h>

void APP_voidInit(void);
void APP_voidUpdate(void);


#endif /* APP_H_ */