/*
 * main.c
 *
 *  Created on: ???/???/????
 *      Author: mahro
 */


#include "STD_Types.h"
#include "BIT_Math.h"

#include "DIO.h"
#include <util/delay.h>
void main(void)
{
	DIO_voidInit();
	while(1)
	{
      DIO_enuWritePin(DIO_PIN_NUM_1,DIO_HIGH);
      _delay_ms(1000);
      DIO_enuWritePin(DIO_PIN_NUM_1,DIO_LOW);
      _delay_ms(1000);
	}
}
