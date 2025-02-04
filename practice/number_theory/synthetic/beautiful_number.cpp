#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

/**
 * Beautiful Numbers
 * A number is said to be beautiful if it is a prime number and
 * sum of digits of the number is exist in fibonacci number.
 *
 * input:
 *      L, R: range of number (1 ≤ a ≤ b ≤ 10^9)
 *
 * output: print all beautiful number in range, if not exist, print -1
 *
 * @example
 *      input: 2 50
 *      output: 2 3 5 11 17 23 41
 */

ll f[93];

void init() {
    f[0] = 0;
    f[1] = 1;
    for (int i = 2; i <= 92; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }
}

int sum_digit(ll n) {
    int sum = 0;
    while (n) {
        sum += n % 10;
        n /= 10;
    }

    return sum;
}

int is_prime(ll n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return 0;
    }

    return n > 1;
}

int check_in_fib(int n) {
    for (int i = 0; i <= 92; i++) {
        if (n == f[i]) {
            return 1;
        }
    }

    return 0;
}

int main() {
    SETUP;
    init();

    int TC;
    cin >> TC;
    while (TC--) {
        ll L, R;
        cin >> L >> R;

        int check = 0;
        for (ll i = L; i <= R; i++) {
            if (is_prime(i) && check_in_fib(sum_digit(i))) {
                check = 1;
                cout << i << " ";
            }
        }

        if (!check)
            cout << "-1";

        cout << endl;
    }

    return 0;
}