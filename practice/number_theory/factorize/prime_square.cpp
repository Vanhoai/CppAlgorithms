#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

/**
 * Prime Square
 * A number is considered a beautiful number when it is both divisible by a
 * prime number and divisible by the square of that prime number. Write a
 * program to list beautiful numbers 19 like that in the interval between two
 * given positive integers.
 *
 *
 * input:
 *      L, R (1 ≤ a ≤ b ≤ 10^6)
 *
 * output: Print all numbers that satisfy the above conditions.
 *
 * @example
 *      input: 1 50
 *      output: 4 8 9 12 16 18 20 24 25 27 28 32 36 40 44 45 48 49 50
 */

const int maxn = 1e6;
int prime[maxn + 1];

void sieve() {
    for (int i = 0; i <= maxn; i++)
        prime[i] = 1;

    prime[0] = prime[1] = 0;
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

    int L, R;
    cin >> L >> R;

    for (int i = L; i <= R; i++) {
        bool check = false;

        for (int k = 2; k * k <= i; k++) {
            if (prime[k] && i % k == 0 && i % (k * k) == 0) {
                check = true;
                break;
            }
        }

        if (check)
            cout << i << " ";
    }

    return 0;
}