#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

int n, m;
vector<int> adj[DEGREE];
bool visited[DEGREE];

bool dfs(int u, int p) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            if (dfs(v, u))
                return true;
        } else if (v != p) {
            return true;
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
        if (dfs(i, 0)) {
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