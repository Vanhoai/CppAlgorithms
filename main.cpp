#include <iostream>
#include <vector>
using namespace std;

#define FOR(i, a, b)  for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= b; --i)

typedef vector<int> vi;
typedef vector<vi> vvi;

vvi allPathsSourceTarget(vvi &graph) {
    vi path;
    path.push_back(0);

    vvi paths;

    queue<vi> q;
    q.push(path);

    while (!q.empty()) {
        vi path = q.front();
        q.pop();

        int u = path.back();
        if (u == graph.size() - 1)
            paths.push_back(path);
        else {
            for (int v : graph[u]) {
                path.push_back(v);
                q.push(path);
                path.pop_back();
            }
        }
    }

    return paths;
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

        vvi graph(n, vi());
        FOR(i, 0, m - 1) {
            int u = edges[i][0];
            int v = edges[i][1];
            graph[u].push_back(v);
        }

        vvi paths = allPathsSourceTarget(graph);
        for (auto &path : paths) {
            for (int node : path)
                cout << node << " ";
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
