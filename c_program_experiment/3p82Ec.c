#include <stdio.h>

int main()
{
    float c;
    float sum = 0;
    for(int i = 1;i<=7;i++)
    {
        long a = 1;
        for(int b = 1;b<=i;b++)
        {
            a *= b;
        }
        c = (float)i/a;
        sum +=c;
        
    }
    printf("%f\n",sum);
    
    return 0;
}