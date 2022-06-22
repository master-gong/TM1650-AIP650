#ifndef _TM650_H_
#define _TM650_H_


#include "STC8H.h"
#include "my_type.h"
#include "disp_iic.h"



#define TM1650_SET(addr,segData)  display_iic_set(addr,segData)


#define LED_SIGE_A     10
#define LED_SIGE_B     11
#define LED_SIGE_C     12
#define LED_SIGE_d     13
#define LED_SIGE_E     14
#define LED_SIGE_F     15
#define LED_SIGE_H     16
#define LED_SIGE_L     17
#define LED_SIGE_r     18
#define LED_SIGE_P     19
#define LED_SIGE_N     20
#define LED_SIGE_M_    21
#define LED_SIGE_U_    22
#define LED_SIGE_D_    23
#define LED_SIGE_Uo    24
#define LED_SIGE_Do    25
#define LED_SIGE_OFF   30
#define LED_SIGE_U     26
#define LED_SIGE_S     5
#define LED_SIGE_Z     28
#define LED_SIGE_Y     29


typedef struct {
    char         grid_data[4]; // 显示
    char         brightness;   // 亮度 0-7 
    char         sec_flash;    // == 1   秒 冒号点亮   
    char         flip;         // == 1   反转显示  
    char         mirror;       // == 1   镜像显示
    char         off;          // == 1   关闭显示               
}_disp_buff_st;


extern void drive_air650_4b01(_disp_buff_st info);

#endif