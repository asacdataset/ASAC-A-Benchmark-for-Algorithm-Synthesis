#include <iostream>
#include <string>
using namespace std;

string encrypt(string plaintext, string key) {
    string ciphertext = "";
    for (int i = 0, j = 0; i < plaintext.length(); i++) {
        char p = plaintext[i];
        if (isalpha(p)) {
            ciphertext += (p + key[j] - 2 * 'A') % 26 + 'A';
            j = (j + 1) % key.length();
        } else {
            ciphertext += p;
        }
    }
    return ciphertext;
}

string decrypt(string ciphertext, string key) {
    string plaintext = "";
    for (int i = 0, j = 0; i < ciphertext.length(); i++) {
        char c = ciphertext[i];
        if (isalpha(c)) {
            plaintext += (c - key[j] + 26) % 26 + 'A';
            j = (j + 1) % key.length();
        } else {
            plaintext += c;
        }
    }
    return plaintext;
}

int main() {
    string key, ciphertext;
    cin >> key >> ciphertext;
    cout << decrypt(ciphertext, key) << endl;
    return 0;
}