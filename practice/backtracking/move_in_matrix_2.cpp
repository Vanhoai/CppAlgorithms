#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

/**
 * Move in matrix
 *
 * input:
 *      T, M, N, A[i][j]
 *      1 ≤ T ≤ 10; 1 ≤ M, N, A[i][j] ≤ 100
 *
 * output: print the path from A[0][0] -> A[n - 1][n - 1] with in in path is
 * maximum
 *
 * @example
 *      input:
 *          2
 *          2 3
 *          1 2 3
 *          4 5 6
 *          2 2
 *          1 2
 *          3 4
 *      output:
 *          16
 *          8
 */

const int maxn = 100;
int n, m, ans, a[maxn + 1][maxn + 1];

void input() {
    cin >> n >> m;
    REP(i, 1, n) REP(j, 1, m) cin >> a[i][j];
}

void backtracking(int i, int j, int sum) {
    if (i == n && j == m)
        ans = max(ans, sum);

    if (i + 1 <= n)
        backtracking(i + 1, j, sum + a[i + 1][j]);

    if (j + 1 <= m)
        backtracking(i, j + 1, sum + a[i][j + 1]);
}

int main() {
    SETUP;

    int TC;
    cin >> TC;
    while (TC--) {
        input();
        ans = -1e9;
        backtracking(1, 1, a[1][1]);
        cout << ans << endl;
    }

    return 0;
}