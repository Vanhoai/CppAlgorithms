#include <iostream>
using namespace std;

/**
 * Euler's Totient function 2
 *
 * input: N: integer (1 ≤ n ≤ 10^6)
 * output: print u(i) from 1 -> N
 *
 * @example
 *      input: 10
 *      output: 1 1 2 2 4 2 6 4 6 4
 */

const int maxn = 1e6;
int du[maxn + 1];

void init() {
    for (int i = 1; i <= maxn; i++) {
        du[i] = i;
    }

    for (int i = 2; i <= maxn; i++) {
        if (du[i] == i) {   // if i is prime
            du[i] = i - 1;
            for (int j = i * 2; j <= maxn; j += i) {
                du[j] = du[j] - du[j] / i;
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

    init();

    int TC;
    cin >> TC;
    while (TC--) {
        int n;
        cin >> n;

        for (int i = 1; i <= n; i++) {
            cout << du[i] << " ";
        }

        cout << endl;
    }

    return 0;
}
