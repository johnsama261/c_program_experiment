#include <stdio.h>

int main() {
    printf("y\t\tx\t\ti\n");

   
    for (int y = 1; y <= 6; y++) {
        for (int k = 11; k <= 25; k++) {
            double x = k * 0.5;
            double i = 2 + (y + 0.5 * x);
            printf("%d\t\t%.1f\t\t%.2f\n", y, x, i);
        }
    }

    return 0;
}