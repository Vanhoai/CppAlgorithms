#include <iostream>
#include <vector>
using namespace std;

#define FOR(i, a, b)  for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= b; --i)

typedef vector<int> vi;
typedef vector<vector<int>> vvi;

vvi adj;
vector<bool> visited;

void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v])
            dfs(v);
    }
}

int comps(int n) {
    int count = 0;
    FOR(i, 0, n - 1) {
        if (!visited[i]) {
            count++;
            dfs(i);
        }
    }

    return count;
}

int makeConnected(int n, vvi &connections) {
    if (connections.size() < n - 1)
        return -1;

    adj.resize(n);
    visited.resize(n);

    FOR(i, 0, connections.size() - 1) {
        int u = connections[i][0];
        int v = connections[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    FOR(i, 0, n - 1) visited[i] = false;
    int ccs = comps(n);

    return ccs - 1;
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

        cout << makeConnected(n, edges) << endl;
    }

    return 0;
}
