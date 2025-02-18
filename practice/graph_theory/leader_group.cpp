#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

/**
 * Leader Group
 *
 * input:
 *      N, M
 *      1 <= N <= 1000
 *      0 <= M <= N*(N-1)/2
 *      1 <= U, V <= N;
 *
 * output: print all leader each group
 *
 * @example
 *      input:
 *          10 6
 *          4 3
 *          4 1
 *          8 5
 *          8 6
 *          4 2
 *          8 2
 *      output:
 *          4 7 9 10
 */

int n, m;
vector<int> adj[DEG];
bool visited[DEG];
vector<int> comps;

void input() {
    cin >> n >> m;
    REP(i, 1, m) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    ms(visited, false);
    REP(i, 1, n) sort(all(adj[i]));
}

void dfs(int u) {
    comps.PB(u);
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v])
            dfs(v);
    }
}

int main() {
    SETUP;
    input();

    vector<int> ans;

    REP(i, 1, n) {
        if (!visited[i]) {
            comps.clear();
            dfs(i);

            int res = i;
            int max = 0;
            sort(all(comps));
            for (int x : comps) {
                if (adj[x].size() > max) {
                    res = x;
                    max = adj[x].size();
                }
            }

            ans.PB(res);
        }
    }

    sort(all(ans));
    FOR(i, 0, sz(ans)) cout << ans[i] << " ";

    return 0;
}