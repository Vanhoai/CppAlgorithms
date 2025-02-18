#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

/**
 * Sum Digit
 *
 * input:
 *      T: number of testcases (1 <= T <= 100)
 *      N: number check (1 <= N <= 10^18)
 *
 * output: print sum of digit of N
 *
 * @example
 *      input: 10000000000000000
 *      output: 1
 */

int sum_digit(ll n) {
    int sum = 0;
    while (n) {
        sum += n % 10;
        n /= 10;
    }

    return sum;
}

int main() {
    SETUP;

    int TC;
    cin >> TC;
    while (TC--) {
        ll n;
        cin >> n;
        cout << sum_digit(n) << endl;
    }

    return 0;
}