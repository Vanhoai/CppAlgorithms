#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

int Ckn(int n, int k) {
    int res = 1;
    k = min(k, n - k);
    for (int i = 0; i < k; i++) {
        res *= n - i;
        res /= i + 1;
    }

    return res;
}

int Akn(int n, int k) {
    int res = 1;
    for (int i = 1; i <= k; i++) {
        res *= n - i + 1;
        res /= i;
    }

    return res;
}

int main() {
    SETUP;

    int n, k;
    cin >> n >> k;
    cout << Ckn(n, k) << endl;

    return 0;
}