#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

/**
 * Check a number is prime
 *
 * input: n (0 <= n <= 10^9)
 * output: YES or NO
 */

int is_prime(ll n) {
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return 0;
    }

    return n > 1;
}

int main() {
    SETUP;

    ll n;
    cin >> n;

    if (is_prime(n)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}