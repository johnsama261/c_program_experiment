#include <stdio.h>

// 定义日期结构体
struct Date {
    int day;
    int month;
    int year;
};

int main() {
    struct Date d1, d2;

    // 输入第一个日期
    printf("Enter first date (day month year): ");
    scanf("%d %d %d", &d1.day, &d1.month, &d1.year);

    // 输入第二个日期
    printf("Enter second date (day month year): ");
    scanf("%d %d %d", &d2.day, &d2.month, &d2.year);

    // 对比年月日全部是否相等
    if (d1.day == d2.day && d1.month == d2.month && d1.year == d2.year) {
        printf("Equal\n");
    } else {
        printf("Unequal\n");
    }

    return 0;
}