#include "./hand.h"
// ���ļ��ĺ�����Ϊ�˼���ʹ�á�
#define MAX_STUDENTS 200

struct student* Caculate(const char *filename)     
{    
    
    if (filename == NULL) {    
        printf("FileRead failed!\n");    
        return NULL;    
    }    
  	  
    int go = 1; // ѭ����ʼ��  
    while (go != -1)  
    {  
        // ����һ������������������ȡģ���㣬�Ի�ȡ����Чѧ����Χ�ڵ��������  
        int selected_student = rand() %sizeof(filename);  
  
        char buffer[200];  
        sprintf(buffer, "�鵽��ѧ���ǣ�%s ��ѧ��Ϊ %d", filename[selected_student], selected_student + 1);  
        int result = MessageBox(NULL, buffer, "�齱�ɹ�", MB_RETRYCANCEL);  
  
        switch (result)  
        {  
        case IDABORT:  
            // �û������"����"��ť���ڴ˴������Ӧ�Ĵ���  
            go = -1;  
            break;  
        case IDIGNORE:  
            MessageBox(NULL, "�����Ҫ�˳���", "��鼸���� qwq", MB_OK);  
            go = -1;  
            break;  
        }  
    }  
      
    free(filename);    
    return 0; // ��������������ﷵ���κ�����Ҫ�Ľ��    
}
