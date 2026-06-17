//计算一个数的阶乘
#include <stdio.h>

int main()
{
    int a = 0;
    long b = 1;
    printf("给一个数计算阶乘\n");
    scanf("%d",&a);

    if (a<=0){
        printf("负数没有阶乘") ;

        return 0;
    }
    for (int i = 1;i<=a;i++)
    {
        b *= i;
    }
    printf("阶乘是%ld",b);
    return 0;
}