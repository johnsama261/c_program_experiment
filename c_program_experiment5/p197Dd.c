#include <stdio.h>

int main() {
    int arr[25];
    int positive = 0, negative = 0;
    int even = 0, odd = 0;
    int i;

    // 输入25个数字
    printf("请输入25个整数\n");
    for (i = 0; i < 25; i++) {
        scanf("%d", &arr[i]);
    }

    // 遍历统计
    for (i = 0; i < 25; i++) {
        int num = arr[i];
        // 正负判断
        if (num > 0)
            positive++;
        else if (num < 0)
            negative++;
        
        // 奇偶判断
        if (num % 2 == 0)
            even++;
        else
            odd++;
    }

    // 输出结果
    printf("正数数量：%d\n", positive);
    printf("负数数量：%d\n", negative);
    printf("偶数数量：%d\n", even);
    printf("奇数数量：%d\n", odd);

    return 0;
}