#include "STC8H.h"
#include "time.h"
#include "my_type.h"

#define Timer1_Reload   (MAIN_Fosc / 1000)      //Timer 2 中断频率, 1000次/秒



volatile   uint8_t ucCycle_Count_1ms = 0  ; /* 1ms计数循环变量 */


void timer1_init(void)
{
        TR1 = 0;    //停止计数

    #if (Timer1_Reload < 64)    // 如果用户设置值不合适， 则不启动定时器
        #error "Timer1设置的中断过快!"

    #elif ((Timer1_Reload/12) < 65536UL)    // 如果用户设置值不合适， 则不启动定时器
        ET1 = 1;    //允许中断
    //  PT1 = 1;    //高优先级中断
        TMOD &= ~0x30;
        TMOD |= (0 << 4);   //工作模式, 0: 16位自动重装, 1: 16位定时/计数, 2: 8位自动重装
    //  TMOD |=  0x40;  //对外计数或分频
        TMOD &= ~0x40;  //定时
    //  INT_CLKO |=  0x02;  //输出时钟
        INTCLKO &= ~0x02;  //不输出时钟

        #if (Timer1_Reload < 65536UL)
            AUXR |=  0x40;  //1T mode
            TH1 = (u8)((65536UL - Timer1_Reload) / 256);
            TL1 = (u8)((65536UL - Timer1_Reload) % 256);
        #else
            AUXR &= ~0x40;  //12T mode
            TH1 = (u8)((65536UL - Timer1_Reload/12) / 256);
            TL1 = (u8)((65536UL - Timer1_Reload/12) % 256);
        #endif

        TR1 = 1;    //开始运行

    #else
        #error "Timer1设置的中断过慢!"
    #endif
}

//========================================================================
// 函数: void timer1_int (void) interrupt TIMER1_VECTOR
// 描述:  timer1中断函数.
// 参数: none.
// 返回: none.
// 版本: V1.0, 2015-1-12
//========================================================================
void timer1_interrupt (void) interrupt 3
{
  //-----------主函数10ms计数实现-start----------
   ucCycle_Count_1ms++;
   if(ucCycle_Count_1ms >= 10) //10ms
   {
      ucCycle_Count_1ms = 0;
      ucFlag.BIT.CYCLE_FLAG = SET;
    }
   //-----------主函数20ms计数实现-End----------
   
   //-------uart接收-------------
//   if(ucFlag.BIT.UART_REC){
//      uart_interval_count++;
//      if(uart_interval_count > 30){
//         uart_interval_count = 0;
//         ucFlag.BIT.UART_REC_OK = true;
//      }
//   }
   
   //TIM1_SR1 &=~0x01;  // 清除更新中断标记，这步不能漏掉，否则会连续进入中断程序  
}

