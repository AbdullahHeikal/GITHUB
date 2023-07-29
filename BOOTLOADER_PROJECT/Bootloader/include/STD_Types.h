#ifndef _STD_TYPES_H
#define _STD_TYPES_H

typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;

typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;

typedef float f32;
typedef double f64;



#ifndef STD_HIGH
#define STD_HIGH   (1U)
#endif

#ifndef STD_LOW
#define STD_LOW   (0U)
#endif

#ifndef STD_TRUE
#define STD_TRUE   (1U)
#endif

#ifndef STD_False
#define STD_False   (0U)
#endif

#ifndef NULL_PTR
#define NULL_PTR   (void*)0
#endif

#endif
