#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

/**
 * Co-Prime
 * A pair of numbers (i,j) is said to be relatively prime if i ≠ j and the
 * greatest common divisor of i with j is 1
 *
 * input:
 *      A, B: two integers (2 < a < b < 100)
 *
 * output: print all pair in range a - b by order ascending
 *
 * @example
 *      input: 5 8
 *      output: (5,6) (5,7) (5,8) (6,7) (7,8)
 */

int is_prime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return 0;
    }

    return n > 1;
}

int gcd(int a, int b) {
    if (b == 0)
        return a;

    return gcd(b, a % b);
}

void solve(int a, int b) {
    for (int i = a; i < b; i++) {
        for (int k = i + 1; k <= b; k++) {
            if (gcd(i, k) == 1) {
                cout << "(" << i << "," << k << ")" << endl;
            }
        }
    }
}

int main() {
    SETUP;

    int A, B;
    cin >> A >> B;

    solve(A, B);

    return 0;
}