#include<stdio.h>  
#include<stdlib.h>  // 引入标准库，用于内存管理和其他通用服务    
#include<string.h>  //调用一个字符串行数库 
#include<time.h>  // 引入时间库，用于获取时间，与下面rand一起使用以产生随机数    
#include<windows.h> // 引入Windows库，这个库包含许多用于Windows操作系统编程的函数和定义  
#include<conio.h>  // 引入CONIO库，这是一个包含许多用于控制台和基于文本的图形用户界面的函数库 
  
 
struct students // 定义一个结构体，名为students，包含一个字符数组作为班级成员 
{  
        char a[60];  
};  
  
int main()  
{  
        int n=52;  // 定义并初始化一个整型变量n为52，代表抽奖候选人的数量 
	    struct students a[55];   	// 定义一个students类型的数组，数组长度为55，数组名为a  
        strcpy(a[0].a,"李腾");  	// 使用strcpy函数将字符串"名字"复制到a[0]的a成员中
        strcpy(a[1].a,"郑家辉");  	//书本119页对strcpy函数功能有详细说明 
        strcpy(a[2].a,"杨杰");  
        strcpy(a[3].a,"李亦欣");  
        strcpy(a[4].a,"杨婷");  
        strcpy(a[5].a,"许佳惠");  
        strcpy(a[6].a,"郭宇欣");  
        strcpy(a[7].a,"邹嘉诚");  
        strcpy(a[8].a,"何宇豪");  
        strcpy(a[9].a,"王梓豪");  
        strcpy(a[10].a,"许志荣");  
        strcpy(a[11].a,"罗杰");  
        strcpy(a[12].a,"刘丰禾");  
        strcpy(a[13].a,"高阳");  
        strcpy(a[14].a,"涂华凯");  
        strcpy(a[15].a,"刘彬");  
        strcpy(a[16].a,"吴宇哲");  
        strcpy(a[17].a,"丁凡祺");  
        strcpy(a[18].a,"韩世彦");  
        strcpy(a[19].a,"朱正阳");  
        strcpy(a[20].a,"孙炜杰");  
        strcpy(a[21].a,"刘笑笑");  
        strcpy(a[22].a,"黄援媛");  
        strcpy(a[23].a,"白帆");  
        strcpy(a[24].a,"李宇翔");  
        strcpy(a[25].a,"罗公博");  
        strcpy(a[26].a,"范斌贤");  
        strcpy(a[27].a,"卢佳豪");  
        strcpy(a[28].a,"黄承烨");  
        strcpy(a[29].a,"王聪华");  
        strcpy(a[30].a,"孙瑞");  
        strcpy(a[31].a,"董飞伯");  
        strcpy(a[32].a,"莫崇韬");  
        strcpy(a[33].a,"黄嘉俊");  
        strcpy(a[34].a,"黄云可");  
        strcpy(a[35].a,"叶焯辉");  
        strcpy(a[36].a,"张旺");  
        strcpy(a[37].a,"董佑欣");  
        strcpy(a[38].a,"观凯壬");  
        strcpy(a[39].a,"陈妃胜");  
        strcpy(a[40].a,"陈柏霖");  
        strcpy(a[41].a,"王建锋");  
        strcpy(a[42].a,"邓植荟");  
        strcpy(a[43].a,"李家涛");  
        strcpy(a[44].a,"何杭杭");  
        strcpy(a[45].a,"车德斌");  
        strcpy(a[46].a,"曹子杰");  
        strcpy(a[47].a,"周子柠");  
        strcpy(a[48].a,"赖敏杰");  
        strcpy(a[49].a,"刘相佶");  
        strcpy(a[50].a,"张勇畅");  
        strcpy(a[51].a,"吴瑞佩");   
         
        printf("按任意键开始抽奖（按0退出）\n");  
          
        char ch; // 定义一个字符变量
        while(1)   // 若没有输入0则开始一个无限循环
        {  
                ch=getch();   // 获取用户从键盘输入的值并保存到ch变量中      
                if(ch=='0')break;                    
                srand((unsigned)time(NULL));   // 使用当前时间作为随机数种子，初始化随机数生成器，保证每次运行程序时生成的随机数序列都不同
                int k=rand()%n;  // 使用随机数生成器生成一个在0到n（不包括n）之间的随机整数k，代表获奖者编号  
                system("cls"); // 使用Windows API函数清除屏幕，实际应用中可能需要根据操作系统进行调整，例如在Linux下可以使用system("clear") 
        
                for(int j=0;j<2;j++) // 一个嵌套循环，为了制造一种动画效果，循环两次打印出四个点，然后清除屏幕并重新打印四个点，重复两次  
                {  
                        for(int i=0;i<4;i++)  
                        {   
                                printf(".");  // 打印一个点   
                                Sleep(100); // 休眠作用，程序运行到这里就要暂停100ms在继续，且这个函数要包含在Windows头文件里 
                        }   
                        system("cls");  //Closing缩写 ，清除屏幕，为下一次打印做准备  
                }  
                
                printf("%s\n",a[k]); 
                printf("按任意键开始抽奖（按0退出）\n");  
        }  
    }
          
