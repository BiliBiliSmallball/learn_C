#ifndef __LCD12864_H
#define __LCD12864_H
#include <system.h>

#define GPIO_DAT				 P0
#define GPIO_CMD				 P2
#define PIN_CS1                  PIN_0
#define PIN_CS2                  PIN_1
#define PIN_RS                   PIN_2
#define PIN_RW                   PIN_3
#define PIN_EN                   PIN_4
#define PINS_CMD          		 PIN_0|PIN_1|PIN_2|PIN_3|PIN_4
#define PINS_DATA                PIN_0|PIN_1|PIN_2|PIN_3|PIN_4|PIN_5|PIN_6|PIN_7
#define PINS_ALL         		 PIN_ALL

//写1，0
#define EN(x)            		x?(SetBits(GPIO_CMD,PIN_EN)):(ClrBits(GPIO_CMD,PIN_EN))
#define RW(x)             		x?(SetBits(GPIO_CMD,PIN_RW)):(ClrBits(GPIO_CMD,PIN_RW))
#define RS(x)             		x?(SetBits(GPIO_CMD,PIN_RS)):(ClrBits(GPIO_CMD,PIN_RS))
#define CS2(x)            		x?(SetBits(GPIO_CMD,PIN_CS2)):(ClrBits(GPIO_CMD,PIN_CS2))
#define CS1(x)            		x?(SetBits(GPIO_CMD,PIN_CS1)):(ClrBits(GPIO_CMD,PIN_CS1))

// 写数据
#define LCD_DATA_OUT(x)      		ClrBits(GPIO_DAT,PIN_ALL);SetBits(GPIO_DAT,x);


void CheckState(void);								 /*状态检查，LCD是否忙*/
void SendCommandToLCD(uint8_t com);		    /*写命令到LCD中*/
void SetLine(uint8_t page);				  /*设置页 0xb8是页的首地址*/
void SetStartLine(uint8_t startline);		 /*设定显示开始行，0xc0是行的首地址*/
void SetColumn(uint8_t column);		   /*设定列地址--Y 0-63 ，0x40是列的首地址*/
void SetOnOff(uint8_t onoff);			  /*开关显示，0x3f是开显示，0x3e是关显示*/
void LCD12864_WriteByte(uint8_t dat);			/*写显示数据 */
void SelectScreen(uint8_t screen);   /*选择屏幕screen: 0-全屏,1-左屏,2-右屏*/
void ClearScreen(uint8_t screen);	   /*清屏screen: 0-全屏,1-左屏,2-右*/
void lcd_rol(void);							  /*向上滚屏*//*这里用做滚动显示*/
void LCD12864_Software_Init(void);							  /*初始化LCD*/
void Display(uint8_t ss, uint8_t page, uint8_t column, uint8_t number);

/*显示全角汉字*/
void Displayen(uint8_t ss, uint8_t page, uint8_t column, char num);

void SetLCD(uint8_t page, uint8_t startline, uint8_t column); /*显示半角汉字和数字和字母*/
void Show_Hz(uint8_t x, uint8_t y, uint8_t hz);
void Show_Num(uint8_t x, uint8_t y, char*str);

// 设置为使用引脚输出模式
void LCD_ALL_DIR_OUT(void);

#endif


