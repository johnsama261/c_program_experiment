#include <stdio.h>
int main() {
    for(int i=0;i<7;puts(" "),i++)
        for(int j=0;j<13;j++)
            putchar(j<7-i ? 'A'+j : j>6+i ? 'A'+12-j : ' ');
    return 0;
}