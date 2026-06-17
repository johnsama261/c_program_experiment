#include <stdio.h>

void luoma(int n)
{
    if(n/1000>0)
    {
        for(int i = 0;i<(n/1000);i++)
        {
            printf("m");
        }
    }
    n = n-1000*(n/1000);

    if(n/500>0)
    {
        for(int i = 0;i<(n/500);i++)
        {
            printf("d");
        }
    }
    n = n-500*(n/500);

    if(n/100>0)
    {
        for(int i = 0;i<(n/100);i++)
        {
            printf("c");
        }
    }
    n = n-100*(n/100);

    if(n/50>0)
    {
        for(int i = 0;i<(n/50);i++)
        {
            printf("l");
        }
    }
    n = n-50*(n/50);

    if(n/10>0)
    {
        for(int i = 0;i<(n/10);i++)
        {
            printf("x");
        }
    }
    n = n-10*(n/10);

    if(n/5>0)
    {
        for(int i = 0;i<(n/5);i++)
        {
            printf("v");
        }
    }
    n = n-5*(n/5);

    if(n/1>0)
    {
        for(int i = 0;i<(n/1);i++)
        {
            printf("i");
        }
    }
    n = n-1*(n/1);
}

int main()
{
    //input
    int a = 0;
    scanf("%d",&a);
    //calc
    luoma(a);

    return 0;
}