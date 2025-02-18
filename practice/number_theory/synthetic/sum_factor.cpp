#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

/**
 * Sum Factor
 *
 *
 * input:
 *      T: number of testcases (1 <= T <= 100)
 *      N: number check (1 <= N <= 10^9)
 *
 * output: print all square number in range
 *
 * @example
 *      input: 10
 *      output: 18 (1 + 10 + 2 + 5)
 */

int main() {
    SETUP;

    int TC;
    cin >> TC;
    while (TC--) {
        ll N;
        cin >> N;

        int sum = 0;
        for (int i = 2; i * i <= N; i++) {
            if (N % i == 0) {
                sum += i;
                if (i != N / i)
                    sum += N / i;
            }
        }

        sum += N + 1;
        cout << sum << endl;
    }

    return 0;
}