#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

/**
 * Sieve of Eratosthenes
 *
 * input: n (0 <= n <= 10^6)
 * output: print all prime numbers less than n
 */

const int maxn = 1e6 + 5;
bool is_prime[maxn + 1];

void sieve(int n) {
    for (int i = 2; i <= n; i++)
        is_prime[i] = true;

    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int k = i * i; k <= n; k += i) {
                is_prime[k] = false;
            }
        }
    }
}

int main() {
    SETUP;

    int n;
    cin >> n;
    sieve(n);

    for (int i = 2; i <= n; i++) {
        if (is_prime[i])
            cout << i << " ";
    }

    return 0;
}