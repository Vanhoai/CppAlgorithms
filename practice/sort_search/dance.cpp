#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

/**
 * Dance
 *
 * input:
 *      T, N, M, A(i)
 *      1 ≤ T ≤ 100
 *      1 ≤ N, M ≤ 10^5
 *
 * output: print maximum pair dancer
 *
 * @example
 *      input:
 *          2
 *          3 2
 *          3 2 1
 *          2 3
 *          3 3
 *          4 3 4
 *          2 2 1
 *      output:
 *          1
 *          3
 */

int main() {
    SETUP;

    int TC;
    cin >> TC;
    while (TC--) {
        int n, m;
        cin >> n >> m;
        int a[n], b[m];
        FOR(i, 0, n) cin >> a[i];
        FOR(i, 0, m) cin >> b[i];

        sort(a, a + n);
        sort(b, b + m);

        int i = 0, j = 0, ans = 0;
        while (i < n && j < m) {
            if (a[i] > b[j]) {
                i++;
                j++;
                ans++;
            } else
                i++;
        }

        cout << ans << endl;
    }

    return 0;
}