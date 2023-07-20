#ifndef FLASH_PRV_H
#define FLASH_PRV_H

#define FMI_BASEADDRESS (0X40023C00)


typedef struct 
{
    u32 ACR ; 
    u32 KEYR ; 
    u32 OPTKEYR;
    u32 SR;
    u32 CR; 
    u32 OPTCR ;

}FMI_t;


#define    ((volatile *FMI_t)FMI_BASEADDRESS))




#endif