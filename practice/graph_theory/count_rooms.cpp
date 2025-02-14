#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

/**
 * Count Room
 *
 * input:
 *      T, N, M
 *      1 <= T <= 50
 *      1 <= N <= 1000
 *
 * output: print the number of rooms
 *
 * @example
 *      input:
 *          2
 *          6 6
 *          ..###.
 *          ...#..
 *          #..#..
 *          .##.#.
 *          ######
 *          .#.##.
 *          6 6
 *          ####.#
 *          .#..##
 *          .#..##
 *          ####..
 *          #...##
 *          .##..#
 *      output:
 *          7
 *          6
 */

int n, m;
char A[1001][1001];

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void input() {
    cin >> n >> m;
    REP(i, 1, n) REP(k, 1, m) cin >> A[i][k];
}

void dfs(int u, int v) {
    A[u][v] = '#';
    FOR(i, 0, 4) {
        int ix = u + dx[i], iy = v + dy[i];
        if (ix >= 1 && ix <= n && iy >= 1 && iy <= m && A[ix][iy] == '.')
            dfs(ix, iy);
    }
}

int main() {
    SETUP;

    int TC;
    cin >> TC;
    while (TC--) {
        input();
        int count = 0;
        REP(i, 1, n) REP(j, 1, m) {
            if (A[i][j] == '.') {
                count++;
                dfs(i, j);
            }
        }

        cout << count << endl;
    }

    return 0;
}