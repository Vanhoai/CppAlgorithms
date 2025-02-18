#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

int n, m, colors[DEG], in[DEG];
vector<int> adj[DEG];

void input() {
    cin >> n >> m;
    FOR(i, 0, m) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        in[v]++;
    }

    ms(colors, 0);
}

bool dfs(int u, int p) {
    colors[u] = 1;
    for (int v : adj[u]) {
        if (colors[v] == 0) {
            if (dfs(v, u))
                return true;
        } else if (colors[v] == 1)
            return true;
    }

    colors[u] = 2;
    return false;
}

bool kahn() {
    queue<int> q;
    REP(i, 1, n) if (in[i] == 0) q.push(i);

    int count = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        count++;

        for (int v : adj[u]) {
            in[v]--;
            if (in[v] == 0)
                q.push(v);
        }
    }

    return count != n;
}

int main() {
    SETUP;

    input();

    bool check = false;
    REP(i, 1, n) {
        if (colors[i] == 0 && dfs(i, 0)) {
            check = true;
            break;
        }
    }

    if (kahn())
        cout << "YES";
    else
        cout << "NO";

    return 0;
}