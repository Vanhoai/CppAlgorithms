#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

/**
 * Minimum Sum
 *
 * input:
 *      T, N, A[i]
 *      1 ≤ T ≤ 100
 *      1 ≤ N ≤ 20
 *      0 ≤ A[i] ≤ 9
 *
 * output: print minimum sum from two number make from array
 *
 * @example
 *      input:
 *          2
 *          6
 *          6 8 4 5 2 3
 *          5
 *          5 3 0 7 4
 *      output:
 *          604
 *          82
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

        vector<int> v;
        FOR(i, 0, n) {
            if (a[i])
                v.PB(a[i]);
        }

        int n1 = 0;
        int n2 = 0;

        for (int i = 0; i < v.size(); i += 2)
            n1 = n1 * 10 + v[i];

        for (int i = 1; i < v.size(); i += 2)
            n2 = n2 * 10 + v[i];

        cout << n1 + n2 << endl;
    }

    return 0;
}