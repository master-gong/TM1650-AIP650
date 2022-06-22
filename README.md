# TM1650-AIP650

TM1650/AIP650芯片的驱动程序
--------------------------------

文件夹《drive》 TM1650/AIP650芯片的驱动程序。

文件夹《example》 STC8H1K08芯片的使用例程工程参考。

文件夹《doc》 TM1650/AIP650芯片的用户手册。

![显示图片][1]


功能： 

码表有常规数字和字符显示（0-9，ABCDdEFHLrPN-_oU）。驱动程序提供反转，镜像实现函数。

驱动说明：

《tm1650》文件夹为芯片的驱动，如果有自己的IIC写函数，可直接替换AIP650.h  的宏#define TM1650_SET(addr,segData)  display_iic_set(addr,segData)

《disp_i2c》 文件夹为模拟IIC实现，可在 disp_iic.h 文件中修改对应的引脚初始化，另不同的芯片要调整延迟函数。




注：本示例程序码表只针对特定数码管模组，不同连线方式需要重新编写码表。

适用模组见：https://gongqijunhui.taobao.com/category-1663332070.htm?spm=a1z10.5-c-s.w4010-22753595293.9.122a7a1cfOQ5dy&search=y&catName=%CF%D4%CA%BE%C4%A3%D7%E9#bd

  [1]: https://github.com/master-gong/TM1650-AIP650/blob/main/example/Video_20220622_073220_639.gif
