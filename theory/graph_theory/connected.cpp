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

void count_connected() {
    int count = 0;
    REP(i, 1, n) {
        if (!visited[i]) {
            dfs(i);
            count++;
        }
    }

    cout << count << endl;
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
    count_connected();

    return 0;
}