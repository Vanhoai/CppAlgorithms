#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

int n, m, parent[DEG];
vector<int> adj[DEG];
bool visited[DEG];

bool bfs(int s) {
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (!visited[v]) {
                q.push(v);
                visited[v] = true;
                parent[v] = u;
            } else if (v != parent[u]) {
                return true;
            }
        }
    }

    return false;
}

void input() {
    cin >> n >> m;
    FOR(i, 0, m) {
        int x, y;
        cin >> x >> y;
        adj[x].PB(y);
        adj[y].PB(x);
    }

    ms(visited, false);
}

int main() {
    SETUP;

    input();

    bool ok = false;
    REP(i, 1, n) {
        if (!visited[i] && bfs(i)) {
            ok = true;
            break;
        }
    }

    if (ok)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}