#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

/**
 * Path in Maze
 *
 * input:
 *      N, Si, Sj, Ei, Ej
 *      2 <= N <= 1000
 *      0 <= A[i][j] <= 1
 *
 * output: print the minimum distance to reach the end
 *
 * @example
 *      input:
 *          10
 *          9 6 9 3
 *          1 1 0 1 1 1 1 0 0 1
 *          0 0 1 0 0 1 0 1 0 1
 *          1 1 1 1 0 0 0 1 1 0
 *          1 0 0 0 1 0 0 0 1 1
 *          1 0 1 0 0 1 0 1 1 0
 *          0 0 1 1 0 1 0 0 0 0
 *          1 1 0 1 0 1 1 0 0 0
 *          0 0 0 1 1 0 1 1 0 1
 *          1 0 1 0 0 1 0 0 1 1
 *          0 1 1 1 1 0 1 0 1 1
 *      output:
 *          3
 */

const int maxn = 1001;
int A[maxn][maxn], D[maxn][maxn];
int n, si, sk, ei, ek;

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

void input() {
    cin >> n;
    cin >> si >> sk >> ei >> ek;
    REP(i, 1, n) REP(k, 1, n) cin >> A[i][k];

    ms(D, 0);
}

void bfs() {
    queue<pi> q;
    q.push(MP(si, sk));
    D[si][sk] = 0;

    while (!q.empty()) {
        pi u = q.front();
        q.pop();
        int x = u.F, y = u.S;
        if (x == ei && y == ek)
            break;

        FOR(i, 0, 8) {
            int ix = x + dx[i], iy = y + dy[i];
            if (ix >= 1 && ix <= n && iy >= 1 && iy <= n && A[ix][iy] == 1) {
                A[ix][iy] = 0;
                q.push(MP(ix, iy));

                D[ix][iy] = D[x][y] + 1;
            }
        }
    }

    cout << D[ei][ek] << endl;
}

int main() {
    SETUP;

    input();
    bfs();

    return 0;
}