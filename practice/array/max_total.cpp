#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

/**
 * Max Total
 *
 * input:
 *      N, Q, L, R, A[i]
 *      1<=N<=10^6
 *      1<=Q<=10^5
 *      0<=L<=R<=N-1
 *      0<=A[i],K<=1000
 *
 * output: print max total sum in L, R in all Q query
 *
 * @example
 *      input:
 *          6 2
 *          5 2 5 3 5 1
 *          2 5
 *          2 4
 *      output:
 *          33
 */

int main() {
    SETUP;

    int n, q;
    cin >> n >> q;
    int a[n];
    FOR(i, 0, n) cin >> a[i];

    int d[n + 5];
    ms(d, 0);

    while (q--) {
        int L, R;
        cin >> L >> R;

        L--;
        R--;

        d[L] += 1;
        d[R + 1] -= 1;
    }

    int F[n];
    F[0] = d[0];
    FOR(i, 1, n) F[i] = F[i - 1] + d[i];

    sort(F, F + n, greater<int>());
    sort(a, a + n, greater<int>());

    ll res = 0;
    FOR(i, 0, n) res += 1LL * a[i] * F[i];
    cout << res << endl;

    return 0;
}