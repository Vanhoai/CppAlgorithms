#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

/**
 * Divisor of the smallest prime number. (Using the sieve of transformations).
 *
 * input:
 *      T: integer (1 <= T <= 1000)
 *      N: integer (1 <= N <= 10^5)
 *
 * output: print numbers is smallest prime of number from 1 to N
 *
 * @example
 *      input: 10
 *      output: 1 2 3 2 5 2 7 2 3 2
 */

const int maxn = 1e5 + 1;
int p[maxn];

void sieve() {
    for (int i = 1; i <= maxn; i++)
        p[i] = i;

    for (int i = 2; i * i <= maxn; i++) {
        if (p[i] == i) {
            for (int k = i * i; k <= maxn; k += i) {
                if (p[k] == k) {
                    p[k] = i;
                }
            }
        }
    }
}

int main() {
    SETUP;
    sieve();

    int TC;
    cin >> TC;
    while (TC--) {
        int N;
        cin >> N;
        for (int i = 1; i <= N; i++) {
            cout << p[i] << " ";
        }

        cout << endl;
    }

    return 0;
}