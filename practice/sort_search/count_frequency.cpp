#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

/**
 * Count number of elements in array
 *
 * input:
 *      T, N, K, A(i)
 *      1 ≤ T ≤ 100
 *      1 ≤ N ≤ 10^5
 *
 * output: print frequency of element in array
 *
 * @example
 *      input:
 *          2
 *          5 3
 *          1 2 3 3 3
 *          5 4
 *          1 1 2 5 6
 *      output:
 *          3
 *          0
 */

int first(int a[], int n, int k) {
    int res = -1;
    int l = 0, r = n - 1;
    while (l <= r) {
        int m = (l + r) >> 1;
        if (a[m] == k) {
            res = m;
            r = m - 1;
        } else if (a[m] > k)
            r = m - 1;
        else
            l = m + 1;
    }

    if (res != -1)
        return res + 1;
    return res;
}

int last(int a[], int n, int k) {
    int res = -1;
    int l = 0, r = n - 1;
    while (l <= r) {
        int m = (l + r) >> 1;
        if (a[m] == k) {
            res = m;
            l = m + 1;
        } else if (a[m] > k)
            r = m - 1;
        else
            l = m + 1;
    }

    if (res != -1)
        return res + 1;
    return res;
}

int main() {
    SETUP;

    int TC;
    cin >> TC;
    while (TC--) {
        int n, k;
        cin >> n >> k;
        int a[n];
        FOR(i, 0, n) cin >> a[i];

        int f = first(a, n, k);
        int l = last(a, n, k);

        if (f != -1 && l != -1)
            cout << l - f + 1 << endl;
        else
            cout << 0 << endl;
    }

    return 0;
}