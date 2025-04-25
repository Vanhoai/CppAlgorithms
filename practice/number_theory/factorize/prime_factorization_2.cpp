#include <iostream>
#include <map>
using namespace std;

/**
 * Prime Factorization (use sieve of Eratosthenes)
 *
 * input:
 *      T: integer (1 <= T <= 1000)
 *      N: long long (1 <= N <= 10^5)
 *
 * output: print all prime factors of a number n
 *
 * @example
 *      input: 28
 *      output: #TC1: 2(2) 3(1) 5(1)
 */

const int maxn = 1e5;
int f[maxn + 1];

void sieve() {
    for (int i = 0; i <= maxn; i++) {
        f[i] = i;
    }

    for (int i = 2; i * i <= maxn; i++) {
        if (f[i] == i) {
            for (int k = i * i; k <= maxn; k += i) {
                if (f[k] == k) {
                    f[k] = i;
                }
            }
        }
    }
}

void solve(int n) {
    map<int, int> mp;

    while (n != 1) {
        mp[f[n]]++;
        n /= f[n];
    }

    for (auto it : mp) {
        cout << it.first << "(" << it.second << ") ";
    }

    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    sieve();

    int TC;
    cin >> TC;
    while (TC--) {

        int N;
        cin >> N;

        cout << "#TC" << TC + 1 << ": ";
        solve(N);
    }

    return 0;
}
