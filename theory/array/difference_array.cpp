#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

/**
 * Difference Array
 * d[0] = a[0]
 * d[i] = a[i] - a[i - 1] where i >= 1
 *
 * increate L -> R with K unit
 * -> d[L] += K, d[R + 1] -= K
 *
 * 7 3
 * 8 5 8 9 7 6 9
 * 0 5 0
 * 0 5 0
 * 1 5 1
 *
 * 8 6 9 10 8 7 9
 */

int main() {
    SETUP;

    int n, q;
    cin >> n >> q;
    int a[n];
    FOR(i, 0, n) cin >> a[i];

    int d[n + 2];
    ms(d, 0);

    d[0] = a[0];
    FOR(i, 1, n) d[i] = a[i] - a[i - 1];

    FOR(i, 0, q) {
        int L, R, K;
        cin >> L >> R >> K;
        d[L] += K;
        d[R + 1] -= K;
    }

    cout << d[0] << " ";
    FOR(i, 1, n) {
        d[i] = d[i] + d[i - 1];
        cout << d[i] << " ";
    }

    return 0;
}