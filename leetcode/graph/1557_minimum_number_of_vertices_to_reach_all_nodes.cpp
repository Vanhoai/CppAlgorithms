#include <iostream>
#include <vector>
using namespace std;

#define FOR(i, a, b)  for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= b; --i)

typedef vector<int> vi;
typedef vector<vi> vvi;

vector<vector<int>> adj;
vector<bool> visited;

vi findSmallestSetOfVertices(int n, vvi &edges) {
    vi indegrees(n);
    for (int i = 0; i < edges.size(); i++) {
        int v = edges[i][1];
        indegrees[v]++;
    }

    vi v;
    for (int i = 0; i < n; i++) {
        if (indegrees[i] == 0)
            v.push_back(i);
    }

    return v;
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

        vector<int> res = findSmallestSetOfVertices(n, edges);
        FOR(i, 0, res.size() - 1) cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}
