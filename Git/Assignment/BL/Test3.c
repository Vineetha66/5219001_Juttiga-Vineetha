#include <stdio.h>

int main() {
    int num1, num2, sum;

    // Ask user for input
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    // Calculate sum
    sum = num1 + num2;

    // Display result
    printf("Sum = %d\n", sum);

    return 0;
}
