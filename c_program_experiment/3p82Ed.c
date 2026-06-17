#include <stdio.h>

int main ()
{
    for(int i = 1;i<=3;i++)
    {
        for(int k = 1;k<=3;k++)
        {
            for(int j = 1;j<=3;j++)
            {
                int sum = 100*i+10*k+j;
                printf("%d\n",sum);
            }
        }
    }
    return 0;
}