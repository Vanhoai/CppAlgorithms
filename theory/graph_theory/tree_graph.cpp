#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

int n, height[1001], child[1001];
vector<int> adj[1001];
bool visited[1001];

void input() {
    cin >> n;
    FOR(i, 0, n - 1) {
        int u, v;
        cin >> u >> v;
        adj[u].PB(v);
        adj[v].PB(u);
    }
}

int dfs(int u, int p) {
    height[u] = height[p] + 1;
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
    ms(height, 0);

    dfs(1, 0);

    REP(i, 1, n) cout << child[i] << " ";
    cout << endl;
    REP(i, 1, n) cout << height[i] << " ";

    return 0;
}