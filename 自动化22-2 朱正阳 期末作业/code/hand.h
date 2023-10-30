/*本文件的作用是将一些每个肯定会用到的头文件藏在这里，
让单个文件做单个文件的事情

伟大的PYTHON之父说过：

“不要重复造轮子”

*/

#ifndef _HAND_H
// 常用组
#include <stdio.h>
#include <string.h>
#include <stdlib.h> // 引入stdlib头文件以使用malloc函数
// stdlib .h 头文件定义了四个变量类型、一些宏和各种通用工具函数。(int()函数)

#include <time.h> //读取时间作为random()函数的参数
#include <conio.h>
#include <windows.h> //该库用于GUI界面的操控。

#endif

/*<conio.h> 是一个C语言库，它提供了一些用于控制台输入/输出的功能。
这个库主要在Windows和DOS操作系统中使用，而在现代的Unix-like系统（如Linux和macOS）中，这个库通常不可用。

<conio.h> 库包含了一些函数，这些函数可以用于从键盘获取输入，而不需要用户按下回车键。
例如，getch() 函数可以立即从键盘获取一个字符，而不需要等待用户按下回车键。

此外，<conio.h> 还提供了一些用于控制控制台输出的函数，例如 gotoxy() 可以将光标移动到指定的屏幕位置。
然而，需要注意的是 <conio.h> 并不是标准C库的一部分，它通常用于Windows和DOS系统的特定应用程序。
在Unix-like系统中，要实现类似的功能，通常需要使用termios库或者ncurses库。

以下是一些 <conio.h> 中常见的函数：

getch(): 从键盘获取一个字符，无需按回车键。
gotoxy(int x, int y): 将控制台的光标移动到指定的屏幕位置。
kbhit(): 如果有一个键被按下，则返回非零值。
clrscr(): 清除控制台屏幕。
需要注意的是，由于 <conio.h> 主要用于Windows和DOS系统，因此在现代的Unix-like系统（如Linux和macOS）上，这个库通常不可用。
在Unix-like系统上，要实现类似的功能，通常需要使用termios库或者ncurses库。*/
