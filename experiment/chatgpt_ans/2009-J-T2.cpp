#include <stdio.h>
#include <stdlib.h>

typedef struct candidate{
    int id;
    int score;
} candidate;

int cmp(const void *a, const void *b) {
    candidate *c1 = (candidate *)a;
    candidate *c2 = (candidate *)b;
    if (c1->score != c2->score) {
        return c2->score - c1->score;
    }
    else {
        return c1->id - c2->id;
    }
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    candidate candidates[n];
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &candidates[i].id, &candidates[i].score);
    }
    qsort(candidates, n, sizeof(candidate), cmp);
    int cutOff = candidates[(int)(m * 1.5) - 1].score;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (candidates[i].score >= cutOff) {
            count++;
        }
    }
    printf("%d %d\n", cutOff, count);
    for (int i = 0; i < n; i++) {
        if (candidates[i].score >= cutOff) {
            printf("%d %d\n", candidates[i].id, candidates[i].score);
        }
    }
    return 0;
}
