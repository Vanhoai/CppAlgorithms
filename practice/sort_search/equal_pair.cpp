#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

/**
 * Equal Pair
 *
 * input:
 *      T, N, A(i)
 *      1 ≤ T ≤ 100
 *      1 ≤ N ≤ 10^5
 *
 * output: print the number of equal pair
 *
 * @example
 *      input:
 *          2
 *          5
 *          8 2 9 8 1
 *          7
 *          6 2 4 2 4 3 4
 *      output:
 *          1
 *          4
 */

int main() {
    SETUP;

    int TC;
    cin >> TC;
    while (TC--) {
        int n;
        cin >> n;
        int a[n];
        FOR(i, 0, n) cin >> a[i];

        sort(a, a + n);

        int ans = 0;
        int count = 1;

        for (int i = 0; i < n - 1; i++) {
            if (a[i] == a[i + 1])
                count++;
            else {
                ans += count * (count - 1) / 2;
                count = 1;
            }
        }

        ans += count * (count - 1) / 2;
        cout << ans << endl;
    }

    return 0;
}