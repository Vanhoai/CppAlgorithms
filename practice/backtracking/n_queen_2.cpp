#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

const int maxn = 100;
int n, res, X[maxn], A[maxn][maxn], c[maxn], d1[maxn], d2[maxn];

void init() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cin >> A[i][j];
    }

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

            if (i == n) {
                int sum = 0;
                for (int b = 1; b <= n; b++) {
                    sum += A[b][X[b]];
                }

                res = max(res, sum);
            }

            backtracking(i + 1);
            c[j] = 0;
            d1[i - j + n] = 0;
            d2[i + j - 1] = 0;
        }
    }
}

int main() {
    SETUP;

    n = 8;
    int TC;
    cin >> TC;
    while (TC--) {
        init();

        res = -1e9;
        backtracking(1);
        cout << res << endl;
    }

    return 0;
}