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

//д1��0
#define EN(x)            		x?(SetBits(GPIO_CMD,PIN_EN)):(ClrBits(GPIO_CMD,PIN_EN))
#define RW(x)             		x?(SetBits(GPIO_CMD,PIN_RW)):(ClrBits(GPIO_CMD,PIN_RW))
#define RS(x)             		x?(SetBits(GPIO_CMD,PIN_RS)):(ClrBits(GPIO_CMD,PIN_RS))
#define CS2(x)            		x?(SetBits(GPIO_CMD,PIN_CS2)):(ClrBits(GPIO_CMD,PIN_CS2))
#define CS1(x)            		x?(SetBits(GPIO_CMD,PIN_CS1)):(ClrBits(GPIO_CMD,PIN_CS1))

// д����
#define LCD_DATA_OUT(x)      		ClrBits(GPIO_DAT,PIN_ALL);SetBits(GPIO_DAT,x);


void CheckState(void);								 /*״̬��飬LCD�Ƿ�æ*/
void SendCommandToLCD(uint8_t com);		    /*д���LCD��*/
void SetLine(uint8_t page);				  /*����ҳ 0xb8��ҳ���׵�ַ*/
void SetStartLine(uint8_t startline);		 /*�趨��ʾ��ʼ�У�0xc0���е��׵�ַ*/
void SetColumn(uint8_t column);		   /*�趨�е�ַ--Y 0-63 ��0x40���е��׵�ַ*/
void SetOnOff(uint8_t onoff);			  /*������ʾ��0x3f�ǿ���ʾ��0x3e�ǹ���ʾ*/
void LCD12864_WriteByte(uint8_t dat);			/*д��ʾ���� */
void SelectScreen(uint8_t screen);   /*ѡ����Ļscreen: 0-ȫ��,1-����,2-����*/
void ClearScreen(uint8_t screen);	   /*����screen: 0-ȫ��,1-����,2-��*/
void lcd_rol(void);							  /*���Ϲ���*//*��������������ʾ*/
void LCD12864_Software_Init(void);							  /*��ʼ��LCD*/
void Display(uint8_t ss, uint8_t page, uint8_t column, uint8_t number);

/*��ʾȫ�Ǻ���*/
void Displayen(uint8_t ss, uint8_t page, uint8_t column, char num);

void SetLCD(uint8_t page, uint8_t startline, uint8_t column); /*��ʾ��Ǻ��ֺ����ֺ���ĸ*/
void Show_Hz(uint8_t x, uint8_t y, uint8_t hz);
void Show_Num(uint8_t x, uint8_t y, char*str);

// ����Ϊʹ���������ģʽ
void LCD_ALL_DIR_OUT(void);

#endif


