#include <stdio.h>

int reverse_digits(int num) {
    int reversed = 0;
    while (num != 0) {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }
    return reversed;
}

int main() {
    int num;
    scanf("%d", &num);

    int reversed = reverse_digits(num);
    printf("%d", reversed);

    return 0;
}