#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

/**
 * Kosaraju's Algorithm
 *
 * 1. Topological
 * 2. Make transpose graph
 * 3. Loop in topological order and dfs in transpose graph
 */

int n, m;
vector<int> adj[1001];
vector<int> trans[1001];

bool visited[1001];
stack<int> st;

void input() {
    cin >> n >> m;
    REP(i, 1, m) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        trans[y].push_back(x);
    }

    ms(visited, false);
}

void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v])
            dfs(v);
    }

    st.push(u);
}

void dfs_trans(int u) {
    visited[u] = true;
    cout << u << " ";
    for (int v : trans[u]) {
        if (!visited[v])
            dfs_trans(v);
    }
}

void kosaraju() {
    ms(visited, false);
    while (!st.empty()) {
        int u = st.top();
        st.pop();

        if (!visited[u]) {
            dfs_trans(u);
            cout << endl;
        }
    }
}

int main() {
    SETUP;
    input();

    REP(i, 1, n) {
        if (!visited[i])
            dfs(i);
    }

    kosaraju();
    return 0;
}