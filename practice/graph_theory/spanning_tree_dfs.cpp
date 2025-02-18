#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

/**
 * Spanning Tree DFS
 *
 * input:
 *      N, M, s
 *      1 <= s <= n <= 1000
 *      1 <= m <= n*(n - 1)/2
 *
 * output: print all edge in spanning tree
 *
 * @example
 *      input:
 *          9 18 4
 *          9 3
 *          5 4
 *          5 1
 *          5 2
 *          7 5
 *          4 3
 *          8 5
 *          4 2
 *          2 1
 *          9 4
 *          7 2
 *          8 6
 *          9 7
 *          4 1
 *          6 1
 *          9 1
 *          6 3
 *          7 1
 *      output:
 *          4->1
 *          4->2
 *          4->3
 *          4->5
 *          4->9
 *          1->6
 *          1->7
 *          5->8
 */

int n, m, s;
vector<int> adj[1001];
bool visited[1001];

void input() {
    cin >> n >> m >> s;
    FOR(i, 0, m) {
        int x, y;
        cin >> x >> y;
        adj[x].PB(y);
        adj[y].PB(x);
    }

    REP(i, 1, n) sort(all(adj[i]));
    ms(visited, false);
}

void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            cout << u << "->" << v << endl;
            dfs(v);
        }
    }
}

int main() {
    SETUP;

    input();
    dfs(s);

    return 0;
}