#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

int n, m, in_degree[DEG];
vector<int> adj[1001];

void kahn() {
    queue<int> q;
    FOR(i, 1, n) {
        if (in_degree[i] == 0)
            q.push(i);
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (int v : adj[u]) {
            in_degree[v]--;
            if (in_degree[v] == 0)
                q.push(v);
        }
    }
}

void input() {
    ms(in_degree, 0);

    cin >> n >> m;
    REP(i, 1, m) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        in_degree[y]++;
    }
}

int main() {
    SETUP;

    input();
    kahn();

    cout << endl;
    return 0;
}