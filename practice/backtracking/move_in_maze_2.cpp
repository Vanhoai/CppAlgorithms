#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

/**
 * Move in Maze 2
 *
 * input:
 *      T, N, A(i)(j)
 *      1 ≤ T ≤ 10
 *      2 ≤ N ≤ 8
 *      0 ≤ A(i)(j) ≤ 1
 *
 * output: print all way move from (1, 1) to (n, n)
 *
 * @example
 *      input:
 *          3
 *          4
 *          1 0 0 0
 *          1 1 0 1
 *          0 1 0 0
 *          0 1 1 1
 *          4
 *          1 0 0 0
 *          1 1 0 1
 *          1 1 0 0
 *          0 1 1 1
 *          5
 *          1 0 0 0 0
 *          1 1 1 1 1
 *          1 1 1 0 1
 *          0 0 0 0 1
 *          0 0 0 0 1
 *      output:
 *          DRDDRR
 *          DDRDRR DRDDRR
 *          DDRRURRDDD DDRURRRDDD DRDRURRDDD DRRRRDDD
 */

const int maxn = 100;
int n, ok, A[maxn][maxn];

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, -1, 1, 0};
string direction = "DLRU";

void input() {
    cin >> n;
    REP(i, 1, n) REP(j, 1, n) cin >> A[i][j];
}

void backtracking(int i, int j, string path) {
    if (i == n && j == n) {
        ok = 1;
        cout << path << " ";
        return;
    }

    for (int k = 0; k < 4; k++) {
        int ix = i + dx[k];
        int jy = j + dy[k];

        if (ix >= 1 && ix <= n && jy >= 1 && jy <= n && A[ix][jy]) {
            A[ix][jy] = 0;
            backtracking(ix, jy, path + direction[k]);
            A[ix][jy] = 1;
        }
    }
}

int main() {
    SETUP;

    int TC;
    cin >> TC;
    while (TC--) {
        input();
        backtracking(1, 1, "");
        if (!ok)
            cout << "-1\n";
        else
            cout << endl;
    }

    return 0;
}