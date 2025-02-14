#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

/**
 * Dijsktra's Algorithms
 *
 * d[i] = INF(i: 1 -> n)
 * d[s] = 0
 * while Q not empty
 *      choose vertex have minimum fee
 *      remove in Q
 *      Relaxation d[v] = min(d[v], d[u] + w)
 */

const int maxn = 1001;
int n, m;
vector<pi> adj[maxn];
int d[maxn];

void input() {
    cin >> n >> m;
    FOR(i, 0, m) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].PB(MP(v, w));
        adj[v].PB(MP(u, w));
    }
}

void dijsktra(int s) {
    REP(i, 1, n) d[i] = INF;
    d[s] = 0;

    priority_queue<pi, vii, greater<pi>> Q;
    Q.push(MP(0, s));

    while (!Q.empty()) {
        pi it = Q.top();
        Q.pop();

        int u = it.S, length = it.F;
        if (length > d[u])
            continue;

        for (pi it : adj[u]) {
            int v = it.F, w = it.S;
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                Q.push(MP(d[v], v));
            }
        }
    }

    REP(i, 1, n) cout << d[i] << " ";
}

int main() {
    SETUP;

    input();
    dijsktra(1);

    return 0;
}