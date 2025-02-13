#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

int n, m, timer = 0;
vector<int> adj[1001];
bool visited[1001];

int disc[1001], low[1001];

void input() {
    cin >> n >> m;
    REP(i, 1, m) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    ms(visited, false);
}

void dfs(int u) {
    disc[u] = low[u] = ++timer;
    visited[u] = true;

    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        } else {
            low[u] = min(low[u], disc[v]);
        }
    }
}

int main() {
    SETUP;
    input();
    dfs(1);

    return 0;
}