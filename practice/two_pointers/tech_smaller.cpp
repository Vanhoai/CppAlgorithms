#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

/**
 * Tech Smaller
 *
 * input:
 *      1<=N,M<=10^7
 *      1<=A[i],B[i]<= 10^9
 *
 * output: print array with f[i] is the number of element less than b[i]
 *
 * @example
 *      input:
 *          6 7
 *          2 3 6 6 6 8
 *          5 5 5 6 6 7 10
 *
 *      output:
 *          2 2 2 2 2 5 6
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
    while (i < n && j < m) {
        if (a[i] < b[j]) {
            k++;
            i++;
        } else {
            cout << k << " ";
            j++;
        }
    }

    while (j < m) {
        cout << k << " ";
        j++;
    }
    
    return 0;
}









