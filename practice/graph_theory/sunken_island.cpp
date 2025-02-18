#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

/**
 * Sunken Island
 *
 * input:
 *      N, M
 *      1 <= N <= 1000
 *      1 <= M <= N*(N-1)/2
 *      1 <= u,v <= N
 *
 * output: print all island which can be sunken
 * and therefore can be disconnected
 *
 * @example
 *      input:
 *          6 8
 *          1 3
 *          6 1
 *          6 3
 *          4 1
 *          6 4
 *          5 2
 *          3 2
 *          3 5
 *      output:
 *          1
 */

int n, m;
vector<int> adj[1001];
bool visited[1001];

void input() {
    cin >> n >> m;
    FOR(i, 0, m) {
        int u, v;
        cin >> u >> v;
        adj[u].PB(v);
        adj[v].PB(u);
    }

    ms(visited, false);
}

void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v])
            dfs(v);
    }
}

int components() {
    int count = 0;
    REP(i, 1, n) {
        if (!visited[i]) {
            dfs(i);
            count++;
        }
    }

    return count;
}

int main() {
    SETUP;

    input();

    vi v;
    int cc = components();
    REP(i, 1, n) {
        ms(visited, false);
        visited[i] = true;
        if (components() > cc)
            v.push_back(i);
    }

    cout << v.size() << endl;
    FOR(i, 0, sz(v)) cout << v[i] << " ";

    return 0;
}