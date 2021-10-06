/*
 * SPI Task Master.c
 *
 * Created: 9/26/2021 5:49:01 PM
 * Author : Mohamed El-Kholy
 */ 

#include "APP/APP.h"


int main(void)
{
    /* Call App Initialization */
	APP_voidInit();
    while (1) 
    {
		/* Call App update */
		APP_voidUpdate();
    }
}

