#include <stdio.h>
#include <math.h>

double sin_5sig(double x) {
    double sum = 0.0;
    double term = x; // n=0 term: x^1/1!
    int n = 0;
    sum = term;      // initialize sum with first term
    
    // Iterate until term magnitude is small enough for 5 significant digits
    while (fabs(term) > fabs(sum) * 5e-5) {
        n++;
        // Recursively compute next term
        term = term * (-x * x) / ((2*n) * (2*n + 1));
        sum += term;
    }
    return sum;
}

// Test main function
int main() {
    double test_vals[] = {0, M_PI /2, M_PI, M_PI/4, 1.0};
    int len = sizeof(test_vals)/sizeof(test_vals[0]);
    for(int i=0; i<len; i++){
        double x = test_vals[i];
        printf("x = %.4f\n", x);
        printf("Custom sin: %.5g\n", sin_5sig(x));
        printf("Library sin: %.5g\n\n", sin(x));
    }
    return 0;
}