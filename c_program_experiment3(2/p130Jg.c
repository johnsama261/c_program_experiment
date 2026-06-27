#include <stdio.h>

void yiwei(int *x,int *y,int *z)
{
    int temp = *z;
    *z = *y;
    *y = *x;
    *x = temp;
}

int main()
{
    int a = 5,b = 8,c = 10;
    yiwei(&a,&b,&c);

    return 0;
}