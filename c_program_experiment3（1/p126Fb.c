#include <stdio.h>

int zonghe(int a,int b,int c,int d,int e)
{
    return a+b+c+d+e;
}

int pingjunzhi(int a,int b,int c,int d,int e)
{
    return (a+b+c+d+e)/5;
}

int biaozhuncha(int a,int b,int c,int d,int e)
{
    int arr[5]={a,b,c,d,e};
    int avg = (a+b+c+d+e)/5;
    int i = 0;
    int j = 0;
    for(i=0;i<5;i++)
    {
        j += (arr[i]-avg)*(arr[i]+avg);
    }
    return j/5;
}
int main()
{
    //input
    int a=0,b=0,c=0,d=0,e=0;
    scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
    //clac
    int q = zonghe(a,b,c,d,e);
    int p = pingjunzhi(a,b,c,d,e);
    int k = biaozhuncha(a,b,c,d,e);

    printf("%d %d %d\n",q,p,k);

    return 0;
}