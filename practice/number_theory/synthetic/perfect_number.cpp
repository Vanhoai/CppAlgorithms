#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

/**
 * Perfect Number
 * A perfect number is a number whose sum of proper divisors (excluding itself)
 * is equal to the number itself. Given a positive integer n, check whether n is
 * a perfect number or not. input: T: number of testcases (1 <= T <= 100) N:
 * number check (1 <= N <= 10^9)
 *
 * output: YES/NO
 *
 * @example
 *      input: 2305843008139952128
 *      output: YES
 */

int is_prime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return 0;
    }

    return n > 1;
}

ll perfect[10];
int cnt = 0;

void init() {
    for (int p = 2; p <= 32; p++) {
        if (is_prime(p)) {
            int tmp = (int) pow(2, p) - 1;
            if (is_prime(tmp)) {
                ll n = 1LL * (int) pow(2, p - 1) * tmp;
                perfect[cnt] = n;
                ++cnt;
            }
        }
    }
}

int main() {
    SETUP;

    init();

    int TC;
    cin >> TC;
    while (TC--) {
        ll N;
        cin >> N;

        bool check = false;
        for (int i = 0; i < cnt; i++) {
            if (N == perfect[i]) {
                check = true;
                break;
            }
        }

        cout << (check ? "YES" : "NO") << endl;
    }

    return 0;
}