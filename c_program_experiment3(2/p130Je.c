#include <stdio.h>

int  ziran(int a)
{
    if(a == 1)
        return 1;
    return a + ziran( a - 1 );
}

int main()
{
    int a = 0;
    printf("前多少位自然数的和->");
    scanf("%d",&a);
    int num = ziran(a);
    printf("\n%d",num);

    return 0;
}