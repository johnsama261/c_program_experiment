#include <stdio.h>
#include <string.h>
#include <ctype.h>

// 判断是否为元音字母，是返回1，否返回0
int isVowel(char c)
{
    c = tolower(c); // 统一转小写判断，兼容大写元音
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        return 1;
    return 0;
}

int main()
{
    char input[200], output[200];
    int i = 0, j = 0;

    printf("请输入一行文本：");
    fgets(input, sizeof(input), stdin);

    // 遍历整行字符串
    while(input[i] != '\0')
    {
        // 不是元音才存入结果数组
        if(!isVowel(input[i]))
        {
            output[j++] = input[i];
        }
        i++;
    }
    output[j] = '\0'; // 字符串结束标记

    printf("删除所有元音后的文本：%s", output);
    return 0;
}