#include <iostream>
using namespace std;

#define ms(s, n)      memset(s, n, sizeof(s))
#define all(a)        a.begin(), a.end()
#define sz(a)         int((a).size())
#define FOR(i, a, b)  for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= b; --i)

#define PB push_back
#define MP make_pair
#define F  first
#define S  second

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
typedef vector<vi> vvi;

const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9 + 1;
const int DEG = (int) 10001;

inline ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
inline ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

/**
 * 2
 * 5
 * 1 2
 * 1 3
 * 2 4
 * 2 5
 * 4
 * 1 2
 * 2 3
 * 3 4
 *
 * 1 3
 * 1 2 4
 * 1 2 5
 * 1 2 3 4
 */

int n, parent[1001];
vector<int> adj[1001];
vector<int> leafs;
bool visited[1001];

void input() {
    cin >> n;
    FOR(i, 0, n - 1) {
        int u, v;
        cin >> u >> v;
        adj[u].PB(v);
        adj[v].PB(u);
    }

    FOR(i, 2, n) if (adj[i].size() == 1) leafs.PB(i);
    ms(visited, false);
}

void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            parent[v] = u;
            dfs(v);
        }
    }
}

void path(int u, int v) {
    vector<int> p;
    while (u != v) {
        p.PB(v);
        v = parent[v];
    }

    p.PB(u);
    reverse(all(p));
    FOR(i, 0, sz(p)) cout << p[i] << " ";
    cout << endl;
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
        input();
        ms(visited, false);
        dfs(1);

        FOR(i, 0, sz(leafs) - 1) path(1, leafs[i]);
        FOR(i, 1, n) adj[i].clear();
        leafs.clear();
    }

    return 0;
}
