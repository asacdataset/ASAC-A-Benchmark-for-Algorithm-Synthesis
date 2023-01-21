#include <stdio.h>
#include <string.h>

const int N = 25;
char s[N];
int main() {
    int a, b, n, cnt = 0;
    scanf("%d%d%d", &a, &b, &n);
    scanf("%s", s);
    while (cnt < 5) {
        int i = n - 1;
        while (i >= 0 && s[i] == b + 'a' - 1 - (n - i - 1)) i--;
        if (i < 0) break;
        s[i]++;
        for (int j = i + 1; j < n; j++) s[j] = s[i] + j - i;
        cnt++;
        printf("%s\n", s);
    }
    return 0;
}
