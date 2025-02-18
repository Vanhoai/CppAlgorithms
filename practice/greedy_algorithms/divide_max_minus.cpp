#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

/**
 * Divide Two Subset Max Minus
 *
 * input:
 *      T, N, A[i]
 *      1 ≤ T ≤ 100
 *      1 ≤ K < N ≤ 50
 *      0 ≤ A[i] ≤ 1000
 *
 * output: print maximum minus 2 subset (k elements) - (n -k elements)
 *
 * @example
 *      input:
 *          2
 *          5 2
 *          8 4 5 2 10
 *          8 3
 *          1 1 1 1 1 1 1 1
 *      output:
 *          17
 *          2
 */

int main() {
    SETUP;

    int TC;
    cin >> TC;
    while (TC--) {
        int n, k;
        cin >> n >> k;
        int a[n];
        FOR(i, 0, n) cin >> a[i];
        sort(a, a + n, greater<int>());

        int mn = n - k;
        if (mn > k)
            swap(mn, k);

        // make sure k > mn
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (i < k)
                res += a[i];
            else
                res -= a[i];
        }

        cout << res << endl;
    }

    return 0;
}
