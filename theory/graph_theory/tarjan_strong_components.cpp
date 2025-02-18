#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

int n, m, timer = 0;
vector<int> adj[1001];
bool visited[1001];
int disc[1001], low[1001];

stack<int> st;
int comps = 0;

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

void dfs(int u, int p) {
    visited[u] = true;
    disc[u] = low[u] = ++timer;
    st.push(u);

    for (int v : adj[u]) {
        if (v == p)
            continue;
        if (!visited[v]) {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
        } else
            low[u] = min(low[u], disc[v]);
    }

    if (disc[u] == low[u]) {
        ++comps;
        cout << comps << endl;
        int v;
        do {
            v = st.top();
            st.pop();
            cout << v << " ";
        } while (v != u);

        cout << endl;
    }
}

int main() {
    SETUP;
    input();

    REP(i, 1, n) {
        if (!visited[i])
            dfs(i, -1);
    }

    return 0;
}