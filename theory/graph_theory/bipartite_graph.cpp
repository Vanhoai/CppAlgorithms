#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

int n, m, colors[DEG];
vector<int> adj[DEG];

void input() {
    cin >> n >> m;
    FOR(i, 0, m) {
        int x, y;
        cin >> x >> y;
        adj[x].PB(y);
        adj[y].PB(x);
    }
}

bool dfs(int u, int p) {
    colors[u] = 3 - colors[p];

    for (int v : adj[u]) {
        if (colors[v] == 0) {
            if (!dfs(v, u))
                return false;
        } else if (colors[v] == colors[u]) {
            return false;
        }
    }

    return true;
}

int main() {
    SETUP;

    input();

    bool check = true;
    colors[0] = 2;
    REP(i, 1, n) {
        if (!colors[i] && !dfs(i, 0)) {
            check = false;
        }
    }

    if (check)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}