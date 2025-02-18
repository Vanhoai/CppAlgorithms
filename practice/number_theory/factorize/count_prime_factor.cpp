#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

/**
 * Count Prime Factors
 *
 * input:
 *      T: integer (1 <= T <= 1000)
 *      N: long long (1 <= N <= 10^9)
 *
 * output: print count of prime factors of a number n
 *
 * @example
 *      input: 10000
 *      output: 2 -> (5, 2)
 */

int count_prime_factors(int n) {
    int s = sqrt(n);

    int count[s + 1];
    memset(count, 0, sizeof(count));

    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            count[i]++;
            n /= i;
        }
    }

    if (n > 1)
        count[n]++;

    int res = 0;
    for (int i = 2; i <= s; i++) {
        if (count[i])
            res++;
    }

    return res;
}

int main() {
    SETUP;

    int TC;
    cin >> TC;
    while (TC--) {
        int N;
        cin >> N;

        cout << count_prime_factors(N) << endl;
    }

    return 0;
}