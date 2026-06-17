#include <stdio.h>

int main() {
    int i = 0;

    while ( i <= 255) {
        
        printf("ASCII值: %3d  |  对应字符: %c\n", i, (char)i);
        i += 1;
    }
    return 0;
}
