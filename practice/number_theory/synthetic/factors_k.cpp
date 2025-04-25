#include <iostream>
using namespace std;

/**
 * Factor k th of number
 *
 * input:
 *      T: number of testcases (1 <= T <= 100)
 *      N: number check (1 <= N <= 10^9)
 *      K: k th (1 <= K <= N <= 10^9)
 *
 * output: print factor k th of number, if not exist, print -1
 *
 * @example
 *      input: n = 28, k = 3
 *      output: 7 -> 28 = 2 x 2 x 7
 */

int solve(int n, int k) {

    int th = 1;

    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            if (k == th)
                return i;
            n /= i;
            th++;
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int TC;
    cin >> TC;
    while (TC--) {
        int n, k;
        cin >> n >> k;
        cout << solve(n, k) << endl;
    }

    return 0;
}
