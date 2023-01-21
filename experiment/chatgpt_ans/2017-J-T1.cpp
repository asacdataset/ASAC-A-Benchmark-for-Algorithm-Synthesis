#include <stdio.h>

int main() {
    int A, B, C;
    scanf("%d%d%d", &A, &B, &C);

    int grade = (A * 0.2) + (B * 0.3) + (C * 0.5);

    printf("%d\n", grade);
    return 0;
}
