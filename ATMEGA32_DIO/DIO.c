/**************************************/
/* Description : DIO program file     */
/* Author      : mahrold              */
/* Version     : 0.1v                 */
/* Date        : 2 Dec 2022           */
/* History     : 0.1v initial creation*/
/**************************************/
#include"STD_Types.h"
#include"BIT_Math.h"

#include"DIO.h"
#include"DIO_cfg.h"
#include"DIO_priv.h"

void DIO_voidInit(void)
{
	//set ddr
	   DDRA = CONC(DIO_PIN_DIR_7 ,DIO_PIN_DIR_6 ,DIO_PIN_DIR_5 ,DIO_PIN_DIR_4 ,DIO_PIN_DIR_3 ,DIO_PIN_DIR_2 ,DIO_PIN_DIR_1 ,DIO_PIN_DIR_0 );
	   DDRB = CONC(DIO_PIN_DIR_15,DIO_PIN_DIR_14,DIO_PIN_DIR_13,DIO_PIN_DIR_12,DIO_PIN_DIR_11,DIO_PIN_DIR_10,DIO_PIN_DIR_9 ,DIO_PIN_DIR_8 );
	   DDRC = CONC(DIO_PIN_DIR_23,DIO_PIN_DIR_22,DIO_PIN_DIR_21,DIO_PIN_DIR_20,DIO_PIN_DIR_19,DIO_PIN_DIR_18,DIO_PIN_DIR_17,DIO_PIN_DIR_16);
	   DDRD = CONC(DIO_PIN_DIR_31,DIO_PIN_DIR_30,DIO_PIN_DIR_29,DIO_PIN_DIR_28,DIO_PIN_DIR_27,DIO_PIN_DIR_26,DIO_PIN_DIR_25,DIO_PIN_DIR_24);
}

tenuErrorStatus DIO_enuWritePin(uint8 u8PinNumCpy,uint8 u8PinValueCpy)
{
	//we write in odr
	tenuErrorStatus enuReturnStateLoc = EOK;
	//we have 4 odr (A,B,C,D)
	if(u8PinNumCpy >= DIO_PIN_NUM_0 && u8PinNumCpy <= DIO_PIN_NUM_7)
	{
		switch(u8PinValueCpy)
		{
			case DIO_LOW:
				CLR_BIT(ODRA , u8PinNumCpy);
				break;
			case DIO_HIGH:
				SET_BIT(ODRA, u8PinNumCpy);
				break;
			default:
				enuReturnStateLoc = PARAM_OUT_RANGE;
		}
	}
	else if((u8PinNumCpy >= DIO_PIN_NUM_8) && (u8PinNumCpy <= DIO_PIN_NUM_15))
	{
				switch(u8PinValueCpy)
		{
			case DIO_LOW:
				CLR_BIT(ODRB , u8PinNumCpy%8);
				break;
			case DIO_HIGH:
				SET_BIT(ODRB , u8PinNumCpy%8);
				break;
			default:
				enuReturnStateLoc = PARAM_OUT_RANGE;
		}
	}
	else if((u8PinNumCpy >= DIO_PIN_NUM_16) && (u8PinNumCpy <= DIO_PIN_NUM_23))
	{
				switch(u8PinValueCpy)
		{
			case DIO_LOW:
				CLR_BIT(ODRC,u8PinNumCpy%8);
				break;
			case DIO_HIGH:
				SET_BIT(ODRC,u8PinNumCpy%8);
				break;
			default:
				enuReturnStateLoc = PARAM_OUT_RANGE;
		}
	}
	else if((u8PinNumCpy >= DIO_PIN_NUM_24) && (u8PinNumCpy <= DIO_PIN_NUM_31))
	{
				switch(u8PinValueCpy)
		{
			case DIO_LOW:
				CLR_BIT(ODRD,u8PinNumCpy);
				break;
			case DIO_HIGH:
				SET_BIT(ODRD,u8PinNumCpy);
				break;
			default:
				enuReturnStateLoc = PARAM_OUT_RANGE;
		}
	}
	else
	{
		enuReturnStateLoc = PARAM_OUT_RANGE;
	}
	return enuReturnStateLoc;
}
tenuErrorStatus DIO_enuReadPin(uint8 u8PinNumCpy,uint8 * u8PinValueCpy)
{
	//reading from idr
	tenuErrorStatus enuReturnStateLoc = EOK;
	//we have 4 idr a,b,c,d we assign value ptr to getbit
	if(u8PinValueCpy != NULL_PTR)
	{
		if(u8PinNumCpy >=DIO_PIN_NUM_0 && u8PinNumCpy <= DIO_PIN_NUM_7)
		{
			* u8PinValueCpy = GET_BIT(IDRA, u8PinNumCpy%8);
		}
		else if(u8PinNumCpy >=DIO_PIN_NUM_8 && u8PinNumCpy <= DIO_PIN_NUM_15)
		{
			* u8PinValueCpy = GET_BIT(IDRB, u8PinNumCpy%8);
		}
		else if(u8PinNumCpy >=DIO_PIN_NUM_16 && u8PinNumCpy <= DIO_PIN_NUM_23)
		{
			* u8PinValueCpy = GET_BIT(IDRC, u8PinNumCpy%8);
		}
		else if(u8PinNumCpy >=DIO_PIN_NUM_24 && u8PinNumCpy <= DIO_PIN_NUM_31)
		{
			* u8PinValueCpy = GET_BIT(IDRD, u8PinNumCpy%8);
		}
		else
		{
			enuReturnStateLoc = PARAM_OUT_RANGE;
		}
	
	}
	else
	{
	enuReturnStateLoc = PARAM_NULL_PTR;
	
	}
	return enuReturnStateLoc;
}
tenuErrorStatus DIO_enuWriteGroup(uint8 * pau8PinNumCpy, uint8 * pau8PinValueCpy,uint8 u8SizeCpy)
{
	tenuErrorStatus enuReturnStateLoc = EOK;
	//we have 2 arrays one for pin nums and one for pin values
	uint8 u8CntrLoc;
	for(u8CntrLoc=0;u8CntrLoc<u8SizeCpy;u8CntrLoc++)
	{
		enuReturnStateLoc = DIO_enuWritePin(pau8PinNumCpy[u8CntrLoc],pau8PinValueCpy[u8CntrLoc]);
		if(enuReturnStateLoc != EOK)
		{
			break;
		}
	}
}
tenuErrorStatus DIO_enuStatePullup(uint8 u8PinNumCpy,uint8 u8StateCpy)
{
	return DIO_enuWritePin(u8PinNumCpy,u8StateCpy);
}
