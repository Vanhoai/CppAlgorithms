#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

/**
 * Rotate Symmetric Subarray
 *
 * input:
 *      T, N, A[i]
 *      1 ≤ T ≤ 100
 *      1 ≤ N ≤ 50
 *      0 ≤ A[i] ≤ 1000
 *
 * output: YES/NO
 *
 * @example
 *      input:
 *          2
 *          7
 *          1 6 3 4 5 2 7
 *          7
 *          1 6 3 4 5 7 2
 *      output:
 *          YES (1 6 3 4 5 2 7) -> (1 6 5 4 3 2 7) -> (1 2 3 4 5 6 7)
 *          NO
 */

int main() {
    SETUP;

    int TC;
    cin >> TC;
    while (TC--) {
        int n;
        cin >> n;
        int a[n];
        FOR(i, 0, n) cin >> a[i];

        vector<int> b(a, a + n);
        sort(b.begin(), b.end());

        bool ok = true;
        FOR(i, 0, n) {
            if (a[i] != b[i] && b[i] != a[n - i - 1]) {
                ok = false;
                break;
            }
        }

        cout << (ok ? "YES" : "NO") << endl;
    }

    return 0;
}
