#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

/**
 * Prime Factorization
 *
 * input:
 *      T: integer (1 <= T <= 1000)
 *      N: long long (1 <= N <= 10^9)
 *
 * output: print all prime factors of a number n
 *
 * @example
 *      input: 28
 *      output: 2 2 7
 */

void factors(int n) {
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            cout << i << " ";
            n /= i;
        }
    }

    if (n > 1)
        cout << n;
    cout << endl;
}

int main() {
    SETUP;

    int TC;
    cin >> TC;
    while (TC--) {
        int N;
        cin >> N;
        factors(N);
    }

    return 0;
}