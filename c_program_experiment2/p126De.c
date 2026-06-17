#include <stdio.h>

void zhiyinshu(int n)
{
    while(n % 2 ==0)
    {
        printf("%d ",2);
        n = n/2;
    }
    for(int i = 3;i*i<=n;i +=2)
    {
        while(n % i ==0)
        {
            printf("%d ",i);
            n = n/i;
        }
    }
    if(n > 1)
        printf("%d",n);
}
//质数参与的最优解，先排除2，然后从小到大排除奇数，记得先和9比较
int main()
{
    int num;
    scanf("%d",&num);
    zhiyinshu(num);

    return 0;
}