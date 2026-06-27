//feibonaqi
#include <stdio.h>

void feibo(int i, int j, int count)
{
    // 终止条件：打印满25个就返回
    if(count > 25)
        return;

    printf("%d ", i);  // 输出当前数
    // 下一组：当前j变成新i，i+j变成新j，计数+1
    feibo(j, i + j, count + 1);
}


int main()
{
    int i=1,j=1;
    feibo(i,j,1);

    return 0;
}