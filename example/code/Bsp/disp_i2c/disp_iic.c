#include "disp_iic.h"

#include "intrins.h"



/***********************
函数功能：us延时
输入参数：无
输出参数：无
备    注：粗略延时，不准
***********************/
static void delay_us(uint8_t z)
{ 
    while(z--){
        _nop_(); 
    }
}

/***********************
函数功能：ms延时
输入参数：无
输出参数：无
备    注：粗略延时，不准
***********************/
static void delay_ms(unsigned int time)
{
    unsigned int i;
    while(time--)  
      for(i=100;i>0;i--)
        delay_us(1); 
}


static void iic_start(void)
{
    DISP_SCL_CRL;
    DISP_SDA_SET; 
    delay_us(4);
    DISP_SCL_SET;    
    delay_us(40);     
    DISP_SDA_CRL;         
    delay_us(4);         
    DISP_SCL_CRL;    
}

static void iic_stop(void)
{
    DISP_SCL_CRL;
    DISP_SCL_CRL;
    delay_us(2);
    DISP_SDA_CRL;
    delay_us(40);
    DISP_SCL_SET;
    delay_us(10);
    DISP_SDA_SET;
    delay_us(40);
}

static void iic_ack(void)
{
    DISP_SCL_CRL;
    DISP_SDA_INPUT();
    delay_us(10);
    DISP_SCL_SET;
    delay_us(40);
    DISP_SCL_CRL;
    delay_us(10);
    DISP_SDA_OUT();
}

static void iic_write_byte(char txd)
{
    uint8_t i;
    DISP_SDA_OUT();
    for(i = 0;i < 8; i ++){
        delay_us(2);
        if((txd&0x80)>>7){ //0x80  1000 0000
            DISP_SDA_SET;
        }else{
            DISP_SDA_CRL;
        }
        txd<<=1; 
        delay_us(20);   
        DISP_SCL_SET;
        delay_us(45);  
        DISP_SCL_CRL;	
        delay_us(20); 
    }
}
 
void display_iic_set(char add,char dat) 
{
    iic_start();
    iic_write_byte(add); 
    iic_ack();
    iic_write_byte(dat);
    iic_ack();
    iic_stop();
}

void init_display_iic_gpio(void)
{

    DISP_SDA_OUT();
    DISP_SCL_OUT(); 
    DISP_SCL_SET;
    DISP_SDA_SET;
    delay_ms(2);
}

