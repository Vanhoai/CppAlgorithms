#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

/**
 * Build Path in N city
 *
 * input:
 *      N, M
 *      1 <= N <= 1000
 *      0 <= M <= N*(N-1)/2
 *      1 <= U, V <= N;
 *
 * output: print all bridges need build to connected graph
 *
 * @example
 *      input:
 *          1
 *          6 3
 *          4 3
 *          4 1
 *          4 2
 *      output:
 *          2
 *          1 5
 *          5 6
 */

int n, m;
vector<int> adj[DEG];
vector<int> cons;
bool visited[DEG];

void input() {
    cin >> n >> m;
    REP(i, 1, m) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}

void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v])
            dfs(v);
    }
}

int main() {
    SETUP;

    input();

    int ans = -1;
    REP(i, 1, n) {
        if (!visited[i]) {
            cons.push_back(i);
            dfs(i);
            ans++;
        }
    }

    cout << ans << endl;
    FOR(i, 0, sz(cons) - 1) cout << cons[i] << " " << cons[i + 1] << endl;

    return 0;
}