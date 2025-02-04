#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

/**
 * Count Factor
 *
 * input:
 *      T: number of testcases (1 <= T <= 100)
 *      N: number check (1 <= N <= 10^6)
 *
 * output: print the number of factor of N!
 *
 * @example
 *      input: 97
 *      output: 26494182162432000
 */

int is_prime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return 0;
    }

    return n > 1;
}

int degree(int n, int p) {
    int ans = 0;
    for (int i = p; i <= n; i *= p) {
        ans += n / i;
    }

    return ans;
}

int main() {
    SETUP;

    int TC;
    cin >> TC;
    while (TC--) {
        int n;
        cin >> n;

        int ans = 1;
        for (int i = 1; i <= n; i++) {
            if (is_prime(i)) {
                int d = degree(n, i);
                ans *= (d + 1);
            }
        }

        cout << ans << endl;
    }

    return 0;
}