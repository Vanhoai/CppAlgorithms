#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

/**
 * Lucky Number
 *
 * input:
 *      T, N
 *      1 <= T <= 100
 *      1 <= N <= 10^6
 *
 * output: print minimum number with digit 4, 7 and sum of number equal k
 *
 * @example
 *      input:
 *          2
 *          11
 *          10
 *      output:
 *          47
 *          -1
 */

int main() {
    SETUP;

    // 4A + 7B = N

    int TC;
    cin >> TC;
    while (TC--) {
        ll n;
        cin >> n;

        int ok = 0;

        for (int b = n / 7; b >= 0; b--) {
            int remain = n - 7 * b;
            if (remain % 4 == 0) {
                ok = 1;
                int a = remain / 4;
                cout << string(a, '4');
                cout << string(b, '7');
                cout << endl;
                break;
            }
        }

        if (!ok)
            cout << -1 << endl;
    }

    return 0;
}