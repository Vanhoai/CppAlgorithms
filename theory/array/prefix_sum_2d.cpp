#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

/**
 * Prefix Sum 2D
 * pre[i][j] = pre[i - 1][j] + pre[i][j -1] - pre[i - 1][j - 1] + a[i][j]
 *
 * 8 8
 * 1 1 0 0 0 1 1 1
 * 1 0 0 0 1 1 1 1
 * 0 1 1 1 0 0 1 0
 * 1 1 1 1 0 1 1 0
 * 1 1 1 1 1 0 1 1
 * 1 0 0 1 0 1 0 1
 * 0 0 0 0 1 0 1 0
 * 1 1 0 0 0 1 0 1
 * 3
 * 2 3 1 7
 * 2 2 2 7
 * 1 2 1 8
 *
 * 8
 * 3
 * 10
 */

int main() {
    SETUP;

    int TC;
    cin >> TC;
    while (TC--) {
        int n, m;
        cin >> n >> m;
        int a[n + 1][m + 1];
        REP(i, 1, n) REP(k, 1, m) cin >> a[i][k];

        int pre[n + 1][m + 1];
        ms(pre, 0);
        REP(i, 1, n) REP(k, 1, m) {
            pre[i][k] =
                pre[i][k - 1] + pre[i - 1][k] - pre[i - 1][k - 1] + a[i][k];
        }

        int q;
        cin >> q;
        FOR(i, 0, q) {
            int i1, i2, k1, k2;
            cin >> i1 >> i2 >> k1 >> k2;

            cout << pre[i2][k2] - pre[i1 - 1][k2] - pre[i2][k1 - 1] +
                        pre[i1 - 1][k1 - 1]
                 << endl;
        }
    }

    return 0;
}