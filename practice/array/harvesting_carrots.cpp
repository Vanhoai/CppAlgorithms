#include "bits/stdc++.h"
#include "bits/macros.h"
using namespace std;

/**
 * Prefix Sum in Matrix 2D
 *
 * input:
 *      1<=N,M<=1000
 *      1<=Q<=10^5
 *      1<=x1,x2<=N, 1<=y1,y2<=M
 *
 * output: print sum of query from L to R
 *
 * @example
 *      input:
 *          8 8
 *          1 1 0 0 0 1 1 1
 *          1 0 0 0 1 1 1 1
 *          0 1 1 1 0 0 1 0
 *          1 1 1 1 0 1 1 0
 *          1 1 1 1 1 0 1 1
 *          1 0 0 1 0 1 0 1
 *          0 0 0 0 1 0 1 0
 *          1 1 0 0 0 1 0 1
 *          3
 *          2 3 1 7 // x1, x2, y1, y2
 *          2 2 2 7
 *          1 2 1 8
 *      output:
 *          8
 *          3
 *          10
 */

const int maxn = 1001;
int A[maxn][maxn], Q[maxn][maxn];

void build() {
    int n, m; cin >> n >> m;
    REP(i, 1, n) REP(k, 1, m) cin >> A[i][k];

    memset(Q, 0, sizeof(Q));
    REP(i, 1, n) REP(k, 1, m) {
        Q[i][k] = Q[i - 1][k] + Q[i][k - 1] - Q[i - 1][k - 1] + A[i][k];
    }
}

void query() {
    int q; cin >> q;
    while (q--) {
        int x1, x2, y1, y2;
        cin >> x1 >> x2 >> y1 >> y2;
        int res = Q[x2][y2] - Q[x1 - 1][y2] - Q[x2][y1 - 1] + Q[x1 - 1][y1 - 1];
        cout << res << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    build();
    query();

    return 0;
}












