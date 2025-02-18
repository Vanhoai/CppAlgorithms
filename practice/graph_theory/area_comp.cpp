#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

/**
 * Area of connected components
 *
 * input:
 *      N, M
 *      1 <= N,M <= 1000
 *
 * output: print area of each component
 *
 * @example
 *      input:
 *          10 10
 *          ###.#.#..#
 *          .######...
 *          ###..##.#.
 *          .##...###.
 *          ##....#..#
 *          .#..###...
 *          ..####.##.
 *          ...##.....
 *          ..#...####
 *          .#..##.##.
 *      output:
 *          1 1 8 1 11 1 17 9 1 1
 */

int n, m;
char A[1001][1001];
int comp = 0;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void input() {
    cin >> n >> m;
    REP(i, 1, n) REP(k, 1, m) cin >> A[i][k];
}

void dfs(int u, int v) {
    A[u][v] = '#';
    comp++;
    FOR(i, 0, 4) {
        int ix = u + dx[i];
        int iy = v + dy[i];

        if (ix >= 1 && ix <= n && iy >= 1 && iy <= m && A[ix][iy] == '.')
            dfs(ix, iy);
    }
}

int main() {
    SETUP;
    input();

    REP(i, 1, n) REP(k, 1, m) {
        if (A[i][k] == '.') {
            comp = 0;
            dfs(i, k);
            cout << comp << " ";
        }
    }

    return 0;
}