#include <stdio.h>

int main() {
    int apple[10], taotao, count = 0;
    for (int i = 0; i < 10; i++) {
        scanf("%d", &apple[i]);
    }
    scanf("%d", &taotao);
    for (int i = 0; i < 10; i++) {
        if (apple[i] <= taotao || apple[i] <= taotao + 30) {
            count++;
        }
    }
    printf("%d", count);
    return 0;
}
