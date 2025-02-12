#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

/**
 *  Pair number with sum equal k
 *
 * input:
 *      T, N
 *      1 ≤ T ≤ 100
 *      1 ≤ n, k ≤ 10^6
 *      -10^6 ≤ A[i] ≤ 10^6
 *
 * output: print the number of pair with sum equal k
 *
 * @example
 *      input:
 *          2
 *          4 4
 *          2 2 2 2
 *          3 3
 *          1 2 3
 *      output:
 *          6
 *          1
 */

ll factorial(int n) {
    if (n == 1)
        return 1;
    return n * factorial(n - 1);
}

const int maxn = 1000005;
int frequency[maxn];

void solve(int a[], int n, int s) {
    ms(frequency, 0);
    FOR(i, 0, n) frequency[a[i]]++;

    ll res = 0;
    FOR(i, 0, n) {
        if (frequency[s - a[i]]) {

            if (a[i] == s - a[i]) {
                res += 1LL * factorial(frequency[a[i]] - 1);
            } else {
                res += 1LL * (frequency[a[i]] * frequency[s - a[i]]);
            }

            frequency[a[i]] = 0;
            frequency[s - a[i]] = 0;
        }
    }

    cout << res << endl;
}

int main() {
    SETUP;

    int TC;
    cin >> TC;
    while (TC--) {
        int n, s;
        cin >> n >> s;
        int a[n];
        FOR(i, 0, n) cin >> a[i];

        solve(a, n, s);
    }

    return 0;
}