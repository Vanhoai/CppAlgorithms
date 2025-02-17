#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

/**
 * String Fibonacci
 * S(1) = 'A', S(2) = 'B'
 * S(n) = S(n - 2) + S(n - 1)
 *
 * input:
 *      N, K
 *      1<=N<=92
 *      1<=K<=7e18
 *
 * output: print result of N ^ K mod 10^9 + 7
 * 
 * @example
 *      input:
 *          5 3
 *      output:
 *          B
 */

ll f[100];

void init() {
    f[0] = 0;
    f[1] = 1;
    for (int i = 2; i <= 92; i++)
        f[i] = f[i - 1] + f[i - 2];
}

char fibo(int n, ll k) {
    if (n == 1) return 'A';
    if (n == 2) return 'B';

    if (k <= f[n - 2])
        return fibo(n - 2, k);
    else 
        return fibo(n - 1, k - f[n - 2]);
}

int main() {
    SETUP;

    init();
    int TC; cin >> TC;
    while (TC--) {
        int n;
        ll k;
        cin >> n >> k;
        cout << fibo(n, k) << endl;
    }

    return 0;
}

















