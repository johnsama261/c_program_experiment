#include <stdio.h>
int main()
{
    int sz[100];
    int i,j;
    //步骤1：填充1~100
    for(i=0;i<100;i++)
        sz[i] = i+1;

    //步骤2-4：筛法核心
    for(i=1;i<100;i++) //i=1对应数字2
    {
        if(sz[i]==0) continue;
        //把当前数的倍数置0
        for(j=sz[i]*2-1;j<100;j+=sz[i])
            sz[j]=0;
    }

    //步骤5：打印非0素数，跳过1
    printf("1~100所有素数：\n");
    for(i=0;i<100;i++)
    {
        if(sz[i]>1)
            printf("%d ",sz[i]);
    }
    return 0;
}