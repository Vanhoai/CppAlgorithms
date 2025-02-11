#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

/**
 * N Queen
 *
 * input:
 *      T: number testcase T < 5
 *      N: number of queen N < 12
 *
 * output: Number of ways to set up the queen
 *
 * @example
 *      input:
 *          1
 *          4
 *      output:
 *          2
 */

const int maxn = 100;
int n, ans, X[maxn], column[maxn], d1[maxn], d2[maxn];

void backtracking(int i) {
    for (int k = 1; k <= n; k++) {
        if (column[k] && d1[i - k + n] && d2[i + k - 1]) {
            X[i] = k;
            column[k] = d1[i - k + n] = d2[i + k - 1] = 0;

            if (i == n)
                ans++;
            else
                backtracking(i + 1);

            column[k] = d1[i - k + n] = d2[i + k - 1] = 1;
        }
    }
}

int main() {
    SETUP;

    int TC;
    cin >> TC;
    while (TC--) {
        cin >> n;
        ans = 0;

        memset(column, 1, sizeof(column));
        memset(d1, 1, sizeof(d1));
        memset(d2, 1, sizeof(d2));

        backtracking(1);
        cout << ans << endl;
    }

    return 0;
}