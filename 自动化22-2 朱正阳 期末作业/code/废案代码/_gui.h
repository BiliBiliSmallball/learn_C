#include "./hand.h"
#include <windows.h> //�ÿ�����GUI����Ĳٿء�

void _print_name(char* a,int b){
	//���������ڴ���һ��������ʵ�ֽ�� 
	
	int go=1;//ѭ����ʼ��  
    while(go != -1){	
		char buffer[200]; 
  		sprintf(buffer,"�鵽��ѧ���ǣ�%s ��ѧ��Ϊ %d", a, b);  
        int result = MessageBox(NULL,buffer, "�齱�ɹ�", MB_ABORTRETRYIGNORE);  
          
        switch(result) {    
            case IDRETRY:    
                // �û������"OK"��ť���ڴ˴������Ӧ�Ĵ���  
                break;    
            case IDABORT:    
                // �û������"����"��ť���ڴ˴������Ӧ�Ĵ���  
                go = -1;  
        }  
    }  
}

//IDOK���û������"OK"��ť��
//IDCANCEL���û������"ȡ��"��ť��
//IDABORT���û������"��ֹ"��ť��
//IDRETRY���û������"����"��ť��
//IDIGNORE���û������"����"��ť��
