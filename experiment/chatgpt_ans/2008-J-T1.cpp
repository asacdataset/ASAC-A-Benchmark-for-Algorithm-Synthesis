#include <stdio.h>
#include <string.h>

int main() {
    char ISBN[20];
    scanf("%s", ISBN);

    int sum = 0;
    for (int i = 0; i < 9; i++) {
        sum += (ISBN[i] - '0') * (i + 1);
    }
    int id = sum % 11;

    if (id == 10) {
        if (ISBN[9] == 'X') {
            printf("Right\n");
        } else {
            ISBN[9] = 'X';
            printf("%s\n", ISBN);
        }
    } else {
        if (ISBN[9] - '0' == id) {
            printf("Right\n");
        } else {
            ISBN[9] = id + '0';
            printf("%s\n", ISBN);
        }
    }

    return 0;
}
