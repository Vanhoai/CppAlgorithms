#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

/**
 *  Couting Sort
 *
 * input:
 *      T, N
 *      1 ≤ T ≤ 100
 *      1 ≤ n ≤ 10^3
 *      0 <= A[i] <= 2
 *
 * output: print arrray sorted
 *
 * @example
 *      input:
 *          2
 *          5
 *          1 1 0 0 2
 *          6
 *          1 1 1 0 0 2
 *      output:
 *          0 0 1 1 2
 *          0 0 1 1 1 2
 */

void counting_sort(int a[], int n) {
    int c[3];
    ms(c, 0);

    FOR(i, 0, n) c[a[i]]++;

    int i = 0;
    FOR(k, 0, 3) {
        while (c[k]) {
            a[i++] = k;
            c[k]--;
        }
    }

    FOR(i, 0, n) cout << a[i] << " ";
    cout << endl;
}

int main() {
    SETUP;

    int TC;
    cin >> TC;
    while (TC--) {
        int n;
        cin >> n;
        int a[n];
        FOR(i, 0, n) cin >> a[i];
        counting_sort(a, n);
    }

    return 0;
}