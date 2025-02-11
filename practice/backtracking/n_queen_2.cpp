#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

/**
 * N Queen
 *
 * input:
 *      T: number testcase T < 5
 *      N = 8
 *      0 ≤ A[i][j] ≤ 100
 *
 * output: print the sum of way set up n queen in chessboard
 *
 * @example
 *      input:
 *          1
 *          1 2 3 4 5 6 7 8
 *          9 10 11 12 13 14 15 16
 *          17 18 19 20 21 22 23 24
 *          25 26 27 28 29 30 31 32
 *          33 34 35 36 37 38 39 40
 *          41 42 43 44 45 46 47 48
 *          48 50 51 52 53 54 55 56
 *          57 58 59 60 61 62 63 64
 *      output:
 *          260
 */

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