#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

/**
 * Mergesort
 *
 * input:
 *      T, N, A(i)
 *      1 ≤ T ≤ 100
 *      1 ≤ N ≤ 10^5
 *
 * output: print sorted array
 *
 * @example
 *      input:
 *          8
 *          8 7 2 1 5 3 6 4
 *      output:
 *          2 1 3 4 5 8 6 7
 */

int main() {
    SETUP;

    int n;
    cin >> n;
    int a[n];
    FOR(i, 0, n) cin >> a[i];

    FOR(i, 0, n) cout << a[i] << " ";

    return 0;
}