#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

/**
 * Statistical Number
 *
 * input:
 *      T, N, X, A(i)
 *      1 ≤ T ≤ 10
 *      1 ≤ X, A(i) ≤ 100
 *      N ≤ 20
 *
 * output: print all way statistical number (partition)
 *
 * @example
 *      input:
 *          1
 *          4 8
 *          2 4 6 8
 *      output:
 *          [2 2 2 2] [2 2 4] [2 6] [4 4] [8]
 */

int n, s, ok, X[100], A[100];

void input() {
    cin >> n >> s;
    REP(i, 1, n) cin >> A[i];
    sort(A + 1, A + n + 1);
}

void backtracking(int i, int pos, int sum) {
    if (sum == s) {
        cout << "[";
        for (int k = 1; k < i; k++) {
            cout << X[k];
            if (k == i - 1)
                cout << "]";
            else
                cout << " ";
        }

        cout << " ";
        ok = 1;
        return;
    }

    for (int k = pos; k <= n; k++) {
        if (sum + A[k] <= s) {
            X[i] = A[k];
            backtracking(i + 1, k, sum + A[k]);
        }
    }
}

int main() {
    SETUP;

    int TC;
    cin >> TC;
    while (TC--) {
        input();
        ok = 0;
        backtracking(1, 1, 0);
        if (!ok)
            cout << "-1\n";
    }

    return 0;
}