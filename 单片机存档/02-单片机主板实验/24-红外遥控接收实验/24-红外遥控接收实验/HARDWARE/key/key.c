#include "system.h"
#include "key.h"

/**************************************************
函数名称：Key_Configure
函数说明：按键初始化配置函数	
输入参数：	无			
返 回 值：	无			
**************************************************/
void Key_Configure(void)
{
	P3_Mode_HighZ( KEY0_PIN | KEY1_PIN );
}

/**************************************************
函数名称：Key_Scan
函数说明：按键扫描函数	
输入参数：	无			
返 回 值：	KEY0_NUM(1)		扫描到按键KEY0按下
			KEY1_NUM(2)		扫描到按键KEY1按下
**************************************************/
uint8_t Key_Scan()
{	
	uint8_t key_value = 1;
	//判断按键是否按下
	if( !(KEY0 & KEY1) )				
	{	
		//软件消抖 	抖动时间的长短由按键的机械特性决定，一般为5ms～10ms
		Delay_ms(10);	
		//再次判断按键是否按下
		if( !(KEY0 & KEY1) )			
		{	
			//读取按键0，如果按下即为低电平，所以要取反
				if( ! KEY0  )
					key_value =	KEY0_NUM;	
				//读取按键1，如果按下即为低电平，所以要取反
				else if( ! KEY1  )
					key_value =	KEY1_NUM;	
		}
		//返回按键值
		return key_value;
	}
	return 0;
}

//                                      endfile
