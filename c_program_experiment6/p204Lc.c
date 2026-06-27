#include <stdio.h>
int main() {
    int mat[4][4], trans[4][4];
    int i, j;

    // 输入4×4原矩阵
    printf("Enter 4x4 matrix elements row-wise:\n");
    for(i = 0; i < 4; i++) {
        for(j = 0; j < 4; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    // 计算转置：mat[i][j] → trans[j][i]
    for(i = 0; i < 4; i++) {
        for(j = 0; j < 4; j++) {
            trans[j][i] = mat[i][j];
        }
    }

    // 输出转置矩阵
    printf("\nTransposed 4x4 matrix:\n");
    for(i = 0; i < 4; i++) {
        for(j = 0; j < 4; j++) {
            printf("%d ", trans[i][j]);
        }
        printf("\n");
    }
    return 0;
}