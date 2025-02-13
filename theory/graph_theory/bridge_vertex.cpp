#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

int n, m;
vector<int> adj[1001];
bool visited[1001];
set<int> a[1001];
vii edges;

void input() {
    cin >> n >> m;
    REP(i, 1, m) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);

        a[x].insert(y);
        a[y].insert(x);

        edges.push_back(MP(x, y));
    }

    ms(visited, false);
}

void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v])
            dfs(v);
    }
}

int components() {
    int count = 0;
    REP(i, 1, n) {
        if (!visited[i]) {
            dfs(i);
            count++;
        }
    }

    return count;
}

void vertex() {
    ms(visited, false);
    int comps = components();

    REP(i, 1, n) {
        ms(visited, false);
        visited[i] = true;

        if (components() < comps) {
            cout << i << " ";
        }
    }
}

void bridge() {
    int coms = components();

    int count = 0;
    vii res;

    for (auto e : edges) {
        int u = e.F, v = e.S;
        a[u].erase(v);
        a[v].erase(u);

        ms(visited, false);
        if (components() < coms) {
            count++;
            res.PB(MP(u, v));
        }

        a[u].insert(v);
        a[v].insert(u);
    }

    cout << count << endl;
    for (auto it : res)
        cout << it.F << " " << it.S << endl;
}

int main() {
    SETUP;
    input();

    return 0;
}