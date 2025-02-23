#include "bits/stdc++.h"
#include "bits/macros.h"
using namespace std;

/**
 * Build difference array
 *
 * input:
 *      1<=N<=10^6
 *      1<=A[i]<=10^9
 *
 * output: print diffrence array
 *
 * @example
 *      input:
 *          5
 *          7 6 9 9 8
 * 
 *      output:
 *          7 -1 3 0 -1
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n; cin >> n;
    int a[n];
    FOR(i, 0, n) cin >> a[i];

    int d[n];
    d[0] = a[0];
    FOR(i, 1, n) d[i] = a[i - 1] - a[i];

    FOR(i, 0, n) cout << d[i] << " ";
    cout << endl;

    return 0;
}












