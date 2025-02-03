#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

/**
 * T-Prime
 *
 * input:
 *      T: integer (1 <= T <= 100)
 *      N: integer (1 <= N <= 10^6)
 *
 * output: print all number from 1 to N with exactly 3 factors
 *
 * @example
 *      input: 50
 *      output: 4 9 25 49
 */

const int maxn = 1e6 + 5;
int prime[maxn];

void sieve() {
    memset(prime, 1, sizeof(prime));

    for (int i = 2; i * i <= maxn; i++) {
        if (prime[i]) {
            for (int k = i * i; k <= maxn; k += i) {
                prime[k] = 0;
            }
        }
    }
}

void solve(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (prime[i]) {
            cout << i * i << " ";
        }
    }

    cout << endl;
}

int main() {
    SETUP;
    sieve();

    int TC;
    cin >> TC;
    while (TC--) {
        int N;
        cin >> N;

        solve(N);
    }

    return 0;
}