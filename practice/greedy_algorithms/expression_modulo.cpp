#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

/**
 * Expression Modulo
 *
 * input:
 *      T, N, A[i]
 *      1 ≤ T ≤ 100
 *      1 ≤ N, A[i] ≤ 10^7
 *
 * output: print max after sorted array and calculate
 *
 *          max = A[i] * i (i: 0 -> n - 1)
 *
 * @example
 *      input:
 *          2
 *          5
 *          5 3 2 4 1
 *          3
 *          1 2 3
 *      output:
 *          40
 *          8
 */

int main() {
    SETUP;

    int TC;
    cin >> TC;
    while (TC--) {
        int n;
        cin >> n;
        ll a[n];
        FOR(i, 0, n) cin >> a[i];
        sort(a, a + n);

        ll res = 0;
        for (int i = 0; i < n; i++) {
            res += a[i] * i;
            res %= MOD;
        }

        cout << res << endl;
    }

    return 0;
}
