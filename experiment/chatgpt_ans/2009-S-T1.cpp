#include <stdio.h>
#include <string.h>

int main() {
    char enciphered[101], original[101], newEnciphered[101];
    int secret[26], check[26];
    scanf("%s %s %s", enciphered, original, newEnciphered);
    int len1 = strlen(enciphered);
    int len2 = strlen(original);
    int len3 = strlen(newEnciphered);
    if (len1 != len2) {
        printf("Failed\n");
        return 0;
    }
    memset(secret, 0, sizeof(secret));
    memset(check, 0, sizeof(check));
    for (int i = 0; i < len1; i++) {
        int x = original[i] - 'A', y = enciphered[i] - 'A';
        if (secret[x] && secret[x] != y) {
            printf("Failed\n");
            return 0;
        }
        if (!secret[x]) {
            check[y] = 1;
            secret[x] = y;
        }
    }
    for (int i = 0; i < 26; i++) {
        if (!check[i]) {
            printf("Failed\n");
            return 0;
        }
    }
    for (int i = 0; i < len3; i++) {
        int y = newEnciphered[i] - 'A';
        for (int j = 0; j < 26; j++) {
            if (secret[j] == y) {
                printf("%c", j + 'A');
                break;
            }
        }
    }
    printf("\n");
    return 0;
}
