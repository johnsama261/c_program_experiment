#include <stdio.h>

int gcd (int j,int k)
{
    int a = 0,b = 0;
    while(k != 0)
    {
        a=j/k;
        b=j-a*k;
        j=k;
        k=b;
    }
    return j;
}

int main()
{
    int res = gcd(1980,1617);
    printf("%d\n",res);

    return 0;
}