


#ifndef __MyType_H
#define __MyType_H


#define MAIN_Fosc       22118400L   //定义主时钟（精确计算115200波特率）

#ifndef BIT
#define BIT(x)	(1 << (x))
#endif

/*!< Signed integer types  */
typedef   signed char     int8_t;
typedef   signed short    int16_t;
typedef   signed long     int32_t;

/*!< Unsigned integer types  */
typedef unsigned char     uint8_t;
typedef unsigned short    uint16_t;
typedef unsigned long     uint32_t;

/*!< STM8 Standard Peripheral Library old types (maintained for legacy purpose) */

typedef int32_t  s32;
typedef int16_t s16;
typedef int8_t  s8;

typedef uint32_t  u32;
typedef uint16_t u16;
typedef uint8_t  u8;

#define SET     (1)
#define CLR     (0)
#define OK      (1)
#define BUSY    (0)
#define true     1
#define false    0

typedef union{
  char BYTE;
  struct{
    char CYCLE_FLAG         :  1 ;  /* 10ms定时标志 */
		
  }BIT;
}_flag;



extern _flag  xdata  ucFlag;                      /* 标志位变量 */




#endif