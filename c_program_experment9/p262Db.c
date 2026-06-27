#include <stdio.h>

// 自定义getint函数
int getint() {
    char str[100];
    int num = 0, i = 0;
    // 读取数字字符串
    while ((str[i] = getchar()) != '\n') {
        i++;
    }
    str[i] = '\0';

    // 字符串转数字（手动实现，不调用atoi）
    i = 0;
    while (str[i] != '\0') {
        num = num * 10 + (str[i] - '0');
        i++;
    }
    return num;
}

// 题目给出的主函数
void main()
{
    int a;
    a = getint();
    printf("you entered %d", a);
}