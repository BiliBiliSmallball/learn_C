#include "hand.h"
#include "./_open_list.h"
#include "./_caculate.h"

/* �����ʹ�ÿ���̨��ͣ����������������򣬻�����Ҳ�����Լ���� getch��system("pause") ��������ѭ������ͣ���򣬵ȴ��û����롣*/

int main(int argc, char *argv[]) {    
    // ǰ��׼��    
    char path[1024]; // ���󻺳�����С�Է�ֹ���    
    srand((unsigned)time(0)); // �������ʼ��
	int i;    
    
    // �û������ļ�·��    
    printf("������·����\n");    
    scanf("%s", path); //..\ǰ������\destination_folder\students.txt  
    
    struct student* p = FileRead(path); // ���������ڽ���Ȳ���û�а취.    
    if (p == NULL) {    
        printf("�ļ���ȡʧ�ܣ�\n");    
        return 0;    
    } else {    
        for(i=0; i<100; i++) { // ��ӡ����ѧ������  
            Caculate(p);
        }  
        free(p); // �ͷ��ڴ棬��Ϊ�������ǲ�����Ҫ����    
    }  
    system("pause");  
    return 0;    
}
