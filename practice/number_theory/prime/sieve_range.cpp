#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

/**
 * Sieve of Eratosthenes
 *
 * input: a, b (0 <= a <= b <= 10^9) & (b - a <= 10^5)
 * output: print all numbers between inclusively a and b if they are prime
 */

void sieve_range(ll L, ll R) {
    int is_prime[R - L + 1];

    for (ll i = L; i <= R; i++) {
        is_prime[i - L] = 1;
    }

    for (ll i = 2; i <= sqrt(R); i++) {
        for (ll j = max(i * i, (L + i - 1) / i * i); j <= R; j += i) {
            is_prime[j - L] = 0;
        }
    }

    for (ll i = max(2ll, L); i <= R; i++) {
        if (is_prime[i - L]) {
            cout << i << ' ';
        }
    }
}

int main() {
    SETUP;

    ll a, b;
    cin >> a >> b;
    sieve_range(a, b);

    return 0;
}