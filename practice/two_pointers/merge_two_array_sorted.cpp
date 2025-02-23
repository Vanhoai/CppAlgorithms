#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

/**
 * Merge two array sorted
 *
 * input:
 *      1<=N,M<=10^7
 *      1<=A[i],B[i]<= 10^9
 *
 * output: print array after merged
 *
 * @example
 *      input:
 *          6 6
 *          1 2 4 4 9 10
 *          4 4 5 6 6 8
 *
 *      output:
 *          1 2 4 4 4 4 5 6 6 8 9 10
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m; cin >> n >> m;
    int a[n], b[m];

    FOR(i, 0, n) cin >> a[i];
    FOR(i, 0, m) cin >> b[i];

    int i = 0, j = 0, k = 0;
    int f[n + m];
    while (i < n && j < m) {
        if (a[i] <= b[i])
            f[k++] = a[i++];
        else
            f[k++] = b[j++]; 
    }

    while (i < n) f[k++] = a[i++];
    while (j < m) f[k++] = b[j++];

    FOR(i, 0, n + m) cout << f[i] << " ";
    cout << endl;

    return 0;
}









