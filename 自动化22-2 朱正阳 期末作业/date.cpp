#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

//创建结构体储存读取的信息
	struct student
	{
		char student_name[30];
	}stu[100];
	
//将filedate.txt的内容导入，并得到总人数
int fileread(const char *filename)
{
	FILE *fp = fopen(filename,"r");
	if(fp == NULL)			//若没有文件可读，则返回错误信息
	{
		perror("file open failed:");
		return -1;
	}
	
	int i;
	for(i =0;!feof(fp);i++)	//将读到的信息录入结构体中
	{
		fgets(stu[i].student_name,30,fp);
//		printf("%s\n",stu[i].student);
	}
	strcat(stu[i].student_name,"\n");
	
	return i;		//返回总人数
	fclose(fp);				//释放指针
}

//使用户输入自己的的目标数字，并与总人数对比，判断是否不合规则
int  ju_num(int std_num)
{
	int num = 0;
	while(true)
	{
		printf("你想要点出几个人呢？\n");
		scanf("%d",&num);			//使用户输入目标数值
		if(num >std_num)
		{
			printf("你输入的数字大于总人数，请重新输入：\n");
			system("pause");		//按任意键继续运行
			system("cls");			//清屏
			continue;				//进行下一次循环
		}
		else if(num <1)
		{
			printf("你输入的数字太小了，请重新输入：\n");
			system("pause");
			system("cls");
			continue;
		}
		break;	//如果没有更大也没有更小，则直接跳出循环
	}
	return num;		//返回用户期望的随机数
}

void delay(unsigned int ms) 	//延时函数
{ 
	int a;
	for (unsigned int i = 0; i < ms; i++) 
	{ 
		for (unsigned int j = 0; j < 1000000; j++) 
		{ 
			a++;
		}
	}
}
		
int  main()
{
	srand((unsigned)time(NULL));				//随机数初始化
	int std_num =fileread("./filedate.txt");	//对filedate初始化,返回总人数
	
	while(true)
	{
		int rand_std_num = ju_num(std_num);			//判断总人数是否符合名单,返回用户期望的随机人数
			
			system("cls");
			
			int rand_num[rand_std_num],rand_temp;	//创建随机数名单 
			for(int i = 0;i<rand_std_num;i++)		//随机得到幸运观众
			{
				next_rand:
				rand_temp = rand()%std_num;
				for(int p = 0;p<=i;p++)				//筛选重复的随机数
				{
					if(rand_temp == rand_num[p])
					{
						goto next_rand;
					}
				}	
				rand_num[i] = rand_temp;			//将没有重复的随机数填入数组
//				printf("%d\n",rand_num[i]);
			}
			
			for(int i = 0;i<rand_std_num;i++)		//使用冒泡排序将随机数组进行排序
			{
				for(int p = 0;p<=i;p++)
				{
					if(rand_num[i] < rand_num[p])
					{
						int again_rand_temp = rand_num[i];
						rand_num[i] = rand_num[p];
						rand_num[p] = again_rand_temp;
					}
				}
			}
			
			printf("%s%d%s","随机选择了",rand_std_num,"个人,结果如下:\n");
			for(int i =0;i<rand_std_num;i++)		//循环打印输出随机目标
			{
				delay(1500);
				printf("%s",stu[rand_num[i]].student_name);
			}
			
			printf("\n\n按下'空格'可进行重新抽取");
			printf("\n按下'ESC'则直接退出本程序\n\n\n\n\n\n");
			
			int key = 0;
			while(key != 0x20||key !=0x1B)
			{
				key = _getch();
				if(key == 0x20)
				{
					system("cls");
					printf("————即将进行下一轮抽取————");
					delay(50000);
					system("cls");
					break;
				}
				else if(key == 0x1B)
				{
					system("cls");
					printf("————感谢您的使用，谢谢！————\n");
					delay(30000);
					return 0;
				}
				
			}
	}
}
