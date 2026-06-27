#include <stdio.h>

int main() {
    int matrix[5][5];
    int i, j, max;

    // 输入5行5列矩阵元素
    printf("请输入5行5列矩阵的25个整数\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // 初始化最大值为第一个元素
    max = matrix[0][0];

    // 遍历整个矩阵找最大值
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (matrix[i][j] > max) {
                max = matrix[i][j];
            }
        }
    }

    // 输出结果
    printf("矩阵中最大的数字是：%d\n", max);
    return 0;
}