#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

/**
 *  Lero Singer
 *
 * input:
 *      N, A[i], B[i]
 *      1 ≤ N ≤ 1000
 *
 * output: print the number of subset
 *
 * @example
 *      input:
 *          1
 *          6
 *          3 8
 *          9 12
 *          6 10
 *          1 4
 *          2 7
 *          11 1 4
 *      output:
 *          3
 */

bool cmp(pair<int, int> a, pair<int, int> b) { return a.second < b.second; }

int main() {
    SETUP;

    int TC;
    cin >> TC;
    while (TC--) {
        int n;
        cin >> n;
        vii a(n);

        for (int i = 0; i < n; i++)
            cin >> a[i].F >> a[i].S;

        sort(a.begin(), a.end(), cmp);

        int res = 1;
        int end_time = a[0].S;
        for (int i = 1; i < n; i++) {
            if (a[i].F > end_time) {
                res++;
                end_time = a[i].S;
            }
        }

        cout << res << endl;
    }

    return 0;
}