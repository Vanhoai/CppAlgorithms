#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

/**
 * Repair Road
 *
 * input:
 *      1 ≤ n ≤ 10^5
 *      1 ≤ m ≤ 2*10^5
 *      1 ≤ a,b ≤ n
 *      1 ≤ c ≤ 10^9
 *
 * output: print minimum fee repair road
 *
 * @example
 *      input:
 *          5 6
 *          1 2 3
 *          2 3 5
 *          2 4 2
 *          3 4 8
 *          5 1 7
 *          5 4 4
 *      output:
 *          14
 */

struct Edge {
    int u;
    int v;
    int w;
};

int n, m, sz[1001], parent[1001];
vector<Edge> adj;

int Find(int u) {
    if (u == parent[u])
        return u;

    return parent[u] = Find(parent[u]);
}

bool Union(int u, int v) {
    u = Find(u);
    v = Find(v);

    if (u == v)
        return false;

    if (sz[u] < sz[v])
        swap(u, v);

    sz[u] += sz[v];
    parent[v] = u;

    return true;
}

void input() {
    cin >> n >> m;
    FOR(i, 0, m) {
        int u, v, w;
        cin >> u >> v >> w;
        adj.PB((Edge) {u, v, w});
    }

    REP(i, 1, n) {
        sz[i] = 1;
        parent[i] = i;
    }
}

bool cmp(Edge a, Edge b) { return a.w < b.w; }

void kruskal() {
    sort(all(adj), cmp);
    ll ans = 0;
    int count = 0;

    FOR(i, 0, m) {
        if (count == n - 1)
            break;

        if (Union(adj[i].u, adj[i].v)) {
            count++;
            ans += adj[i].w;
        }
    }

    if (count != n - 1)
        cout << "IMPOSSIBLE";
    else
        cout << ans << endl;
}

int main() {
    SETUP;

    input();
    kruskal();

    return 0;
}