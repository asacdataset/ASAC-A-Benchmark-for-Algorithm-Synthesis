#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char word[11];
    scanf("%s", word);
    for (int i = 0; i < strlen(word); i++) {
        word[i] = tolower(word[i]);
    }

    char article[1000001];
    scanf(" %[^\n]s", article);
    for (int i = 0; i < strlen(article); i++) {
        article[i] = tolower(article[i]);
    }

    int count = 0;
    int first_occurrence = -1;
    int j = 0;
    for (int i = 0; i < strlen(article); i++) {
        if (article[i] == word[j]) {
            j++;
            if (j == strlen(word)) {
                count++;
                if (first_occurrence == -1) {
                    first_occurrence = i - j + 1;
                }
                j = 0;
            }
        } else {
            j = 0;
        }
    }

    if (count == 0) {
        printf("-1");
    } else {
        printf("%d %d", count, first_occurrence);
    }

    return 0;
}