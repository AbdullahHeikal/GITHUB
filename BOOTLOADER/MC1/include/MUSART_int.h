#ifndef MUSART_INT_H
#define MUSART_INT_H

void MUSART_voidInit(void);
void MUSART_Transmitt(u8 Copy_u8Data);
u8 MUSART_Recive(void);
void MUSART_voidEnable(void);
void MUSART_voidDisable(void);
void MUSART_voidCallBack(void(*ptr)(void));



u8 MUSART_ReciveString(u8 * Receiving_Location);

void MUSART_voidTransmit(u8 * arr);
u8   MUSART_u8ReceiveWIFI(void);














#endif
