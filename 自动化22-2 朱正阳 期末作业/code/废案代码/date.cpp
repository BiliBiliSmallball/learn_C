#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

//�����ṹ�崢���ȡ����Ϣ
	struct student
	{
		char student_name[30];
	}stu[100];
	
//��filedate.txt�����ݵ��룬���õ�������
int fileread(const char *filename)
{
	FILE *fp = fopen(filename,"r");
	if(fp == NULL)			//��û���ļ��ɶ����򷵻ش�����Ϣ
	{
		perror("file open failed:");
		return -1;
	}
	
	int i;
	for(i =0;!feof(fp);i++)	//����������Ϣ¼��ṹ����
	{
		fgets(stu[i].student_name,30,fp);
//		printf("%s\n",stu[i].student);
	}
	strcat(stu[i].student_name,"\n");
	
	return i;		//����������
	fclose(fp);				//�ͷ�ָ��
}

//ʹ�û������Լ��ĵ�Ŀ�����֣������������Աȣ��ж��Ƿ񲻺Ϲ���
int  ju_num(int std_num)
{
	int num = 0;
	while(true)
	{
		printf("����Ҫ����������أ�\n");
		scanf("%d",&num);			//ʹ�û�����Ŀ����ֵ
		if(num >std_num)
		{
			printf("����������ִ��������������������룺\n");
			system("pause");		//���������������
			system("cls");			//����
			continue;				//������һ��ѭ��
		}
		else if(num <1)
		{
			printf("�����������̫С�ˣ����������룺\n");
			system("pause");
			system("cls");
			continue;
		}
		break;	//���û�и���Ҳû�и�С����ֱ������ѭ��
	}
	return num;		//�����û������������
}

void delay(unsigned int ms) 	//��ʱ����
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
	srand((unsigned)time(NULL));				//�������ʼ��
	int std_num =fileread("./filedate.txt");	//��filedate��ʼ��,����������
	
	while(true)
	{
		int rand_std_num = ju_num(std_num);			//�ж��������Ƿ��������,�����û��������������
			
			system("cls");
			
			int rand_num[rand_std_num],rand_temp;	//������������� 
			for(int i = 0;i<rand_std_num;i++)		//����õ����˹���
			{
				next_rand:
				rand_temp = rand()%std_num;
				for(int p = 0;p<=i;p++)				//ɸѡ�ظ��������
				{
					if(rand_temp == rand_num[p])
					{
						goto next_rand;
					}
				}	
				rand_num[i] = rand_temp;			//��û���ظ����������������
//				printf("%d\n",rand_num[i]);
			}
			
			for(int i = 0;i<rand_std_num;i++)		//ʹ��ð��������������������
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
			
			printf("%s%d%s","���ѡ����",rand_std_num,"����,�������:\n");
			for(int i =0;i<rand_std_num;i++)		//ѭ����ӡ������Ŀ��
			{
				delay(1500);
				printf("%s",stu[rand_num[i]].student_name);
			}
			
			printf("\n\n����'�ո�'�ɽ������³�ȡ");
			printf("\n����'ESC'��ֱ���˳�������\n\n\n\n\n\n");
			
			int key = 0;
			while(key != 0x20||key !=0x1B)
			{
				key = _getch();
				if(key == 0x20)
				{
					system("cls");
					printf("������������������һ�ֳ�ȡ��������");
					delay(50000);
					system("cls");
					break;
				}
				else if(key == 0x1B)
				{
					system("cls");
					printf("����������л����ʹ�ã�лл����������\n");
					delay(30000);
					return 0;
				}
				
			}
	}
}
