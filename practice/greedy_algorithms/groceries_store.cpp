#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

/**
 * Groceries Store
 *
 * input:
 *      T, N, S, M
 *      1 ≤ T ≤ 100
 *      1 ≤ N, S, M ≤ 30
 *
 * output: print the number of day at least can buy for s next day
 *
 * @example
 *      input:
 *          2
 *          16 10 2
 *          20 10 30
 *      output:
 *          2
 *          -1
 *
 */

int check(int n, int s, int m) {
    if (m > n)
        return -1;

    int sun = s / 7;
    bool check = n * (s - sun) >= m * s;

    if (!check)
        return -1;

    FOR(i, 1, n - sun + 1) {
        if (s * m <= i * n)
            return i;
    }

    return -1;
}

int main() {
    SETUP;

    int TC;
    cin >> TC;
    while (TC--) {
        int n, s, m;
        cin >> n >> s >> m;
        cout << check(n, s, m) << endl;
    }

    return 0;
}
