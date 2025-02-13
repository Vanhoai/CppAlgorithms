#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

int n, m, height[DEG];
vector<int> adj[DEG];
bool visited[DEG];

void input() {
    cin >> n >> m;
    FOR(i, 0, m) {
        int x, y;
        cin >> x >> y;
        adj[x].PB(y);
        adj[y].PB(x);
    }
}

void dfs(int u, int h) {
    visited[u] = true;
    height[u] = h;

    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v, h + 1);
        }
    }
}

void bfs(int s) {
    queue<int> q;
    q.push(s);
    visited[s] = true;
    height[s] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
                height[v] = height[u] + 1;
            }
        }
    }
}

int main() {
    SETUP;
    input();
    dfs(1, 0);

    REP(i, 1, n) cout << height[i] << " ";

    return 0;
}