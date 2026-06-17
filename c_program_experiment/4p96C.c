#include <stdio.h>
#include <stdbool.h>

long jiecheng(int n)
{
    long result = 1;
    for(int i = 1;i<=n;i++)
    {
        result *=i;
    }
    return result;
}

int sushu(int n)
{
    if (n<=1) return false;
    if (n==2) return true;
    if (n%2==0) return false;
    for (int i = 3;i*i<=n;i+=2)
    {
        if (n%i==0) return false;
    }
    return true;
}
 
int jioshu(int n)
{
    if(n%2 == 0)
    {
        return true;
    }
    else{
        return false;
    }
}

int main ()
{
    while (1)
    {
        int a = 0;
        int n = 0;
        printf("1阶乘\n2素数\n3奇偶\n4退出\n");
        scanf("%d",&a);
        switch(a)
        {
            case 1:
                scanf("%d",&n);
                if (n<0){
                    printf("负数没有阶乘\n");}
                else if(n>=0){
                    printf("%d的阶乘是%ld\n",n,jiecheng(n)); 
                }
                break;

            case 2:
                scanf("%d",&n);
                if(sushu(n)){
                    printf("%d是素数\n",n);
                }
                else{
                    printf("%d不是素数\n",n);
                }
                break;

            case 3:
                scanf("%d",&n);
                if(jioshu(n)){
                    printf("%d是偶数\n",n);
                }
                else{
                    printf("%d是奇数\n",n);
                }
                break;

            case 4:
                return 0;

            default:
                printf("false\n");
        }
    }
    return 0;
}