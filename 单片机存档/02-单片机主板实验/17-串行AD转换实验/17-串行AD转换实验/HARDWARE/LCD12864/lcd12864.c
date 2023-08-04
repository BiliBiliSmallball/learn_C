#include <system.h>
#include "lcd12864.h"
#include "lcdziku.h"
	 
/***********************************************
�������ƣ�SendCommandToLCD
��    �ܣ�д���LCD��
��ڲ�����com ָ��
�� �� ֵ����	
************************************************/
void SendCommandToLCD(uint8_t com)
{
	Delay_us(10);
	RS(0);
	Delay_us(10);
	RW(0);	
	ClrBits(GPIO_DAT,PINS_DATA);	
	SetBits(GPIO_DAT,com);
	Delay_us(100);	
	EN(1);
	Delay_us(10);		
	EN(0);	
	Delay_us(10);	
	ClrBits(GPIO_DAT,PINS_DATA);
}

/*********************************************************************
�������ƣ�SetLCD
��    �ܣ������׵�ַ
��ڲ�����page�� ����ҳ startline���趨��ʾ��ʼ��  olumn���趨�е�ַ
�� �� ֵ����	
**********************************************************************/
void SetLCD(uint8_t page,uint8_t startline,uint8_t column)
{
	Delay_us(10);
	SetLine(page);
	Delay_us(10);
	SetStartLine(startline); 
	Delay_us(10);
	SetColumn(column);
	Delay_us(10);
}
 /*����ҳ 0xb8��ҳ���׵�ַ*/
void SetLine(uint8_t page)	
{
    page=0xb8|page; //1011 1xxx 0<=page<=7 �趨ҳ��ַ--X 0-7,8��Ϊһҳ64/8=8����8ҳ
    SendCommandToLCD(page);
}

 /*�趨��ʾ��ʼ�У�0xc0���е��׵�ַ*/
void SetStartLine(uint8_t startline) 	   
{
    startline=0xc0|startline; //1100 0000
    SendCommandToLCD(startline); //���ô����п�ʼ��0--63��һ���0 �п�ʼ��ʾ
}

 /*�趨�е�ַ--Y 0-63 ��0x40���е��׵�ַ*/
void SetColumn(uint8_t column)	
{
    column=column &0x3f; //column���ֵΪ64��Խ�� 0=<column<=63
    column= 0x40|column; //01xx xxxx
    SendCommandToLCD(column);
}

 
 /*������ʾ��0x3f�ǿ���ʾ��0x3e�ǹ���ʾ*/
void SetOnOff(uint8_t onoff)	   
{
	onoff=0x3e|onoff; //0011 111x,onoffֻ��Ϊ0����1
	SendCommandToLCD(onoff);
}

/***********************************************
�������ƣ�LCD12864_WriteByte
��    �ܣ�д��ʾ����
��ڲ�����dat ����
�� �� ֵ����	
************************************************/
void LCD12864_WriteByte(uint8_t dat)	
{
	Delay_us(10);
    RS(1);
    Delay_us(10);
    RW(0);	
    Delay_us(10);	
    EN(0);  
	ClrBits(GPIO_DAT,PINS_DATA);
    SetBits(GPIO_DAT,dat);
    Delay_us(100);		
    EN(1);
    Delay_us(10);	
    EN(0);
    Delay_us(10);	
    ClrBits(GPIO_DAT,PINS_DATA);
}



/***********************************************
�������ƣ�SelectScreen
��    �ܣ�ѡ����Ļ��ʾ
��ڲ�����ѡ����Ļscreen: 0-ȫ��,1-����,2-����
�� �� ֵ����	
************************************************/
void SelectScreen(uint8_t screen)	  
{ 						 
   switch(screen)
   { 
     case 0: CS1(0);//ȫ��
             Delay_us(10);
             CS2(0); 
             Delay_us(10);
             break; 
     case 1: CS1(1);//����
             Delay_us(10);
             CS2(0);
             Delay_us(10);
             break;
     case 2: CS1(0);//����
             Delay_us(10);
             CS2(1);
             Delay_us(10); 
             break;
		 default:break;
   }
}

/***********************************************
�������ƣ�ClearScreen
��    �ܣ�����
��ڲ���������screen: 0-ȫ��,1-����,2-��
�� �� ֵ����	
************************************************/
void ClearScreen(uint8_t screen)	  //��ʾ����ʱ�����ֿ�������µĺ������ǣ�ע��ҲҪ�ڵ�ǰshow_hz�иı��������λ��
{ 																	//
	for(screen=0;screen<8;screen++)
	{
        Show_Hz(screen,0,8);
        Show_Hz(screen,1,8);
        Show_Hz(screen,2,8);
        Show_Hz(screen,3,8);
        Show_Hz(screen,4,8);
        Show_Hz(screen,5,8);
        Show_Hz(screen,6,8);
        Show_Hz(screen,7,8);
	}			 
}

