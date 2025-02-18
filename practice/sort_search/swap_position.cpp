#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

/**
 * Swap Position
 *
 * input:
 *      T, N, M, A(i)
 *      1 ≤ T ≤ 100
 *      1 ≤ N, M ≤ 10^5
 *
 * output: print maximum milk
 *
 * @example
 *      input:
 *          1
 *          5
 *          5 4 3 2 1
 *      output:
 *          1 5
 *          2 4
 */
// quicksort with hoare partition, pivot is the last element of segment
void qs_hoare(int a[], int l, int r) {
    int i = l, j = r, x = a[r];
    while (i <= j) {
        while (a[i] < x)
            ++i;
        while (a[j] > x)
            --j;

        if (i <= j) {
            if (i != j) {
                cout << a[i] << " " << a[j] << endl;
            }
            swap(a[i], a[j]);

            ++i;
            --j;
        }
    }
    if (i < r)
        qs_hoare(a, i, r);
    if (l < j)
        qs_hoare(a, l, j);
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
        qs_hoare(a, 0, n - 1);
    }

    return 0;
}