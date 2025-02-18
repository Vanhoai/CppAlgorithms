#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

const int maxn = 1001;

int n, m;
vii adj[1001];
bool used[1001];

struct Edge {
    int u, v, w;
};

void input() {
    cin >> n >> m;
    FOR(i, 0, m) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].PB(MP(v, w));
        adj[v].PB(MP(u, w));
    }
}

void prim(int s) {
    priority_queue<pi, vii, greater<pi>> Q;
    used[s] = true;

    for (pi v : adj[s]) {
        if (!used[v.F])
            Q.push(MP(v.S, v.F));
    }

    int d = 0, count = 0;
    vector<Edge> edges;

    while (!Q.empty()) {
        pi e = Q.top();
        Q.pop();
        int u = e.S, w = e.F;

        if (!used[u]) {
            count++;
            d += w;
            used[u] = true;

            for (pi v : adj[u]) {
                if (!used[v.F])
                    Q.push(MP(v.S, v.F));
            }
        }
    }

    cout << d << endl;
}

int main() {
    SETUP;

    input();
    prim(1);

    return 0;
}