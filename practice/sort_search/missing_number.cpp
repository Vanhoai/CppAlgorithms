#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

/**
 *  Missing Number
 *
 * input:
 *      T, N, A[i]
 *      1 ≤ T ≤ 100
 *      1 ≤ n, A[i] ≤ 10^6
.
 *
 * output: print missing number
 *
 * @example
 *      input:
 *          2
 *          5
 *          4 5 3 8 6
 *          3
 *          2 1 3
 *      output:
 *          7
 *          0
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
        sort(a, a + n);

        int ok = 0;
        FOR(i, 0, n - 1) {
            int dif = a[i + 1] - a[i];
            if (dif > 1) {
                ok = 1;
                if (dif == 2)
                    cout << a[i] + 1;
                else {
                    FOR(k, 0, dif) cout << a[i] + k + 1 << " ";
                }
            }
        }

        if (!ok)
            cout << a[0] - 1;
        cout << endl;
    }

    return 0;
}