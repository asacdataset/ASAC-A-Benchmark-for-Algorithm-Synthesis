#include <stdio.h>
#include <stdlib.h>

struct student {
    int num;
    int chinese;
    int math;
    int english;
    int total;
} students[305];

int compare(const void *a, const void *b) {
    struct student *sa = (struct student *)a;
    struct student *sb = (struct student *)b;

    if (sa->total != sb->total) {
        return sb->total - sa->total;
    } else if (sa->chinese != sb->chinese) {
        return sb->chinese - sa->chinese;
    } else {
        return sa->num - sb->num;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &students[i].chinese, &students[i].math, &students[i].english);
        students[i].num = i + 1;
        students[i].total = students[i].chinese + students[i].math + students[i].english;
    }

    qsort(students, n, sizeof(struct student), compare);

    for (int i = 0; i < 5; i++) {
        printf("%d %d\n", students[i].num, students[i].total);
    }

    return 0;
}
