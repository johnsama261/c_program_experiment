#include <stdio.h>

int main1()
{
    //input 
    int a = 0;
    scanf("%d",&a);
    //clac
    
    int j = 1;
    for(int i = a;i>0;i--)
    {
        j = j*i;
    }
    //output
    printf("%d\n",j);

    return 0;
}
//问题是没有0和-1的判断，还没有考虑阶乘过大超过int存储
long long factorial(int num)
{
    // 负数无阶乘，返回-1标记错误
    if(num < 0)
        return -1;
    // 0! 和 1! 都等于1
    long long res = 1;
    for(int i = num; i > 0; i--)
    {
        res = res * i;
    }
    return res;
}
int main()
{
    int a = 0;
    printf("请输入整数：");
    scanf("%d", &a);
    
    long long result = factorial(a);
    if(result == -1)
    {
        printf("负数不存在阶乘\n");
    }
    else
    {
        printf("%d 的阶乘 = %lld\n", a, result);
    }
    return 0;
}