/***********************************************
�������ƣ�lcd_rol
��    �ܣ����Ϲ���  ��������������ʾ
��ڲ�������
�� �� ֵ����	
************************************************/
void lcd_rol(void)					
{
    uint8_t i;
    for(i = 0; i < 64; i++)
    {
        CS1(0); // Ƭѡ1
        SendCommandToLCD(0xc0+i);
        CS1(1); 
        CS2(0);	// Ƭѡ2
        SendCommandToLCD(0xc0+62-i);
        CS2(0); // Ƭѡ2
        Delay_us(10);
    }
}	

/***********************************************
�������ƣ�LCD12864_Software_Init
��    �ܣ���ʼ��LCD
��ڲ�������
�� �� ֵ����	
************************************************/
void LCD12864_Software_Init(void) 	  
{ 
	LCD_ALL_DIR_OUT();
	Delay_us(10);
	SelectScreen(0);
	SetOnOff(0); //����ʾ
	Delay_us(10);
	SelectScreen(0);
	SetOnOff(1); //����ʾ
	Delay_us(10);
	SelectScreen(0);
	ClearScreen(0);//����
	Delay_us(10);
	SetStartLine(0); //��ʼ��:0
	Delay_us(10);
	SetOnOff(0x3f);	//����ʾ
	Delay_us(10);
	ClearScreen(0);//����
	Delay_us(10);
}

/************************************************************
�������ƣ�Show_Hz
��    �ܣ�������ʾ����
��ڲ�����X��������ֵ��Y��������ֵ��hz�����ֿ��еĵڼ�������
�� �� ֵ����	
*************************************************************/
void Show_Hz(uint8_t x,uint8_t y,uint8_t hz)
{		
	uint8_t l_r=0;
	if(x<=3)
		l_r=1;
	else 
		l_r =2;
	Display(l_r,y*2,x*16,hz);
}

/************************************************************
�������ƣ�Show_Num
��    �ܣ���ĸ�����֡��ַ�����ʾ����
��ڲ�����X��������ֵ��Y��������ֵ��str������Ҫ��ʾ������
�� �� ֵ����	
*************************************************************/
void Show_Num(uint8_t x,uint8_t y,char*str)
{		
	uint8_t l_r=0,i=0;
	while(*str != '\0')
	{
		if(x>15)
		{x=0;i+=2;}
		if(x<8)l_r=1;
		else l_r =2;
		Displayen(l_r,y*2+i,x*8,*str++);
		x++;	
	}
}

/**********************************************************************
�������ƣ�Display
��    �ܣ���ʾȫ�Ǻ���
��ڲ�����SSѡ��������pagrѡҳ������columnѡ�в�����numberѡ�ڼ��������
�� �� ֵ����	
***********************************************************************/
void Display(uint8_t ss,uint8_t page,uint8_t column,uint8_t number)
{
	int i;	//ѡ��������pagrѡҳ������columnѡ�в�����numberѡ�ڼ��������
	SetOnOff(0x3f);			//����ʾ
	SelectScreen(ss);
	column=column&0x3f;
	SetLine(page);			//д�ϰ�ҳ
	SetColumn(column); 		//������
	for(i=0;i<16;i++)  		//����16�е��������
	{
		LCD12864_WriteByte(Hzk[i+32*number]); //i+32*number���ֵ�ǰ16���������	
	}
	SetLine(page+1);		//д�°�ҳ
	SetColumn(column); 		//������
    for(i=0;i<16;i++)	  	//����16�е��������
	{
		LCD12864_WriteByte(Hzk[i+32*number+16]);	//i+32*number+16���ֵĺ�16���������
	}
} 

/**********************************************************************
�������ƣ�Displayen
��    �ܣ���ʾ��Ǻ��ֺ����ֺ���ĸ
��ڲ�����SSѡ��������pagrѡҳ������columnѡ�в�����numberѡ�ڼ��������
�� �� ֵ����	
***********************************************************************/
void Displayen(uint8_t ss,uint8_t page,uint8_t column,char num)
{
    uint8_t i;//ѡ��������pagrѡҳ������columnѡ�в�����numberѡ�ڼ��������
    uint8_t number = num;
    SelectScreen(ss);
    column=column&0x3f;
    SetLine(page);	//д�ϰ�ҳ
    SetColumn(column);
    for(i=0;i<8;i++)
    {
        LCD12864_WriteByte(ascll[i+16*number]);
    }
    SetLine(page+1);	//д�°�ҳ
    SetColumn(column);
    for(i=0;i<8;i++)
    {
        LCD12864_WriteByte(ascll[i+16*number+8]);
    }
}  

/**********************************************************************
�������ƣ�LCD_ALL_DIR_OUT
��    �ܣ�����Ϊʹ���������ģʽ
��ڲ�������
�� �� ֵ����	
***********************************************************************/   	   
void LCD_ALL_DIR_OUT(void)
{
	P0_Mode_PullUp(PINS_DATA);
	P2_Mode_PullUp(PINS_CMD);
	ClrBits(GPIO_CMD,PINS_ALL);
	ClrBits(GPIO_DAT,PINS_ALL);
}
