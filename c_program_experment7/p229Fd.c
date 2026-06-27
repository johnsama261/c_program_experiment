#include <stdio.h>

// 月份名称映射
char *monthName[] = {"January","February","March","April","May","June",
                     "July","August","September","October","November","December"};

// 判断闰年：返回1闰年，0平年
int isLeap(int year)
{
    if((year%4==0 && year%100!=0) || (year%400==0))
        return 1;
    return 0;
}

// 获取某年某月总天数
int getDayCount(int mon, int year)
{
    int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if(mon == 2 && isLeap(year))
        return 29;
    return days[mon-1];
}

// 计算从1900-01-01到指定年月前一月末的总天数
long totalDays(int mon, int year)
{
    long sum = 0;
    int y,m;
    // 累加1900 ~ year-1 全年天数
    for(y=1900; y<year; y++)
        sum += isLeap(y) ? 366 : 365;
    // 累加当年1月 ~ mon-1月天数
    for(m=1; m<mon; m++)
        sum += getDayCount(m, year);
    return sum;
}

int main()
{
    int mon, year;
    int daysInMonth, firstWeek, day, i;
    printf("请输入月份(1-12)和年份：");
    scanf("%d %d", &mon, &year);

    // 1. 计算当月1号是星期几
    long allDay = totalDays(mon, year);
    firstWeek = allDay % 7; // 0=周一，1=周二...6=周日
    daysInMonth = getDayCount(mon, year);

    // 打印标题
    printf("\n          %s %d\n", monthName[mon-1], year);
    printf("Mon   Tue   Wed   Thu   Fri   Sat   Sun\n");

    // 打印第一行前置空白
    for(i=0; i<firstWeek; i++)
        printf("      ");

    // 逐天打印日期
    for(day=1; day<=daysInMonth; day++)
    {
        printf("%3d   ", day);
        // 到周日换行
        if((firstWeek + day) % 7 == 0)
            printf("\n");
    }
    printf("\n");
    return 0;
}