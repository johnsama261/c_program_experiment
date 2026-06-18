#include <stdio.h>

void zhiyinshu(int zhi)
{
    if(zhi <2)
    {
        printf("void");
        return;
    }
    while(zhi%2 == 0)
    {
        printf("2 ");
        zhi /=2;
    }
    for(int i = 3;i*i<zhi;i+=2)
    {
        while(zhi%i == 0)
        {
            printf("%d ",i);
            zhi = zhi/i;
        }
    }
    printf("%d ",zhi);
}

void zhiyinshu_digui(int zhi)
{
    if(zhi < 2)
        return;
    // 因子2
    if(zhi % 2 == 0)
    {
        printf("2 ");
        zhiyinshu_digui(zhi / 2);
        return;
    }
    // 奇数因子
    for(int i = 3; i*i <= zhi; i += 2)
    {
        if(zhi % i == 0)
        {
            printf("%d ", i);
            zhiyinshu_digui(zhi / i);
            return;
        }
    }
    // 剩余质数
    printf("%d ", zhi);
}

int main()
{
    int a = 0;
    scanf("%d",&a);

    zhiyinshu(a);
    printf("\n");
    zhiyinshu_digui(a);

    return 0;
}