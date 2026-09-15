#include <iostream>

using namespace std;

char upper(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 'a' + 'A';
    }
    return c;
}

void enkripsi(const char src[], char res[]) {
    int len = 0;
    while (src[len] != '\0') len++;

    if (len == 0) {
        res[0] = '\0';
        return;
    }

    res[0] = upper(src[0]);

    for (int i = 1; i < len; i++) {
        int curr = upper(src[i]) - 'A' + 1;
        int prev = upper(src[i - 1]) - 'A' + 1;

        int val = curr + prev;
        if (val > 26) {
            val -= 26;
        }

        res[i] = (char)('A' + val - 1);
    }
    res[len] = '\0';
}

void dekripsi(const char src[], char res[]) {
    int len = 0;
    while (src[len] != '\0') len++;

    if (len == 0) {
        res[0] = '\0';
        return;
    }

    res[0] = upper(src[0]);

    for (int i = 1; i < len; i++) {
        int curr = upper(src[i]) - 'A' + 1;
        int prev = res[i - 1] - 'A' + 1;

        int val = curr - prev;
        if (val <= 0) {
            val += 26;
        }

        res[i] = (char)('A' + val - 1);
    }
    res[len] = '\0';
}

int main() {
    char in[] = "ALIENS";
    char enc[100];
    char dec[100];

    enkripsi(in, enc);
    cout << "Pesan asli     : " << in << endl;
    cout << "hasil enkripsi : " << enc << endl;

    dekripsi(enc, dec);
    cout << "Hasil dekripsi : " << dec << endl;

    return 0;
}