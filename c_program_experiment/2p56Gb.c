#include <stdio.h>

int main()
{
    char i;
    printf("写字符");
    scanf("%c",&i);

    if (i>='A' && i<='Z')
    {
        printf("i是大写字母");
    }
    else if (i>='a' && i<='z')
    {
        printf("i是小写字母");
    }
    else if (i>='0' && i<='9')
    {
        printf("i是数字");
    }
    else 
    {
        printf("i是特殊符号");
    }
    return 0;
}