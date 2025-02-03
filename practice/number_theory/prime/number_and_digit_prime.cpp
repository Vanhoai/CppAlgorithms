#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

/**
 * Number and Digit Prime
 *
 * input:
 *      T: number of test cases (1 <= T <= 10^3)
 *      a, b (1 < a < b < 10^6)
 *
 * output: print the number of numbers between a and b that are prime
 * and the number of digits of the numbers between a and b that are prime
 *
 * @example
 *      input: a = 10, b = 100
 *      output: 4
 *      description: 2, 3, 5, 7
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

int main() {
    SETUP;

    int T;
    cin >> T;
    while (T--) {
        int a, b;
        cin >> a >> b;

        int count = 0;
        for (int i = a; i <= b; i++) {
            if (is_prime(i) && digit_prime(i)) {
                count++;
                cout << i << " ";
            }
        }

        cout << count << endl;
    }

    return 0;
}