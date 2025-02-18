#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

/**
 * Link line
 *
 * input:
 *      T, N, A[i]
 *      N ≤ 2 * 10^6
 *      1 ≤ A[i] ≤ 10^9
 *
 * output: print minimum fee link line
 *
 * @example
 *      input:
 *          7
 *          2 4 1 2 10 2 3
 *      output:
 *          59
 */

int main() {
    SETUP;

    int n;
    cin >> n;
    priority_queue<ll, vector<ll>, greater<ll>> Q;
    FOR(i, 0, n) {
        int x;
        cin >> x;
        Q.push(x);
    }

    ll res = 0;
    while (Q.size() > 1) {
        ll u = Q.top();
        Q.pop();
        ll v = Q.top();
        Q.pop();

        res += 1LL * u + v;
        res %= MOD;
        Q.push(u + v);
    }

    cout << res << endl;

    return 0;
}
