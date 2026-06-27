//ejinzhi

#include <stdio.h>

void ejinzhi(int n)
{
    return n ==0 ? 0 :(ejinzhi(n/2),printf("%d",n%2));
}

int main()
{
    int num;
    scanf("%d",&num);
    ejinzhi(num);

    return 0;
}