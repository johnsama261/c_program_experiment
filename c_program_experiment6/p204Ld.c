#include <stdio.h>
#include <conio.h>

#define UP    72
#define DOWN  80
#define LEFT  75
#define RIGHT 77

// 替代原dos.h的getkey，兼容现代控制台
int getkey()
{
    while (!_kbhit());
    int ch = _getch();
    // 方向键会先输出0xE0扩展码，再返回扫描码
    if (ch == 0 || ch == 224)
        return _getch();
    return ch;
}

void printBoard(int board[4][4])
{
    int i,j;
    system("cls");
    printf("=====15 PUZZLE GAME=====\n");
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(board[i][j]==0)
                printf("[  ] ");
            else
                printf("[%2d] ", board[i][j]);
        }
        printf("\n");
    }
    printf("========================\n");
    printf("方向键移动，排序1~15即通关\n");
}

void findBlank(int board[4][4], int *x, int *y)
{
    int i,j;
    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
            if(board[i][j]==0)
            {
                *x = i;
                *y = j;
                return;
            }
}

int isWin(int board[4][4])
{
    int num=1,i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(i==3 && j==3) break;
            if(board[i][j] != num) return 0;
            num++;
        }
    }
    return 1;
}

int main()
{
    int board[4][4] = {
        {1,  4, 15, 7},
        {8, 10,  2,11},
        {14, 3,  6,13},
        {12, 9,  5, 0}
    };
    int blankX, blankY;
    int key, step=0;
    int temp;

    while(1)
    {
        printBoard(board);
        if(isWin(board)) break;
        findBlank(board, &blankX, &blankY);
        key = getkey();

        if(key == RIGHT)
        {
            if(blankY - 1 >= 0)
            {
                temp = board[blankX][blankY-1];
                board[blankX][blankY-1] = board[blankX][blankY];
                board[blankX][blankY] = temp;
                step++;
            }
        }
        else if(key == DOWN)
        {
            if(blankX - 1 >= 0)
            {
                temp = board[blankX-1][blankY];
                board[blankX-1][blankY] = board[blankX][blankY];
                board[blankX][blankY] = temp;
                step++;
            }
        }
        // 上、左箭头无操作
    }

    printBoard(board);
    printf("通关！总步数：%d\n", step);
    return 0;
}