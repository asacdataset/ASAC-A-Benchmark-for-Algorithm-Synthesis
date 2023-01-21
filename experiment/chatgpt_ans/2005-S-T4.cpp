#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int N = 55;
char s[N], t[N];
int n, ans[N];

bool check() {
    // Compare the expressions
}

int main() {
    scanf("%s", s);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", t);
        if (check(s, t)) ans[i] = 1;
    }
    for (int i = 0; i < n; i++)
        if (ans[i]) printf("%c", i + 'A');
    printf("\n");
    return 0;
}
