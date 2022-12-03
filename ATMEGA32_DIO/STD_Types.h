/**************************************/
/*Description : Standerd Types Lib    */
/*Author : abo elnour                 */
/*Versio : 0.1v                       */
/*Date : 11 Nov 2022                  */
/**************************************/
#ifndef STD_Types_H
#define STD_Types_H



typedef   unsigned char            uint8 ;
typedef   unsigned short int       uint16;
typedef   unsigned long int        uint32;
typedef   signed char              sint8;
typedef   signed short int         sint16;
typedef   signed long int           sint32;
typedef   float                    float32;
typedef   double                   flaot64;
typedef   long double              float128;


typedef enum 
{
	EOK  ,
	ENOK  ,
	PARAM_OUT_RANGE,
	PARAM_NULL_PTR 
}tenuErrorStatus;

#define NULL_PTR (void *) 0
#endif