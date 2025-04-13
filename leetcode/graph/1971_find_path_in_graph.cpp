#include <iostream>
#include <vector>
using namespace std;

#define FOR(i, a, b)  for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= b; --i)

bool validPath(int n, vector<vector<int>> &edges, int source, int destination) {
    vector<vector<int>> adj(n, vector<int>());
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool visited[n];
    memset(visited, false, sizeof(visited));

    queue<int> q;
    q.push(source);
    visited[source] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (u == destination)
            break;

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }

    return visited[destination];
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
        int n, m, s, e;
        cin >> n >> m >> s >> e;
        vector<vector<int>> edges;
        for (int i = 0; i < m; i++) {
            vector<int> x(2);
            cin >> x[0];
            cin >> x[1];
            edges.push_back(x);
        }

        cout << validPath(n, edges, s, e) << endl;
    }

    return 0;
}
