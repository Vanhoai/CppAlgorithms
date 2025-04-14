#include <iostream>
#include <set>
#include <vector>
using namespace std;

#define FOR(i, a, b)  for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= b; --i)

vector<vector<int>> adj;
vector<bool> visited;
vector<int> parents;

bool dfs(int u, int p, int &s, int &e) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            parents[v] = u;
            if (dfs(v, u, s, e))
                return true;
        } else if (v != p) {
            s = v;
            e = u;
            return true;
        }
    }

    return false;
}

vector<int> findRedundantConnection(vector<vector<int>> &edges) {
    adj.clear();
    visited.clear();
    parents.clear();

    adj.resize(edges.size() + 1);
    visited.resize(edges.size() + 1);
    parents.resize(edges.size() + 1);

    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int s, e;
    dfs(1, 0, s, e);
    set<pair<int, int>> paths;
    int end = e;
    while (s != e) {
        paths.insert({parents[e], e});
        e = parents[e];
    }
    paths.insert({s, end});

    for (int i = edges.size() - 1; i >= 0; i--) {
        int u = edges[i][0];
        int v = edges[i][1];

        if (paths.find({u, v}) != paths.end() ||
            paths.find({v, u}) != paths.end())
            return {u, v};
    }

    return {0, 1};
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
        vector<vector<int>> edges;
        for (int i = 0; i < m; i++) {
            vector<int> v(2);
            cin >> v[0] >> v[1];
            edges.push_back(v);
        }

        vector<int> ans = findRedundantConnection(edges);
        FOR(i, 0, ans.size() - 1) cout << ans[i] << " ";
        cout << endl;
    }

    return 0;
}
