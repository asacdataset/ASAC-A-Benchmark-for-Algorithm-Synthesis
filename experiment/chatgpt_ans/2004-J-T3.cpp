#include <stdio.h>
#include <string.h>

void post_order(char *s, int length) {
    if (length <= 0) return;
    int mid = length / 2;
    post_order(s, mid);
    post_order(s + mid, length - mid);
    printf("%c", s[mid]);
}

int main() {
    int n;
    scanf("%d", &n);
    char s[20];
    scanf("%s", s);
    post_order(s, 1 << n);
    return 0;
}
