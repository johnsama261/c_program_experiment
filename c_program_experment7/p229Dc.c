#include <stdio.h>
#include <string.h>

int main() {
    char str[100], sub[100];
    int pos, n, i, idx = 0;

    // 输入原字符串
    printf("Enter the original string: ");
    gets(str); // 简单场景可用，安全场景可改用fgets

    // 输入起始位置、提取字符数
    printf("Enter starting position (1-based): ");
    scanf("%d", &pos);
    printf("Enter number of characters to extract (0 for rest of string): ");
    scanf("%d", &n);

    int start = pos - 1; // 转为C语言0起始下标
    int len = strlen(str);

    // 确定实际要截取的长度：n=0则取到末尾
    int extract_len;
    if (n == 0) {
        extract_len = len - start;
    } else {
        extract_len = n;
    }

    // 边界防护：防止越界
    if (start < 0 || start >= len) {
        printf("Invalid starting position!\n");
        return 1;
    }
    if (start + extract_len > len) {
        extract_len = len - start;
    }

    // 逐个拷贝子串
    for (i = start; i < start + extract_len; i++) {
        sub[idx++] = str[i];
    }
    sub[idx] = '\0'; // 字符串结束符

    printf("Extracted substring: %s\n", sub);
    return 0;
}