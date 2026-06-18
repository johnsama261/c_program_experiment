#include <stdio.h>

int feidigui(int num)
{
    int sum = 0;
    for(int i = 0;i<5;i++)
    {
        sum += num%10;
        num = num/10;
    }
    return sum;
}

int digui(int num)
{
    if(num == 0)
        return 0;
    return (num%10)+digui(num/10);
}

int main()
{
    int a=0;
    scanf("%d",&a);
    //clac
    int j = feidigui(a);
    //clac digui
    int i = digui(a);

    printf("%d %d",j,i);

    return 0;
}