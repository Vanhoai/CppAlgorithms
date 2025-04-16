#include <iostream>
#include <vector>
using namespace std;

#define FOR(i, a, b)  for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= b; --i)

typedef vector<int> vi;
typedef vector<vi> vvi;

int timer = 0;
vvi adj;
vector<bool> visited;
vector<int> disc, low, ap;

void convert(int n, vvi &edges) {
    adj.resize(n);
    visited.resize(n);
    disc.resize(n);
    low.resize(n);
    ap.resize(n);

    FOR(i, 0, edges.size() - 1) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void dfs(int u, int p, vvi &edges) {
    visited[u] = true;
    disc[u] = low[u] = ++timer;

    for (int v : adj[u]) {
        if (v == p)
            continue;

        if (!visited[v]) {
            dfs(v, u, edges);
            low[u] = min(low[u], low[v]);

            if (p != -1 && disc[u] < low[v]) {
                vi es(2);
                es[0] = u;
                es[1] = v;
                edges.push_back(es);
            }
        } else {
            low[u] = min(low[u], disc[v]);
        }
    }
}

vvi criticalConnections(int n, vvi &connections) {
    convert(n, connections);
    FOR(i, 0, n - 1) visited[i] = false;

    vvi ans;
    timer = 0;

    FOR(i, 0, n - 1) {
        if (!visited[i])
            dfs(i, -1, ans);
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int TC;
    cin >> TC;
    while (TC--) {
        int n, m;
        cin >> n >> m;
        vvi edges(m);

        FOR(i, 0, m - 1) {
            vi v(2);
            cin >> v[0] >> v[1];
            edges[i] = v;
        }

        vvi res = criticalConnections(n, edges);
        for (int i = 0; i < res.size(); i++)
            cout << res[i][0] << " " << res[i][1] << endl;
    }

    return 0;
}
