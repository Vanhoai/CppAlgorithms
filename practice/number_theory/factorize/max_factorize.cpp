#include <iostream>
using namespace std;

/**
 * Max factorize
 *
 * input:
 *      T: 1 ≤ T ≤ 100
 *      N: 1 ≤ N ≤ 10^6
 *
 * output: print max factor is prime of N
 *
 * @example
 *      input: 10
 *      output: 5
 */

const int maxn = 1e6;
int p[maxn + 1];

void sieve() {
    for (int i = 1; i <= maxn; i++) {
        p[i] = i;
    }

    for (int i = 2; i * i <= maxn; i++) {
        if (p[i] == i) {
            for (int k = i * i; k <= maxn; k += i) {
                p[k] = i;
            }
        }
    }
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

        cout << p[N] << endl;
    }

    return 0;
}
