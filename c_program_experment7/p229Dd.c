#include <stdio.h>
#include <string.h>

int main()
{
    char input[100], output[500];
    int i = 0, j = 0;
    char ch;
    int num, k;

    printf("请输入带括号格式字符串，如1(2)4：");
    scanf("%s", input);

    while (input[i] != '\0')
    {
        // 普通数字/字符，直接存入结果
        if (input[i] != '(')
        {
            ch = input[i];
            i++;
            // 遇到左括号，读取重复次数
            if (input[i] == '(')
            {
                i++;
                num = input[i] - '0'; // 提取括号内数字
                i += 2; // 跳过数字和右括号 )
                // 重复ch num次写入输出
                for (k = 0; k < num; k++)
                {
                    output[j++] = ch;
                }
            }
            else
            {
                // 无括号，单次存入
                output[j++] = ch;
            }
        }
    }
    output[j] = '\0'; // 字符串结束标记

    printf("转换后结果：%s\n", output);
    return 0;
}