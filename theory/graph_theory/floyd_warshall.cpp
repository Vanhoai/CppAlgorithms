#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

int n, m;
int d[1001][1001];

void input() {
    cin >> n >> m;
    FOR(i, 0, m) {
        int u, v, w;
        cin >> u >> v >> w;
        d[u][v] = d[v][u] = w;
    }
}

void floyd() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

int main() {
    SETUP;

    input();
    floyd();

    int q;
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        cout << d[x][y] << endl;
    }

    return 0;
}