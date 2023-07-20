#include "STD_Types.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"

void  DIO_voidSetPinDirection(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PinState)
{
	if(  (Copy_u8PinNumber >= PIN0) && (Copy_u8PinNumber <= PIN7)  )
	{
		switch(Copy_u8PortName)
		{
		case PORTA:
			switch(Copy_u8PinState)
			{
			case INPUT:
				CLR_BIT(DIO_DDRA, Copy_u8PinNumber);
				break;
			case OUTPUT:
				SET_BIT(DIO_DDRA, Copy_u8PinNumber);
				break;
			}
			break;

			case PORTB: 
				switch(Copy_u8PinState)
				{
				case INPUT:
					CLR_BIT(DIO_DDRB, Copy_u8PinNumber);
					break;
				case OUTPUT:
					SET_BIT(DIO_DDRB, Copy_u8PinNumber);
					break;
				}
				break;

				case PORTC:
					switch(Copy_u8PinState)
					{
					case INPUT:
						CLR_BIT(DIO_DDRC, Copy_u8PinNumber);
						break;
					case OUTPUT:
						SET_BIT(DIO_DDRC, Copy_u8PinNumber);
						break;
					}
					break;

					case PORTD:
						switch(Copy_u8PinState)
						{
						case INPUT:
							CLR_BIT(DIO_DDRD, Copy_u8PinNumber);
							break;
						case OUTPUT:
							SET_BIT(DIO_DDRD, Copy_u8PinNumber);
							break;
						}
						break;
						default:
							/*Do Nothing*/
							break;

		}
	}
	else
	{
		/*Do Nothing*/
	}
}

void DIO_voidSetPinValue(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PinValue)
{
	if( (Copy_u8PinNumber >= PIN0 ) && (Copy_u8PinNumber <= PIN7) )
	{
		switch(Copy_u8PortName)
		{
		case PORTA:
			switch(Copy_u8PinValue)
			{
			case HIGH:
				SET_BIT(DIO_PORTA, Copy_u8PinNumber);
				break;
			case LOW:
				CLR_BIT(DIO_PORTA, Copy_u8PinNumber);
				break;
			}
			break;
			case PORTB:
				switch(Copy_u8PinValue)
				{
				case HIGH:
					SET_BIT(DIO_PORTB, Copy_u8PinNumber);
					break;
				case LOW:
					CLR_BIT(DIO_PORTB, Copy_u8PinNumber);
					break;
				}
				break;
				case PORTC:
					switch(Copy_u8PinValue)
					{
					case HIGH:
						SET_BIT(DIO_PORTC, Copy_u8PinNumber);
						break;
					case LOW:
						CLR_BIT(DIO_PORTC, Copy_u8PinNumber);
						break;
					}
					break;
					case PORTD:
						switch(Copy_u8PinValue)
						{
						case HIGH:
							SET_BIT(DIO_PORTD, Copy_u8PinNumber);
							break;
						case LOW:
							CLR_BIT(DIO_PORTD, Copy_u8PinNumber);
							break;
						}
						break;
		}
	}
	else
	{
		/*Do Nothing*/
	}
}


u8 DIO_u8GetPinValue(u8 Copy_u8PortName, u8 Copy_u8PinNumber)
{
	u8 Local_u8PinValue;
	switch(Copy_u8PortName)
	{
	case PORTA:
		Local_u8PinValue = GET_BIT(DIO_PINA, Copy_u8PinNumber);
		break;

	case PORTB:
		Local_u8PinValue = GET_BIT(DIO_PINB, Copy_u8PinNumber);
		break;

	case PORTC:
		Local_u8PinValue = GET_BIT(DIO_PINC, Copy_u8PinNumber);
		break;

	case PORTD:
		Local_u8PinValue = GET_BIT(DIO_PIND, Copy_u8PinNumber);
		break;
	default:
		/*Do Nothing*/
		break;
	}

	return Local_u8PinValue;
}



void DIO_voidSetPortDirection(u8 Copy_u8PortName, u8 Copy_u8PortState)
{
	switch(Copy_u8PortName)
	{
	case PORTA:
		switch(Copy_u8PortState)
		{
		case INPUT:
			DIO_DDRA = ALL_INPUT;
			break;
		case OUTPUT:
			DIO_DDRA = ALL_OUTPUT;
			break;
		}
		break;

		case PORTB:
			switch(Copy_u8PortState)
			{
			case INPUT:
				DIO_DDRB = ALL_INPUT;
				break;
			case OUTPUT:
				DIO_DDRB = ALL_OUTPUT;
				break;
			}
			break;

			case PORTC:
				switch(Copy_u8PortState)
				{
				case INPUT:
					DIO_DDRC = ALL_INPUT;
					break;
				case OUTPUT:
					DIO_DDRC = ALL_OUTPUT;
					break;
				}
				break;

				case PORTD:
					switch(Copy_u8PortState)
					{
					case INPUT:
						DIO_DDRD = ALL_INPUT;
						break;
					case OUTPUT:
						DIO_DDRD = ALL_OUTPUT;
						break;
					}
					break;
	}
}



void DIO_voidSetPortValue(u8 Copy_u8PortName, u8 Copy_u8PortValue)
{
	switch(Copy_u8PortName)
	{
	case PORTA:
		switch(Copy_u8PortValue)
		{
		case LOW:
			DIO_PORTA = ALL_LOW;
			break;
		case HIGH:
			DIO_PORTA = ALL_HIGH;
			break;
		}
		break;

		case PORTB:
			switch(Copy_u8PortValue)
			{
			case LOW:
				DIO_PORTB = ALL_LOW;
				break;
			case HIGH:
				DIO_PORTB = ALL_HIGH;
				break;
			}
			break;

			case PORTC:
				switch(Copy_u8PortValue)
				{
				case LOW:
					DIO_PORTC = ALL_LOW;
					break;
				case HIGH:
					DIO_PORTC = ALL_HIGH;
					break;
				}
				break;

				case PORTD:
					switch(Copy_u8PortValue)
					{
					case LOW:
						DIO_PORTD = ALL_LOW;
						break;
					case HIGH:
						DIO_PORTD = ALL_HIGH;
						break;
					}
					break;
	}
}


void DIO_voidSetPortSpecificDirection(u8 Copy_u8PortName, u8 Copy_u8PortDirection)
{
	if( (Copy_u8PortDirection >= 0) && (Copy_u8PortDirection <= 255) )
	{
		switch(Copy_u8PortName)
		{
		case PORTA:
			DIO_DDRA = Copy_u8PortDirection;
			break;

		case PORTB:
			DIO_DDRB = Copy_u8PortDirection;
			break;

		case PORTC:
			DIO_DDRC = Copy_u8PortDirection;
			break;

		case PORTD:
			DIO_DDRD = Copy_u8PortDirection;
			break;
		}
	}
	else
	{
		/*Do Nothing*/
	}
}


void DIO_voidSetPortSpecificValue(u8 Copy_u8PortName, u8 Copy_u8PortValue)
{
	if( (Copy_u8PortValue >= 0) && (Copy_u8PortValue <= 255) )
	{
		switch(Copy_u8PortName)
		{
		case PORTA:
			DIO_PORTA = Copy_u8PortValue;
			break;

		case PORTB:
			DIO_PORTB = Copy_u8PortValue;
			break;

		case PORTC:
			DIO_PORTC = Copy_u8PortValue;
			break;

		case PORTD:
			DIO_PORTD = Copy_u8PortValue;
			break;
		}
	}
	else
	{
		/*Do Nothing*/
	}
}






