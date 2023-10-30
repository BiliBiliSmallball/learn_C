#include "./hand.h"
#include <windows.h> //该库用于GUI界面的操控。

void _print_name(char* a,int b){
	//本函数用于创建一个弹窗并实现结果 
	
	int go=1;//循环初始化  
    while(go != -1){	
		char buffer[200]; 
  		sprintf(buffer,"抽到的学生是：%s ，学号为 %d", a, b);  
        int result = MessageBox(NULL,buffer, "抽奖成功", MB_ABORTRETRYIGNORE);  
          
        switch(result) {    
            case IDRETRY:    
                // 用户点击了"OK"按钮，在此处添加相应的代码  
                break;    
            case IDABORT:    
                // 用户点击了"重试"按钮，在此处添加相应的代码  
                go = -1;  
        }  
    }  
}

//IDOK：用户点击了"OK"按钮。
//IDCANCEL：用户点击了"取消"按钮。
//IDABORT：用户点击了"中止"按钮。
//IDRETRY：用户点击了"重试"按钮。
//IDIGNORE：用户点击了"忽略"按钮。
