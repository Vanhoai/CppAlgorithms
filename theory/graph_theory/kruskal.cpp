#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

struct Edge {
    int u;
    int v;
    int w;
};

int n, m;
int sz[100001], parent[100001];
vector<Edge> edges;

void init() {
    REP(i, 1, n) {
        sz[i] = 1;
        parent[i] = i;
    }
}

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

    if (sz[u] > sz[v]) {
        parent[v] = u;
        sz[u] += sz[v];
    } else {
        parent[u] = v;
        sz[v] += sz[u];
    }

    return true;
}

void input() {
    cin >> n >> m;
    FOR(i, 0, m) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.PB((Edge) {u, v, w});
    }
}

void kruskal() {
    sort(all(edges), [](Edge a, Edge b) -> bool { return a.w < b.w; });
    int d = 0;

    vector<Edge> mst;
    FOR(i, 0, m) {
        if (mst.size() == n - 1)
            break;

        Edge e = edges[i];
        if (Union(e.u, e.v)) {
            mst.PB(e);
            d += e.w;
        }
    }

    cout << d << endl;
    for (auto it : mst)
        cout << it.u << "->" << it.v << ": " << it.w << endl;
}

int main() {
    SETUP;

    input();
    init();
    kruskal();

    return 0;
}