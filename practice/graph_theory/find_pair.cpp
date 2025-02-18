#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

/**
 * Find Pair
 *
 * input:
 *      N
 *      2 <= N <= 1000
 *
 * output: print all leader each group
 *
 * @example
 *      input:
 *          10
 *          9 10
 *          5 9
 *          7 4
 *          4 5
 *          2 3
 *          6 7
 *          7 8
 *          3 6
 *          1 2
 *      output:
 *          51
 */

int n, child[1001];
vector<int> adj[1001];
bool visited[1001];

void input() {
    cin >> n;
    REP(i, 1, n - 1) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}

int dfs(int u, int p) {
    int count = 1;
    for (int v : adj[u]) {
        if (v != p)
            count += dfs(v, u);
    }

    child[u] = count;
    return count;
}

int main() {
    SETUP;

    input();
    dfs(1, -1);

    int ans = 0;
    REP(i, 1, n) ans += child[i];
    cout << ans;

    return 0;
}