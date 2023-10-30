#include "hand.h"
#include "./_open_list.h"
#include "./_caculate.h"

/* 你可以使用控制台暂停功能来运行这个程序，或者你也可以自己添加 getch、system("pause") 或者输入循环来暂停程序，等待用户输入。*/

int main(int argc, char *argv[]) {    
    // 前期准备    
    char path[1024]; // 增大缓冲区大小以防止溢出    
    srand((unsigned)time(0)); // 随机数初始化
	int i;    
    
    // 用户输入文件路径    
    printf("请输入路径：\n");    
    scanf("%s", path); //..\前置条件\destination_folder\students.txt  
    
    struct student* p = FileRead(path); // 主程序，现在解耦度不高没有办法.    
    if (p == NULL) {    
        printf("文件读取失败！\n");    
        return 0;    
    } else {    
        for(i=0; i<100; i++) { // 打印所有学生姓名  
            Caculate(p);
        }  
        free(p); // 释放内存，因为现在我们不再需要它了    
    }  
    system("pause");  
    return 0;    
}
