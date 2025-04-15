#include <iostream>
#include <vector>
using namespace std;

#define FOR(i, a, b)  for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= b; --i)

vector<vector<int>> adj;
vector<int> colors;
int d[5] = {0, 0, 0, 0, 0};

void dfs(int u, int prev) {
    memset(d, 0, sizeof(d));
    d[prev] = 1;

    for (int v : adj[u]) {
        if (colors[v] != 0)
            d[colors[v]] = 1;
    }

    for (int i = 1; i <= 4; i++) {
        if (d[i] == 0) {
            colors[u] = i;
            break;
        }
    }

    for (int v : adj[u]) {
        if (colors[v] == 0)
            dfs(v, colors[u]);
    }
}

vector<int> gardenNoAdj(int n, vector<vector<int>> &paths) {
    adj.clear();
    colors.clear();

    adj.resize(n + 1);
    colors.resize(n + 1);

    for (int i = 0; i < paths.size(); i++) {
        int u = paths[i][0];
        int v = paths[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        if (colors[i] == 0)
            dfs(i, 0);
    }

    vector<int> ans;
    for (int i = 1; i <= n; i++)
        ans.push_back(colors[i]);

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
        vector<vector<int>> paths(m);
        FOR(i, 0, m - 1) {
            vector<int> v(2);
            cin >> v[0] >> v[1];
            paths[i] = v;
        }

        vector<int> ans = gardenNoAdj(n, paths);
        FOR(i, 0, ans.size() - 1) cout << ans[i] << " ";
        cout << endl;
    }

    return 0;
}
