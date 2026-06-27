#include <stdio.h>
int main()
{
    int sz[100];
    int n,i,temp;
    printf("输入数组长度：");
    scanf("%d",&n);
    //输入数组
    for(i=0;i<n;i++)
        scanf("%d",&sz[i]);

    //交换奇偶下标成对元素，步长2
    for(i=0;i<n-1;i+=2)
    {
        temp=sz[i];
        sz[i]=sz[i+1];
        sz[i+1]=temp;
    }

    //输出结果
    printf("交换后数组：\n");
    for(i=0;i<n;i++)
        printf("%d ",sz[i]);
    return 0;
}