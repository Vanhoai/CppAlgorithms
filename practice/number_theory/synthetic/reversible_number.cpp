#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

/**
 * Reversible Number
 *
 *
 * input:
 *      T: number of testcases (1 <= T <= 100)
 *      N: number check (1 <= N <= 10^18)
 *
 * output: YES/NO
 *
 * @example
 *      input: 9999999999999999
 *      output: YES
 */

const int maxn = 18;
int digit[maxn + 1];
int cnt = 0;

void decay_n(ll n) {
    int index = 1;
    while (n) {
        digit[index++] = n % 10;
        n /= 10;
    }

    cnt = index - 1;
}

int solve(ll N) {
    ll sum = 0;
    ll index = cnt;
    for (int i = 1; i <= cnt; i++) {
        ll k = digit[i] * pow(10, --index);
        sum += k;
    }

    return sum == N;
}

int main() {
    SETUP;

    int TC;
    cin >> TC;
    while (TC--) {
        ll N;
        cin >> N;

        memset(digit, 0, sizeof(digit));
        decay_n(N);

        if (solve(N))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}