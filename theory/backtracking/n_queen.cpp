#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

const int maxn = 100;
int n, res, X[maxn], c[maxn], d1[maxn], d2[maxn];

void init() {
    memset(c, 0, sizeof(c));
    memset(d1, 0, sizeof(d1));
    memset(d2, 0, sizeof(d2));
}

void backtracking(int i) {
    for (int j = 1; j <= n; j++) {
        if (c[j] == 0 && d1[i - j + n] == 0 && d2[i + j - 1] == 0) {
            X[i] = j;
            c[j] = 1;
            d1[i - j + n] = 1;
            d2[i + j - 1] = 1;

            if (i == n)
                res++;

            backtracking(i + 1);
            c[j] = 0;
            d1[i - j + n] = 0;
            d2[i + j - 1] = 0;
        }
    }
}

int main() {
    SETUP;

    cin >> n;
    res = 0;
    backtracking(1);
    cout << res << endl;

    return 0;
}