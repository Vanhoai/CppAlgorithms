#include <iostream>
#include <set>
using namespace std;

#define FOR(i, a, b)  for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= b; --i)

int n, m, degree[1001];
set<int> adj[1001];

void input() {
    cin >> n >> m;
    FOR(i, 0, m - 1) {
        int u, v;
        cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);

        degree[u]++;
        degree[v]++;
    }
}

vector<int> euler(int s) {
    stack<int> st;
    vector<int> ec;

    st.push(s);
    while (!st.empty()) {
        int u = st.top();
        if (!adj[u].empty()) {
            int v = *adj[u].begin();

            st.push(v);
            adj[u].erase(v);
            adj[v].erase(u);
        } else {
            ec.push_back(u);
            st.pop();
        }
    }

    return ec;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    input();
    vector<int> path = euler(1);
    FOR(i, 0, path.size() - 1) cout << path[i] << " ";

    return 0;
}
