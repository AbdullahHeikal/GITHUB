#include "LIB/STD_Types.h"
#include "DIO/DIO_interface.h"
#include "PB_interface.h"

u8 Button_u8Initialization (PushButton_t*button){
if (button->button_A == PULLUP){
    DIO_voidSetPinDirection(button->PORT_num,button->PIN_num,INPUT);
    DIO_voidSetPinValue(button->PORT_num,button->PIN_num,HIGH);
}
else {
     DIO_voidSetPinDirection(button->PORT_num,button->PIN_num,INPUT);
}

}
