#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

/**
 * T-Prime 3
 *
 * input:
 *      T: integer (1 <= T <= 100)
 *      L, R: integer (1 ≤ L, R ≤ 10^12)
 *
 * output: print the number of number with exactly 3 factors in the range [L, R]
 *
 * @example
 *      input: 1 1000000000000
 *      output: 78498
 */

const int maxn = 1e6 + 1;
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

int main() {
    SETUP;

    sieve();

    int TC;
    cin >> TC;
    while (TC--) {
        ll L, R;
        cin >> L >> R;

        int count = 0;
        int c1 = sqrt(L);
        int c2 = sqrt(R);

        for (ll i = max(2, c1); i <= c2; i++) {
            if (prime[i]) {
                count++;
            }
        }

        cout << count << endl;
    }

    return 0;
}