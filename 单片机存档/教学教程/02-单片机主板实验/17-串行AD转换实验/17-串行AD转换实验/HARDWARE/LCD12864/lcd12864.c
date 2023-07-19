#include <system.h>
#include "lcd12864.h"
#include "lcdziku.h"
	 
/***********************************************
函数名称：SendCommandToLCD
功    能：写命令到LCD中
入口参数：com 指令
返 回 值：无	
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
函数名称：SetLCD
功    能：设置首地址
入口参数：page： 设置页 startline：设定显示开始行  olumn：设定列地址
返 回 值：无	
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
 /*设置页 0xb8是页的首地址*/
void SetLine(uint8_t page)	
{
    page=0xb8|page; //1011 1xxx 0<=page<=7 设定页地址--X 0-7,8行为一页64/8=8，共8页
    SendCommandToLCD(page);
}

 /*设定显示开始行，0xc0是行的首地址*/
void SetStartLine(uint8_t startline) 	   
{
    startline=0xc0|startline; //1100 0000
    SendCommandToLCD(startline); //设置从哪行开始：0--63，一般从0 行开始显示
}

 /*设定列地址--Y 0-63 ，0x40是列的首地址*/
void SetColumn(uint8_t column)	
{
    column=column &0x3f; //column最大值为64，越出 0=<column<=63
    column= 0x40|column; //01xx xxxx
    SendCommandToLCD(column);
}

 
 /*开关显示，0x3f是开显示，0x3e是关显示*/
void SetOnOff(uint8_t onoff)	   
{
	onoff=0x3e|onoff; //0011 111x,onoff只能为0或者1
	SendCommandToLCD(onoff);
}

/***********************************************
函数名称：LCD12864_WriteByte
功    能：写显示数据
入口参数：dat 数据
返 回 值：无	
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
函数名称：SelectScreen
功    能：选择屏幕显示
入口参数：选择屏幕screen: 0-全屏,1-左屏,2-右屏
返 回 值：无	
************************************************/
void SelectScreen(uint8_t screen)	  
{ 						 
   switch(screen)
   { 
     case 0: CS1(0);//全屏
             Delay_us(10);
             CS2(0); 
             Delay_us(10);
             break; 
     case 1: CS1(1);//左屏
             Delay_us(10);
             CS2(0);
             Delay_us(10);
             break;
     case 2: CS1(0);//右屏
             Delay_us(10);
             CS2(1);
             Delay_us(10); 
             break;
		 default:break;
   }
}

/***********************************************
函数名称：ClearScreen
功    能：清屏
入口参数：清屏screen: 0-全屏,1-左屏,2-右
返 回 值：无	
************************************************/
void ClearScreen(uint8_t screen)	  //显示汉字时，在字库中添加新的汉字码是，注意也要在当前show_hz中改变清屏码的位子
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
函数名称：lcd_rol
功    能：向上滚屏  这里用做滚动显示
入口参数：无
返 回 值：无	
************************************************/
void lcd_rol(void)					
{
    uint8_t i;
    for(i = 0; i < 64; i++)
    {
        CS1(0); // 片选1
        SendCommandToLCD(0xc0+i);
        CS1(1); 
        CS2(0);	// 片选2
        SendCommandToLCD(0xc0+62-i);
        CS2(0); // 片选2
        Delay_us(10);
    }
}	

/***********************************************
函数名称：LCD12864_Software_Init
功    能：初始化LCD
入口参数：无
返 回 值：无	
************************************************/
void LCD12864_Software_Init(void) 	  
{ 
	LCD_ALL_DIR_OUT();
	Delay_us(10);
	SelectScreen(0);
	SetOnOff(0); //关显示
	Delay_us(10);
	SelectScreen(0);
	SetOnOff(1); //开显示
	Delay_us(10);
	SelectScreen(0);
	ClearScreen(0);//清屏
	Delay_us(10);
	SetStartLine(0); //开始行:0
	Delay_us(10);
	SetOnOff(0x3f);	//开显示
	Delay_us(10);
	ClearScreen(0);//清屏
	Delay_us(10);
}

/************************************************************
函数名称：Show_Hz
功    能：汉字显示函数
入口参数：X：横坐标值，Y：纵坐标值，hz：在字库中的第几个汉字
返 回 值：无	
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
函数名称：Show_Num
功    能：字母、数字、字符串显示函数
入口参数：X：横坐标值，Y：纵坐标值，str：是需要显示的内容
返 回 值：无	
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
函数名称：Display
功    能：显示全角汉字
入口参数：SS选屏参数，pagr选页参数，column选列参数，number选第几汉字输出
返 回 值：无	
***********************************************************************/
void Display(uint8_t ss,uint8_t page,uint8_t column,uint8_t number)
{
	int i;	//选屏参数，pagr选页参数，column选列参数，number选第几汉字输出
	SetOnOff(0x3f);			//开显示
	SelectScreen(ss);
	column=column&0x3f;
	SetLine(page);			//写上半页
	SetColumn(column); 		//控制列
	for(i=0;i<16;i++)  		//控制16列的数据输出
	{
		LCD12864_WriteByte(Hzk[i+32*number]); //i+32*number汉字的前16个数据输出	
	}
	SetLine(page+1);		//写下半页
	SetColumn(column); 		//控制列
    for(i=0;i<16;i++)	  	//控制16列的数据输出
	{
		LCD12864_WriteByte(Hzk[i+32*number+16]);	//i+32*number+16汉字的后16个数据输出
	}
} 

/**********************************************************************
函数名称：Displayen
功    能：显示半角汉字和数字和字母
入口参数：SS选屏参数，pagr选页参数，column选列参数，number选第几汉字输出
返 回 值：无	
***********************************************************************/
void Displayen(uint8_t ss,uint8_t page,uint8_t column,char num)
{
    uint8_t i;//选屏参数，pagr选页参数，column选列参数，number选第几汉字输出
    uint8_t number = num;
    SelectScreen(ss);
    column=column&0x3f;
    SetLine(page);	//写上半页
    SetColumn(column);
    for(i=0;i<8;i++)
    {
        LCD12864_WriteByte(ascll[i+16*number]);
    }
    SetLine(page+1);	//写下半页
    SetColumn(column);
    for(i=0;i<8;i++)
    {
        LCD12864_WriteByte(ascll[i+16*number+8]);
    }
}  

/**********************************************************************
函数名称：LCD_ALL_DIR_OUT
功    能：设置为使用引脚输出模式
入口参数：无
返 回 值：无	
***********************************************************************/   	   
void LCD_ALL_DIR_OUT(void)
{
	P0_Mode_PullUp(PINS_DATA);
	P2_Mode_PullUp(PINS_CMD);
	ClrBits(GPIO_CMD,PINS_ALL);
	ClrBits(GPIO_DAT,PINS_ALL);
}
