#include "hand.h"

#define MAX_NAME_LENGTH 50
#define MAX_STUDENTS 300

int ReadStudents()
{
    // 文件输入
    char _path[200];
    printf("请输入名单所在文件的 “绝对路径”\n");
    scanf("%s", _path);

    FILE *file;
    file = fopen(_path, "r");
    if (file == NULL)
    {
        printf("无法打开文件\n");
        return 1;
    }

    char names[MAX_STUDENTS][MAX_NAME_LENGTH]; // 定义一个字符串数组用于存储名单
    int num_names = 0;

    fseek(file, 0, SEEK_SET);
    while (!feof(file) && num_names < MAX_STUDENTS)
    {                                         // 循环读取每一行，直到文件结束或名单已满
        fscanf(file, "%s", names[num_names]); // 读取一行
        num_names++;
    }

    fclose(file); // 关闭文件
    printf("成功读取了：%d 行\n", num_names);

    // 输出:创建一个弹窗并实现结果

    int go = 1; // 循环初始化
    while (go != -1)
    {
        // 使用当前时间作为种子来初始化随机数生成器
        srand(time(NULL));
        // 生成一个随机数，并对其进行取模运算，以获取在有效学生范围内的随机索引
        int selected_student = rand() % num_names;

        char buffer[200];
        sprintf(buffer, "抽到的学生是：%s ，学号为 %d", names[selected_student], selected_student + 1);
        int result = MessageBox(NULL, buffer, "抽奖成功", MB_RETRYCANCEL);

        switch (result)
        {
        case IDABORT:
            // 用户点击了"重试"按钮，在此处添加相应的代码
            go = -1;
        case IDIGNORE:
            MessageBox(NULL, "你真的要退出吗？", "多抽几个嘛 qwq", MB_OK);
        }
    }
    return 0;
}

/*
首先，它定义了两个宏：MAX_NAME_LENGTH 和 MAX_STUDENTS。前者设定了每个名字的最大长度为50个字符，后者设定了学生人数的最大值为300。

ReadStudents() 函数是主要功能函数。在这个函数中：

它试图打开一个名为 students.txt 的文件，该文件应该包含学生的名字和学号。如果文件无法打开，函数会打印错误信息并返回1。
定义一个字符串数组 names，用于存储读取到的学生名字。数组的大小为 MAX_STUDENTS x MAX_NAME_LENGTH，确保能够存储每个学生的名字和学号（假设学号是数字，每个数字占一个字符）。
使用 fseek(file,0,SEEK_SET) 将文件指针重新定位到文件的开始位置。
通过一个循环从文件中读取每一行的内容，并将每行的内容（假设是学生的名字）存储在 names 数组中。循环会一直进行，直到达到文件末尾或者已读取的学生数量达到 MAX_STUDENTS。
使用 fclose(file) 关闭文件。
打印成功读取的学生数量。
使用当前时间作为随机数生成器的种子，以确保每次程序运行时都能产生不同的随机数。
生成一个随机数，并取模以获取一个在有效学生范围内的随机索引。
打印选定的学生的名字和学号（这里的学号其实就是前面生成的随机索引）。
*/
