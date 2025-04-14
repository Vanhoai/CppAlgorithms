#include <iostream>
#include <vector>
using namespace std;

#define FOR(i, a, b)  for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= b; --i)

int findJudge(int n, vector<vector<int>> &trust) {
    vector<int> in_degree(n + 1);
    vector<int> out_degree(n + 1);

    for (int i = 0; i < trust.size(); i++) {
        int u = trust[i][0];
        int v = trust[i][1];

        in_degree[v]++;
        out_degree[u]++;
    }

    for (int i = 1; i <= n; i++) {
        if (in_degree[i] == n - 1 && out_degree[i] == 0)
            return i;
    }

    return -1;
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

        cout << findJudge(n, edges) << endl;
    }

    return 0;
}
