#include <iostream>

using namespace std;

int updateK(int k, int val) {
    if (val % 2 == 0) {
        k += 2;
    } else {
        k -= 1;
    }
    
    if (k < 2) {
        k = 2;
    }
    
    return k;
}

void hapus(int arr[], int &len, int idx) {
    for (int i = idx; i < len - 1; i++) {
        arr[i] = arr[i + 1];
    }
    len--;
}

int main() {
    int n, k;

    cout << "Masukan N: ";
    cin >> n;

    cout << "Masukan K: ";
    cin >> k;

    if (n <= 0) return 0;
    if (k < 2) k = 2;

    int a[1000];
    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
    }

    int len = n;
    int pos = 0;

    cout << "\nUrutan eliminasi:\n";

    while (len > 1) {
        int target = (pos + k - 1) % len;
        int out = a[target];

        cout << "Astronot " << out << " dieliminasi (K: " << k << ")\n";

        hapus(a, len, target);
        k = updateK(k, out);
        pos = target;
    }

    cout << "\nAstronot terakhir: Astronot " << a[0] << endl;

    return 0;
}