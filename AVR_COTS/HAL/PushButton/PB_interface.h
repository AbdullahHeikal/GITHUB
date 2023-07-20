  
 #ifndef PB_INTERFACE_H
 #define PB_INTERFACE_H
#include "LIB/STD_Types.h"
#include "PB_config.h"
#include "PB_Private.h"
#define PULLUP  0 
#define PULLDOWN 1 
#define pressed 2
#define released 3 
typedef enum{
    PULLUP,
    PULLDOWN
}Button_Active_state_t;
typedef struct Button
{
    u8 PIN_num;
    u8 PORT_num ; 
Button_Active_state_t button_A;
    /* data */
}PushButton_t;

u8 Button_u8Initialization (PushButton_t*button);












 #endif