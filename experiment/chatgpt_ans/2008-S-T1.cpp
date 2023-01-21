#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool is_prime(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= n / i; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    char s[101];
    scanf("%s", s);
    int freq[26] = {0};
    int maxn = 0, minn = 100;
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        freq[s[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        if (freq[i] > maxn) maxn = freq[i];
        if (freq[i] < minn && freq[i] > 0) minn = freq[i];
    }
    int diff = maxn - minn;
    if (is_prime(diff)) {
        printf("Lucky Word\n%d", diff);
    } else {
        printf("No Answer\n0");
    }
    return 0;
}
