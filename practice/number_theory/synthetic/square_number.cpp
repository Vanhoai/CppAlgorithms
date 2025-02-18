#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

/**
 * Square Number
 *
 *
 * input:
 *      T: number of testcases (1 <= T <= 100)
 *      N: number check (1 <= N <= 10^18)
 *
 * output: YES/NO
 *
 * @example
 *      input: 10000000000000000
 *      output: YES
 */

int is_square(ll n) {
    int s = sqrt(n);
    return n == 1LL * s * s;
}

int main() {
    SETUP;

    int TC;
    cin >> TC;
    while (TC--) {
        ll N;
        cin >> N;

        if (is_square(N))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}