#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

/**
 * Check a number is prime
 *
 * input:
 *      T: number of test cases (1 <= T <= 10^3)
 *      N: number of primes (1 <= N <= 10^6)
 *
 * output: YES or NO
 */

const int maxn = 1e6 + 5;
bool is_prime[maxn + 1];

void sieve() {
    for (int i = 2; i <= maxn; i++) {
        is_prime[i] = true;
    }

    for (int i = 2; i * i <= maxn; i++) {
        if (is_prime[i]) {
            for (int k = i * i; k <= maxn; k += i) {
                is_prime[k] = false;
            }
        }
    }
}

int main() {
    SETUP;
    sieve();

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        if (is_prime[N]) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}