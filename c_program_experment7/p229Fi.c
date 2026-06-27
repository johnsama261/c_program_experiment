#include <stdio.h>
#include <string.h>
#include <ctype.h>

void abbreviateName(char *fullName) {
    char tokens[50][20];
    int tokenCount = 0;
    char *ptr = strtok(fullName, " ");
    while (ptr != NULL) {
        strcpy(tokens[tokenCount++], ptr);
        ptr = strtok(NULL, " ");
    }
    for (int i = 0; i < tokenCount - 1; i++) {
        putchar(toupper(tokens[i][0]));
        printf(". ");
    }
    printf("%s\n", tokens[tokenCount - 1]);
}

int main() {
    char nameLine[200];
    printf("连续输入人名，输入quit结束程序\n");
    while (1) {
        printf("人名：");
        fgets(nameLine, sizeof(nameLine), stdin);
        nameLine[strcspn(nameLine, "\n")] = '\0';
        if (strcmp(nameLine, "quit") == 0) break;
        printf("缩写：");
        abbreviateName(nameLine);
    }
    return 0;
}