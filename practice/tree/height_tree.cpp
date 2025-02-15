#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

/**
 * 2
 * 5
 * 1 2
 * 1 3
 * 2 4
 * 2 5
 * 4
 * 1 2
 * 2 3
 * 3 4
 *
 * 2
 * 3
 */

vector<int> adj[100001];
int d[100001];
bool visited[100001];
int n;

void input() {
    cin >> n;
    FOR(i, 0, n - 1) {
        int u, v;
        cin >> u >> v;
        adj[u].PB(v);
        adj[v].PB(u);
    }

    ms(visited, false);
    ms(d, 0);
}

void bfs(int s) {
    queue<int> q;
    q.push(s);
    visited[s] = true;
    d[s] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (!visited[v]) {
                d[v] = d[u] + 1;
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int main() {
    SETUP;

    int TC;
    cin >> TC;
    while (TC--) {
        input();
        bfs(1);

        cout << *max_element(d + 1, d + n + 1) << endl;
        REP(i, 1, n) adj[i].clear();
    }

    return 0;
}