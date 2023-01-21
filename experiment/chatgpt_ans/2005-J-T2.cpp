#include <stdio.h>

int main() {
    int l, m, u, v, trees_removed = 0;
    scanf("%d%d", &l, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &u, &v);
        trees_removed += (v - u + 1); // +1 because endpoints are included
    }
    printf("%d", l + 1 - trees_removed); // +1 because 0 is included
    return 0;
}
