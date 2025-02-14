#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

int n, m, timer = 0;
vector<int> adj[1001];
bool visited[1001];

vector<pair<int, int>> edges;
int disc[1001], low[1001], ap[1001];

void input() {
    cin >> n >> m;
    REP(i, 1, m) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    ms(visited, false);
    ms(ap, 0);
}

void dfs_vertex(int u, int p) {
    visited[u] = true;
    disc[u] = low[u] = ++timer;

    int child = 0;
    for (int v : adj[u]) {
        if (v == p)
            continue;
        if (!visited[v]) {
            dfs_vertex(v, u);
            child++;
            low[u] = min(low[u], low[v]);
            if (p != -1 && disc[u] <= low[v])
                ap[u] = true;
        } else
            low[u] = min(low[u], disc[v]);
    }

    if (p == -1 && child > 1)
        ap[u] = true;
}

void dfs_edge(int u, int p) {
    visited[u] = true;
    disc[u] = low[u] = ++timer;

    for (int v : adj[u]) {
        if (v == p)
            continue;
        if (!visited[v]) {
            dfs_edge(v, u);
            low[u] = min(low[u], low[v]);
            if (p != -1 && disc[u] < low[v])
                edges.PB(MP(u, v));
        } else
            low[u] = min(low[u], disc[v]);
    }
}

int main() {
    SETUP;
    input();

    REP(i, 1, n) {
        if (!visited[i])
            dfs_vertex(i, -1);
    }

    REP(i, 1, n) {
        if (ap[i])
            cout << i << " ";
    }
    cout << endl;

    ms(visited, false);
    REP(i, 1, n) {
        if (!visited[i])
            dfs_edge(i, -1);
    }

    for (auto it : edges)
        cout << it.F << " " << it.S << endl;

    return 0;
}