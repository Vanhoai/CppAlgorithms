#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

int n, m, s, e, parent[DEGREE];
vector<int> adj[DEGREE];
bool visited[DEGREE];

void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
            parent[v] = u;
        }
    }
}

void input() {
    cin >> n >> m >> s >> e;
    FOR(i, 1, m) {
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
    dfs(s);

    if (!visited[e])
        cout << "No Path" << endl;
    else {
        vi path;
        while (e != s) {
            path.push_back(e);
            e = parent[e];
        }

        path.push_back(s);
        INVERSE(i, path.size() - 1, 0) cout << path[i] << " ";
        cout << endl;
    }

    return 0;
}