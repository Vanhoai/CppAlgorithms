#include <iostream>
using namespace std;

#define FOR(i, a, b)  for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= b; --i)

typedef vector<int> vi;
typedef vector<vi> vvi;

int N, M;
vvi adj;
vi degree;
vector<bool> visited;

bool bfs(int s) {
    queue<int> q;
    q.push(s);
    visited[s] = true;

    int cv = 0;
    vector<int> v;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cv++;
        v.push_back(u);

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }

    FOR(i, 0, v.size() - 1) {
        if (degree[v[i]] != cv - 1)
            return false;
    }

    return true;
}

void convert(int n, vvi edges) {
    N = n;
    M = edges.size();

    adj.clear();
    visited.clear();
    degree.clear();

    adj.resize(n, vi());
    visited.resize(n, false);
    degree.resize(n, 0);

    FOR(i, 0, M - 1) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }
}

int countCompleteComponents(int n, vvi &edges) {
    convert(n, edges);

    int count = 0;
    FOR(i, 0, n - 1) {
        if (!visited[i]) {
            if (bfs(i))
                count++;
        }
    }

    return count;
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
        vvi edges(m, vi(2));

        FOR(i, 0, m - 1) cin >> edges[i][0] >> edges[i][1];
        cout << countCompleteComponents(n, edges) << endl;
    }

    return 0;
}
