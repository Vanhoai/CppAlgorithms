#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

/**
 *  Sort by abs
 *
 * input:
 *      T, N, X, A[i]
 *      1 ≤ T ≤ 100
 *      1 ≤ n, X, A[i] ≤ 10^5
 *
 * output: print array after sorted
 *
 * @example
 *      input:
 *          2
 *          5 7
 *          10 5 3 9 2
 *          5 6
 *          1 2 3 4 5
 *      output:
 *          5 9 10 3 2
 *          5 4 3 2 1
 */

const int maxn = 100005;
int idx[maxn];

int n, X;

bool comparator(int a, int b) {
    if (abs(X - a) == abs(X - b))
        return idx[a] < idx[b];

    return abs(X - a) < abs(X - b);
}

int main() {
    SETUP;

    int TC;
    cin >> TC;
    while (TC--) {
        cin >> n >> X;
        int a[n];
        ms(idx, 0);

        FOR(i, 0, n) {
            cin >> a[i];
            idx[a[i]] = i;
        }

        sort(a, a + n, comparator);
        FOR(i, 0, n) cout << a[i] << " ";
        cout << endl;
    }

    return 0;
}