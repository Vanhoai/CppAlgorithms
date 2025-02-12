#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

/**
 *  Merge two array
 *
 * input:
 *      T, N, M, A[i]
 *      1 ≤ T ≤ 100
 *      1 ≤ n, m ≤ 10^6
 *      -10^9 ≤ A[i], B[i] ≤ 10^9
 *
 * output: print array after merge
 *
 * @example
 *      input:
 *          1
 *          3 4
 *          1 2 3
 *          1 5 6 2
 *      output:
 *          1 1 2 2 3 5 6
 */

int main() {
    SETUP;

    int TC;
    cin >> TC;
    while (TC--) {
        int n, m;
        cin >> n >> m;
        ll a[n], b[m];

        FOR(i, 0, n) cin >> a[i];
        FOR(i, 0, m) cin >> b[i];

        sort(a, a + n);
        sort(b, b + m);

        ll res[n + m];
        int k = 0;

        int i = 0, j = 0;
        while (i < n && j < m) {
            if (a[i] <= b[j])
                res[k++] = a[i++];
            else
                res[k++] = b[j++];
        }

        while (i < n)
            res[k++] = a[i++];

        while (j < m)
            res[k++] = b[j++];

        FOR(e, 0, k) cout << res[e] << " ";
        cout << endl;
    }

    return 0;
}