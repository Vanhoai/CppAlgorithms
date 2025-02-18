#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

/**
 * Euler's Totient function
 * Count the number of co-prime numbers with n not exceeding n.
 *
 * output: print the number of co-prime numbers with n not exceeding n.
 *
 * @example
 *      input: 10000000000000000
 *      output: 4000000000000000
 */

ll u(ll n) {
    ll res = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            res = res - res / i;
            while (n % i == 0)
                n /= i;
        }
    }

    if (n > 1)
        res = res - res / n;

    return res;
}

int main() {
    SETUP;

    int TC;
    cin >> TC;
    while (TC--) {
        ll n;
        cin >> n;
        cout << u(n) << endl;
    }

    return 0;
}