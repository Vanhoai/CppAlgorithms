#include "bits/stdc++.h"
#include "bits/macros.h"
using namespace std;

/**
 * Update operation in difference array
 *
 * input:
 *      1<=N<=10^6
 *      1<=Q<= 10^5
 *      0<=L<=R<=N-1, 0<=A[i],K<=1000
 *
 * output: print array after q update
 *
 * @example
 *      input:
 *          7 3
 *          8 5 8 9 7 6 9
 *          0 5 0
 *          0 5 0
 *          1 5 1
 * 
 *      output:
 *          8 6 9 10 8 7 9
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, q; cin >> n >> q;
    int a[n];
    FOR(i, 0, n) cin >> a[i];

    int d[n];
    d[0] = a[0];
    FOR(i, 1, n) d[i] = a[i] - a[i - 1];

    while (q--) {
        int l, r, v;
        cin >> l >> r >> v;
        a[l] += v;
        a[r + 1] -= v;
    }

    FOR(i, 1, n) d[i] = d[i] + d[i - 1];
    FOR(i, 0, n) cout << d[i] << " ";
    cout << endl;

    return 0;
}
