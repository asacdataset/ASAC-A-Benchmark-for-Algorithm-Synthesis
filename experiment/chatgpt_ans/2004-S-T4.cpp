#include <stdio.h>
#include <string.h>

int n, ans[26], used[26];
char a[4][3010];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= 3; i++) {
        scanf("%s", a[i]);
    }

    for (int i = 0; i < n; i++) {
        int x = a[1][i] - 'A', y = a[2][i] - 'A', z = a[3][i] - 'A';
        if (!ans[x]) {
            ans[x] = i;
            used[i] = 1;
        }
        if (!ans[y]) {
            ans[y] = i + 1;
            used[i + 1] = 1;
        }
        if (!ans[z]) {
            ans[z] = i + 2;
            used[i + 2] = 1;
        }
    }

    for (int i = 0; i < 26; i++) {
        if (!used[i]) {
            for (int j = 0; j < 26; j++) {
                if (!ans[j]) {
                    ans[j] = i;
                    break;
                }
            }
        }
    }

    for (int i = 0; i < 26; i++) {
        printf("%d ", ans[i]);
    }

    return 0;
}
