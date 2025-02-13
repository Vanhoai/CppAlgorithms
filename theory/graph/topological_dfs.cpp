#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

int n, m;
vector<int> adj[1001];
stack<int> st;
bool visited[1001];

// topological use dfs
void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v])
            dfs(v);
    }

    st.push(u);
}

void input() {
    cin >> n >> m;
    REP(i, 1, m) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }

    ms(visited, false);
}

int main() {
    SETUP;

    input();
    REP(i, 1, n) {
        if (!visited[i])
            dfs(i);
    }

    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

    cout << endl;
    return 0;
}