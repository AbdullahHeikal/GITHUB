#ifndef MUSART_PRV_H
#define MUSART_PRV_H


#define MUSART1_BASE_ADRESS  (0x40011000)
typedef struct{
	u32 SBK       :1;
	u32 RWU       :1;
	u32 RE        :1;
	u32 TE        :1;
	u32 IDLEIE    :1;
	u32 RXNEIE    :1;
	u32 TCIE      :1;
	u32 TXEIF     :1;
	u32 PEIE      :1;
	u32 PS        :1;
	u32 PCE       :1;
	u32 WAKE      :1;
	u32 M         :1;
	u32 UE        :1;
	u32 RESERVED0 :1;
	u32 OVER8     :1;
	u32 RESERVED1 :16;

}MUSART_CR1;



typedef struct{
	u32 SR;
	u32 DR;
	u32 BRR;
	MUSART_CR1 CR1;
	u32 CR2;
	u32 CR3;
	u32 GTPR;

}MUSART_t;



#define USART     ((volatile MUSART_t*)MUSART1_BASE_ADRESS)















#endif
