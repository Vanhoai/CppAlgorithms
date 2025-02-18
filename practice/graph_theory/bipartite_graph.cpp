#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

/**
 * Bipartite Graph
 *
 * input:
 *      N, M
 *      1 <= N <= 1000
 *      1 <= M <= N*(N-1)/2
 *      1 <= u,v <= N
 *
 * output: YES/NO
 *
 * @example
 *      input:
 *          5 4
 *          1 2
 *          3 2
 *          4 3
 *          4 5
 *      output:
 *          YES
 */

int n, m, colors[1001];
vector<int> adj[1001];

/**
 * Coloring
 * 0 -> not visited
 * 1 -> red
 * 2 -> green
 */

void input() {
    cin >> n >> m;
    FOR(i, 0, m) {
        int x, y;
        cin >> x >> y;
        adj[x].PB(y);
        adj[y].PB(x);
    }

    ms(colors, 0);
}

bool dfs(int u, int p) {
    colors[u] = 3 - colors[p];
    for (int v : adj[u]) {
        if (colors[v] == 0) {
            if (!dfs(v, u))
                return false;
        } else if (colors[v] == colors[u])
            return false;
    }

    return true;
}

int main() {
    SETUP;

    int TC;
    cin >> TC;
    while (TC--) {
        input();

        bool check = true;
        colors[0] = 2;
        REP(i, 1, n) {
            if (colors[i] == 0 && !dfs(i, 0)) {
                check = false;
                break;
            }
        }

        cout << (check ? "YES" : "NO") << endl;
    }

    return 0;
}