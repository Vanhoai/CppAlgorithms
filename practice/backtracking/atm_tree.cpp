#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

/**
 * ATM Tree
 *
 * input:
 *      T, N, S, A(i)
 *      1 <= N <= 30
 *      S ≤ 10^9
 *      A(i) <= 10^9
 *
 * output: print minimum paper of money
 *
 * @example
 *      input:
 *          1
 *          3 5
 *          1 4 5
 *      output:
 *          1 (1 - 5)
 */

int n, s, k, ok;
ll A[100], X[100];

void in() {
    cin >> n >> s;
    REP(i, 1, n) cin >> A[i];
    sort(A + 1, A + n + 1, greater<ll>());
}

void backtracking(int i) {
    if (ok)
        return;

    for (int j = X[i - 1] + 1; j <= n - k + i; j++) {
        X[i] = j;
        if (i == k) {
            int sum = 0;
            for (int j = 1; j <= k; j++)
                sum += A[X[j]];

            if (sum == s) {
                ok = 1;
            }
        } else
            backtracking(i + 1);
    }
}

int main() {
    SETUP;

    int TC;
    cin >> TC;
    while (TC--) {
        in();

        ok = 0;
        for (int i = 1; i <= n; i++) {
            k = i;
            backtracking(1);
            if (ok) {
                cout << k << endl;
                break;
            }
        }

        if (!ok)
            cout << -1 << endl;
    }

    return 0;
}