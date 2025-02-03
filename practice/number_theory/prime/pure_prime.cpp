#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

/**
 * Pure Prime
 * A number is considered to be prime if it is prime, all of its digits are
 * prime, and the sum of its digits is also a prime. The problem is to count how
 * many prime numbers there are between two given integers.
 *
 * input:
 *      T: number of test cases (1 <= T <= 100)
 *      A, B: two integers (1 <= A <= B <= 10^9)
 *
 * output: print count of pure prime numbers between A and B
 *
 * @example
 *      input: 23 199
 *      output: 1 number: 23
 */

int is_prime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return 0;
    }

    return n > 1;
}

int digit_prime(int n) {
    while (n) {
        if (!is_prime(n % 10)) {
            return 0;
        }

        n /= 10;
    }

    return 1;
}

int sum_prime(int n) {
    int sum = 0;
    while (n) {
        sum += n % 10;
        n /= 10;
    }

    return is_prime(sum);
}

int main() {
    SETUP;

    int TC;
    cin >> TC;
    while (TC--) {
        int A, B;
        cin >> A >> B;

        int count = 0;
        REP(i, A, B) {
            if (is_prime(i) && digit_prime(i) && sum_prime(i)) {
                count++;
            }
        }

        cout << count << endl;
    }

    return 0;
}