#include "STD_Types.h"
#include "BIT_MATH.h"
#include "MRCC_int.h"
#include "MGPIO_int.h"
#include "MSYSTICK_int.h"
#include "MNVIC_int.h"
#include "MEXTI_int.h"
#include "HSTP_int.h"
#include "HLEDMATRIX_int.h"

u8 arr[8]={28, 62, 102, 204, 204, 102, 62, 28};
u8 arr1[8]={0b11111110,0b11111101,0b11111011,0b11110111,0b11101111,0b11011111,0b10111111,0b01111111};
void main(void)
{
	u8 i;
	MRCC_init();
	MRCC_Enable_peripheral(RCC_AHB1,AHB1_GPIOA);
	HSTP_voidInit();
	MSYSYTICK_voidInit();


	while (1)
	{
		for (i=0;i<8;i++){
			HLEDMATRIX_VoidDisableColumns();
			HSTP_voidShiftData(arr[i]);
			HSTP_voidShiftData(arr1[i]);
			HSTP_voidSendData();
			MSYSYTICK_voidDelayms(2);
		}
	}
}

