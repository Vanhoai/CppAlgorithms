#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

int n, m;
vector<int> adj[1001];
bool visited[1001];

void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v])
            dfs(v);
    }
}

void bfs(int s) {
    queue<int> q;
    visited[s] = true;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

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

int main() {
    SETUP;

    input();
    dfs(1);   // visited from 1 to all degree
    bfs(2);   // visited from 2 to all degree

    return 0;
}