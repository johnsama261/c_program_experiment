//打印每位立方和等于本身的数
#include <stdio.h>

int main()
{
    int a,b,c,d;

    for (a = 1;a<=500;a++)
    {
        b = a;
        c = 0;
        while(b!=0)
        {
            d = b%10;
            c += d*d*d;
            b =b/10;
        }
        if (c==a)
        {
            printf("%d\n",a);
        }
    }
    return 0;
}