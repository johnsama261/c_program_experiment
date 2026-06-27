#include <stdio.h>
#include <string.h>

// 偏移加密固定值
#define PIANYI 128

// 替换映射表 明文0-127对应密文字符
char tihuan_ming[128] = {
    '0','1','2','3','4','5','6','7','8','9','!','@','#','$','%','^',
    '&','*','(',')','-','_','=','+','[','{',']','}','\\','|',';',':',
    '\'','"',',','<','.','>','/','?','A','B','C','D','E','F','G','H',
    'I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X',
    'Y','Z','a','b','c','d','e','f','g','h','i','j','k','l','m','n',
    'o','p','q','r','s','t','u','v','w','x','y','z',' ','\n','\t','\r','\0'
};
// 反向解密映射
char tihuan_mi[128];

// 初始化替换解密表
void init_tihuan()
{
    int i;
    memset(tihuan_mi,0,sizeof(tihuan_mi));
    for(i=0;i<128;i++)
    {
        tihuan_mi[(unsigned char)tihuan_ming[i]] = i;
    }
}

// 偏移加密
void piayi_jia(FILE *src,FILE *tar)
{
    char c;
    while((c=fgetc(src))!=EOF)
    {
        fputc(c + PIANYI, tar);
    }
}

// 偏移解密
void piayi_jian(FILE *src,FILE *tar)
{
    char c;
    while((c=fgetc(src))!=EOF)
    {
        fputc(c - PIANYI, tar);
    }
}

// 替换加密
void tihuan_jia(FILE *src,FILE *tar)
{
    char c;
    while((c=fgetc(src))!=EOF)
    {
        if((unsigned char)c < 128)
            fputc(tihuan_ming[(unsigned char)c], tar);
        else
            fputc(c,tar);
    }
}

// 替换解密
void tihuan_jian(FILE *src,FILE *tar)
{
    char c;
    while((c=fgetc(src))!=EOF)
    {
        if((unsigned char)c < 128)
            fputc(tihuan_mi[(unsigned char)c], tar);
        else
            fputc(c,tar);
    }
}

int main()
{
    FILE *wenjian_src,*wenjian_tar;
    char mingming[100],miming[100];
    int mode;

    init_tihuan();
    printf("====文件加密解密程序====\n");
    printf("1 偏移加密  2 偏移解密\n");
    printf("3 替换加密  4 替换解密\n");
    printf("请输入模式数字：");
    scanf("%d",&mode);
    getchar();

    printf("输入源文件路径：");
    gets(mingming);
    printf("输入输出文件路径：");
    gets(miming);

    wenjian_src = fopen(mingming,"rb");
    if(!wenjian_src)
    {
        printf("打开源文件失败！\n");
        return 1;
    }
    wenjian_tar = fopen(miming,"wb");
    if(!wenjian_tar)
    {
        printf("创建目标文件失败！\n");
        fclose(wenjian_src);
        return 1;
    }

    switch(mode)
    {
        case 1: piayi_jia(wenjian_src,wenjian_tar); break;
        case 2: piayi_jian(wenjian_src,wenjian_tar); break;
        case 3: tihuan_jia(wenjian_src,wenjian_tar); break;
        case 4: tihuan_jian(wenjian_src,wenjian_tar); break;
        default: printf("模式错误！\n");
    }

    fclose(wenjian_src);
    fclose(wenjian_tar);
    printf("操作完成！\n");
    return 0;
}