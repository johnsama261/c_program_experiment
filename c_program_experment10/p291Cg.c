#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 屏幕常量
#define ZUO_X 0
#define SHANG_Y 1
#define YOU_X 79
#define XIA_Y 23
#define TISHI_Y 24
#define MEIYE_HANG 23

// 替代gotoxy：ANSI光标定位 (x列,y行)
void set_cursor(int x, int y)
{
    printf("\033[%d;%dH", y+1, x+1);
}

// 绘制外框
void hua_kuang()
{
    int i;
    // 上边框 y=1
    set_cursor(ZUO_X, SHANG_Y);
    printf("┌");
    for(i=ZUO_X+1; i<YOU_X; i++) printf("─");
    printf("┐");
    // 左右竖边 y=2~22
    for(i=SHANG_Y+1; i<XIA_Y; i++)
    {
        set_cursor(ZUO_X, i);
        printf("│");
        set_cursor(YOU_X, i);
        printf("│");
    }
    // 下边框 y=23
    set_cursor(ZUO_X, XIA_Y);
    printf("└");
    for(i=ZUO_X+1; i<YOU_X; i++) printf("─");
    printf("┘");
}

// 清屏+打印标题行(文件名+页码)
void da_biaoti(char *wenjianming, int ye)
{
    system("clear"); // Linux/macOS清屏；Windows替换为system("cls")
    set_cursor(0,0);
    printf("文件：%s | 页码：%d", wenjianming, ye);
    hua_kuang();
}

// 底部提示行
void da_tishi()
{
    set_cursor(0, TISHI_Y);
    printf("Press any key...");
}

// 跨平台无阻塞按键读取
char get_key()
{
    system("stty raw -echo");
    char c = getchar();
    system("stty sane");
    return c;
}

int main()
{
    FILE *fp;
    char wenjianming[128];
    char hang[256];
    int ye=1, hangshu=0;

    printf("输入要读取的文本文件名：");
    scanf("%s", wenjianming);
    fp = fopen(wenjianming, "r");
    if(!fp)
    {
        printf("文件打开失败！");
        return 1;
    }

    da_biaoti(wenjianming, ye);
    int dangqian_y = SHANG_Y + 1;

    while(fgets(hang, sizeof(hang), fp) != NULL)
    {
        if(hangshu >= MEIYE_HANG)
        {
            da_tishi();
            get_key();
            ye++;
            hangshu = 0;
            dangqian_y = SHANG_Y + 1;
            da_biaoti(wenjianming, ye);
        }
        set_cursor(ZUO_X+1, dangqian_y);
        printf("%.*s", YOU_X-2, hang);
        dangqian_y++;
        hangshu++;
    }

    fclose(fp);
    da_tishi();
    get_key();
    return 0;
}