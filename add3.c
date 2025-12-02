#include <stdio.h>

int main() {
    int a, b, c, sum;
    printf("Enter three numbers separated by spaces: ");
    scanf("%d %d %d", &a, &b, &c);
    sum = a + b + c;
    printf("Sum of the three numbers: %d\n", sum);

    return 0;
}