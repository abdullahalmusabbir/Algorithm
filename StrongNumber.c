#include <stdio.h>

int main() {
    int num, originalNum, sum = 0, digit, factorial;

    printf("Enter a positive integer: ");
    scanf("%d", &num);

    originalNum = num;

    while (num > 0) {
        digit = num % 10;
        factorial = 1;

        for (int i = 1; i <= digit; ++i) {
            factorial *= i;
        }

        sum += factorial;
        num /= 10;
    }

    if (sum == originalNum) {
        printf("%d is a Strong number.\n", originalNum);
    } else {
        printf("%d is not a Strong number.\n", originalNum);
    }

    return 0;
}

