#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

/**
 * Binary Pow
 *
 * input:
 *      N, K
 *      1<=N<=10^6
 *      1<=K<=10^9
 *
 * output: print result of N ^ K mod 10^9 + 7
 *
 * a^b = {
 *      b == 0 -> 1
 *      b even -> a^b/2 * a^b/2
 *      b old -> a^b/2 * a^b/2 * a
 * }
 * 
 * @example
 *      input:
 *          2
 *          9 9
 *          994402 999992619
 *      output:
 *          387420489
 *          925329307
 */

ll binpow(ll a, ll b) {
    if (b == 0) return 1;

    ll n = binpow(a, b / 2);
    if (b % 2 == 0)
        return (n % MOD) * (n % MOD) % MOD;
    else 
        return ((n % MOD) * (n % MOD)% MOD) * (a % MOD) % MOD;
}

int main() {
    SETUP;

    int TC; cin >> TC;
    while (TC--) {
        ll n, k; cin >> n >> k;
        cout << binpow(n, k) << endl;
    }

    return 0;
}

























