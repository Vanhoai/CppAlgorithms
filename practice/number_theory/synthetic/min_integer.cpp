#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

/**
 * Min Integer
 * Find the smallest n-digit positive integer that is divisible by x, y, and z.
 *
 * input:
 *      T: number of testcases (1 <= T <= 100)
 *      x, y, z, n (1 ≤ x, y, z ≤ 10^4)  n ≤ 16.
 *
 * output: Print out the number that satisfies the conditions of the question
 *
 * @example
 *      input: 2 3 5 4
 *      output: 1020
 */

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) { return a / gcd(a, b) * b; }

int main() {
    SETUP;

    int TC;
    cin >> TC;
    while (TC--) {
        int x, y, z, n;
        cin >> x >> y >> z >> n;

        int lc = lcm(x, lcm(y, z));
        int res = ((ll) pow(10, n - 1) + lc - 1) / lc * lc;
        if (res > pow(10, n))
            cout << -1 << endl;
        else
            cout << res << endl;
    }

    return 0;
}