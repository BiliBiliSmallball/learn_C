#include "./hand.h"
// 本文件的函数是为了计算使用。
#define MAX_STUDENTS 200

struct student* Caculate(const char *filename)     
{    
    
    if (filename == NULL) {    
        printf("FileRead failed!\n");    
        return NULL;    
    }    
  	  
    int go = 1; // 循环初始化  
    while (go != -1)  
    {  
        // 生成一个随机数，并对其进行取模运算，以获取在有效学生范围内的随机索引  
        int selected_student = rand() %sizeof(filename);  
  
        char buffer[200];  
        sprintf(buffer, "抽到的学生是：%s ，学号为 %d", filename[selected_student], selected_student + 1);  
        int result = MessageBox(NULL, buffer, "抽奖成功", MB_RETRYCANCEL);  
  
        switch (result)  
        {  
        case IDABORT:  
            // 用户点击了"重试"按钮，在此处添加相应的代码  
            go = -1;  
            break;  
        case IDIGNORE:  
            MessageBox(NULL, "你真的要退出吗？", "多抽几个嘛 qwq", MB_OK);  
            go = -1;  
            break;  
        }  
    }  
      
    free(filename);    
    return 0; // 或者你可以在这里返回任何你需要的结果    
}
