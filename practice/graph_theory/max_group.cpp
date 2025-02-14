#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

/**
 * Max Group Friend
 *
 * input:
 *      N, M
 *      1 <= N <= 1000
 *      0 <= M <= N*(N-1)/2
 *      1 <= U, V <= N;
 *
 * output: print the number of members max in a group
 *
 * @example
 *      input:
 *          10 6
 *          8 2
 *          4 1
 *          8 6
 *          8 7
 *          8 1
 *          8 5
 *      output:
 *          7
 */

int n, m;
vector<int> adj[DEG];
bool visited[DEG];
int comps;

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
    comps++;
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v])
            dfs(v);
    }
}

int main() {
    SETUP;

    input();

    int ans = -1e9;
    REP(i, 1, n) {
        if (!visited[i]) {
            comps = 0;
            dfs(i);
            ans = max(ans, comps);
        }
    }

    cout << ans << endl;
    return 0;
}