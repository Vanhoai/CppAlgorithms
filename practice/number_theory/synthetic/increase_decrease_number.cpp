#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

/**
 * Increase/Decrease Number
 * A number is said to be an increase/decrease number if digits of the number
 * are increasing/decreasing in order. Your'mission is count all number is an
 * increase/decrease number have n digits with n available.
 *
 * input:
 *      T: number of testcases (1 <= T <= 100)
 *      N: number check (1 <= N <= 6)
 *
 * output: print the number of increase/decrease number have n digits with n
 * available.
 *
 * @example
 *      input: 2
 *      output: 20
 */

int count_digit(int n) {
    int count = 0;
    while (n) {
        count++;
        n /= 10;
    }

    return count;
}

int is_prime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return 0;
    }

    return n > 1;
}

int solve(int n) {
    int count = 0;
    for (int i = pow(10, n - 1); i < pow(10, n); i++) {
        if (is_prime(i) && count_digit(i) == n) {
            count++;
        }
    }

    return count;
}

int main() {
    SETUP;

    int TC;
    cin >> TC;
    while (TC--) {
        int N;
        cin >> N;

        cout << solve(N) << endl;
    }

    return 0;
}