#include <stdio.h>

int main()
{
    int sz[25];
    int x, cnt = 0, i;
    // shuru 25 ge shu
    for(i = 0; i < 25; i++)
    {
        scanf("%d", &sz[i]);
    }
    // shuru yao zhao de shu
    scanf("%d", &x);
    // bian li tong ji ci shu
    for(i = 0; i < 25; i++)
    {
        if(sz[i] == x)
            cnt++;
    }
    if(cnt > 0)
        printf("shu zi cun zai, chu xian %d ci", cnt);
    else
        printf("shu zi bu cun zai");
    return 0;
}