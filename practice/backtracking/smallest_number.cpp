#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

/**
 * Smallest number with N divisors
 *
 * input:
 *      T, N
 *      T ≤ 20
 *      1 ≤ N ≤ 1000
 *
 * output: print minimum number with N divisors
 *
 * @example
 *      input:
 *          2
 *          4
 *          6
 *      output:
 *          6
 *          12
 */

int p[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
int n;

ll backtracking(int pos, ll count, ll x) {
    if (count == n)
        return x;

    ll tmp = 1e18 + 5;
    int i = 1;
    while (true) {
        x *= p[pos];
        if (x > tmp)
            break;

        if (count * (i + 1) > n)
            break;

        tmp = min(tmp, backtracking(pos + 1, count * (i + 1), x));
        i++;
    }

    return tmp;
}

int main() {
    SETUP;

    int TC;
    cin >> TC;
    while (TC--) {
        cin >> n;
        ll ans = backtracking(0, 1, 1);
        cout << ans << endl;
    }

    return 0;
}