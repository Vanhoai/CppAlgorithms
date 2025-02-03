#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

/**
 * Pair Prime
 *
 * input:
 *      T: number of test cases (1 <= T <= 100)
 *      N: number of pairs (1 <= N <= 10^5)
 *
 * output: print all pairs with sum of them equal to N
 *
 * @example
 *      input: N = 6
 *      output: 3 3
 */

const int maxn = 1e5 + 1;
map<int, int> mp;

void sieve() {
    for (int i = 1; i <= maxn; i++) {
        mp[i] = 1;
    }

    mp[1] = 0;
    for (int i = 2; i * i <= maxn; i++) {
        if (mp[i]) {
            for (int k = i * i; k <= maxn; k += i) {
                mp[k] = 0;
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

        for (int i = N - 1; i >= 2; i--) {
            if (mp[i] && mp[N - i]) {
                cout << i << " " << N - i << endl;
            }
        }
    }

    return 0;
}