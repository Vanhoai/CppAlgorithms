#include "bits/stdc++.h"
using namespace std;

/**
 * Static Sum Query
 *
 * input:
 *      1<=N,Q<=10^6
 *      1<=A[i]<=10^9
 *      0<=L<=R<=N-1
 *
 * output: print sum of query from L to R
 *
 * @example
 *      input:
 *          11 3
 *          6 5 9 7 7 6 7 7 5 9 7
 *          1 9
 *          1 10
 *          0 8
 *      output:
 *          62
 *          69
 *          59
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, q; cin >> n >> q;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    int f[n];
    f[0] = a[0];
    for (int i = 1; i < n; i++)
        f[i] = f[i - 1] + a[i];

    while (q--) {
        int L, R; cin >> L >> R;
        if (L == 0) cout << f[R] << endl;
        else cout << f[R] - f[L - 1] << endl;
    }

    return 0;
}















