#include <stdio.h>

// 自定义xgets：读取一行，不含换行符
void xgets(char str[]) {
    int i = 0;
    char ch;
    // 循环读取字符，直到回车
    while ((ch = getchar()) != '\n') {
        str[i++] = ch;
    }
    str[i] = '\0'; // 字符串结束标记
}

// 自定义xputs：输出字符串并自动换行
void xputs(char str[]) {
    int i = 0;
    while (str[i] != '\0') {
        putchar(str[i]);
        i++;
    }
    putchar('\n'); // puts自带换行
}

int main() {
    char buf[100];
    printf("请输入一行文字（可带空格）：\n");
    xgets(buf);

    printf("你输入的内容是：\n");
    xputs(buf);
    return 0;
}