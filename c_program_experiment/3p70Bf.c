#include <stdio.h>

int main()
{
    int a = 0;
    int b = 0;
    int computer = 0;
    int chose = 0;
    for (int i = 1;i<=4;i+=1) 
    {
        printf("从1到4中选择你选择的火柴数\n");
        scanf("%d",&chose);
        computer = 5 -chose;
        printf("电脑抽取%d根火柴\n",computer);
     
    }
    printf("从1到4中选择你选择的火柴数\n");
    scanf("%d",&b);
    printf("你选走了最后一根，再试一次吧");
    
    return 0;
}