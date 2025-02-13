#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

/**
 * Min Expression Multiply
 *
 * input:
 *      T, N, A[i]
 *      1 ≤ T ≤ 100
 *      1 ≤ N ≤ 10^7
 *      0 ≤ A[i], B[i] ≤ 10^18
 *
 * output: print min expression
 *
 *      P(min) = A[i] * B[i] (i: 0 -> n - 1)
 *
 * @example
 *      input:
 *          2
 *          7
 *          1 6 3 4 5 2 7
 *          1 1 1 2 3 4 3
 *          7
 *          1 6 3 5 5 2 2
 *          0 1 9 0 1 2 3
 *      output:
 *          45
 *          27
 */

int main() {
    SETUP;

    int TC;
    cin >> TC;
    while (TC--) {
        int n;
        cin >> n;
        ll a[n], b[n];

        FOR(i, 0, n) cin >> a[i];
        FOR(i, 0, n) cin >> b[i];

        sort(a, a + n);
        sort(b, b + n, greater<int>());

        ll res = 0;
        FOR(i, 0, n) res += a[i] * b[i];

        cout << res << endl;
    }

    return 0;
}
