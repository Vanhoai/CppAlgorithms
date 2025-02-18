#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

/**
 * Lucky Number
 *
 * input:
 *      T, N
 *      1 <= T <= 50
 *      1 <= N <= 10^5
 *
 *      1, 2, 5, 10, 20, 50, 100, 200, 500, 1000
 *
 * output: print the minimum number of paper
 *
 * @example
 *      input:
 *          2
 *          70
 *          121
 *      output:
 *          2
 *          3
 */

int main() {
    SETUP;

    int X[10] = {1000, 500, 200, 100, 50, 20, 10, 5, 2, 1};

    int TC;
    cin >> TC;
    while (TC--) {
        int n;
        cin >> n;

        int res = 0;

        for (int i = 0; i < 10; i++) {
            res += n / X[i];
            n %= X[i];
        }

        cout << res << endl;
    }

    return 0;
}
