#include <stdio.h>
#include <conio.h>

#define UP_ARROW    72
#define DOWN_ARROW  80
#define LEFT_ARROW  75
#define RIGHT_ARROW 77
#define ESC_KEY     27

char *monthName[] = {"January","February","March","April","May","June",
                     "July","August","September","October","November","December"};

int getkey()
{
    while(!_kbhit());
    int ch = _getch();
    if(ch == 0 || ch == 224)
        return _getch();
    return ch;
}

int isLeap(int year)
{
    return (year%4==0 && year%100!=0) || (year%400==0);
}

int getDayCount(int mon, int year)
{
    int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if(mon == 2 && isLeap(year)) return 29;
    return days[mon-1];
}

long totalDays(int mon, int year)
{
    long sum = 0;
    int y,m;
    for(y=1900; y<year; y++)
        sum += isLeap(y)?366:365;
    for(m=1; m<mon; m++)
        sum += getDayCount(m, year);
    return sum;
}

void printCalendar(int mon, int year)
{
    system("cls");
    long allDay = totalDays(mon, year);
    int firstWeek = allDay % 7;
    int daysInMonth = getDayCount(mon, year);
    int i,day;

    printf("          %s %d\n", monthName[mon-1], year);
    printf("Mon   Tue   Wed   Thu   Fri   Sat   Sun\n");
    for(i=0; i<firstWeek; i++) printf("      ");
    for(day=1; day<=daysInMonth; day++)
    {
        printf("%3d   ", day);
        if((firstWeek + day) % 7 == 0) printf("\n");
    }
    printf("\n\n操作：↑下一年 ↓上一年 ←上月 →下月 | ESC退出\n");
}

int main()
{
    int mon, year, key;
    printf("输入初始月份(1-12) 年份: ");
    scanf("%d %d", &mon, &year);
    while(1)
    {
        printCalendar(mon, year);
        key = getkey();
        switch(key)
        {
            case UP_ARROW: year++; break;
            case DOWN_ARROW: year--; break;
            case RIGHT_ARROW: mon++; if(mon>12){mon=1;year++;} break;
            case LEFT_ARROW: mon--; if(mon<1){mon=12;year--;} break;
            case ESC_KEY: system("cls");printf("退出成功\n");return 0;
        }
    }
    return 0;
}