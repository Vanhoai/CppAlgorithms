#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

/**
 * Make Road
 *
 * input:
 *      1 ≤ n ≤ 10^5
 *      1 ≤ m ≤ 2*10^5
 *      1 ≤ a,b ≤ n
 *
 * output: print pair a: components, b: max components
 *
 * @example
 *      input:
 *          5 3
 *          1 2
 *          1 3
 *          4 5
 *      output:
 *          4 2
 *          3 3
 *          2 3
 */

struct Edge {
    int u;
    int v;
    int w;
};

int n, m, res;
int sz[100001], parent[100001];

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

int Union(int u, int v) {
    u = Find(u);
    v = Find(v);

    if (u == v)
        return 0;

    if (sz[u] < sz[v])
        swap(u, v);

    sz[u] += sz[v];
    parent[v] = u;

    res = max(res, sz[u]);
    return 1;
}

void solve() {
    cin >> n >> m;
    init();

    res = 1;
    int comps = n;
    FOR(i, 0, m) {
        int x, y;
        cin >> x >> y;
        comps -= Union(x, y);
        cout << comps << " " << res << endl;
    }
}

int main() {
    SETUP;
    solve();
    return 0;
}