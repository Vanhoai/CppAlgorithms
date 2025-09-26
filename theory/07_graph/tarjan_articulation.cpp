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

int n, m, timer = 0;
vector<int> adj[1001];
bool visited[1001];

vector<pair<int, int>> edges;
int disc[1001], low[1001], ap[1001];

void input() {
    cin >> n >> m;
    FOR(i, 1, m) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    ms(visited, false);
    ms(ap, 0);
}

void dfs_vertex(int u, int p) {
    visited[u] = true;
    disc[u] = low[u] = ++timer;

    int child = 0;
    for (int v : adj[u]) {
        if (v == p)
            continue;
        if (!visited[v]) {
            dfs_vertex(v, u);
            child++;
            low[u] = min(low[u], low[v]);
            if (p != -1 && disc[u] <= low[v])
                ap[u] = true;
        } else
            low[u] = min(low[u], disc[v]);
    }

    if (p == -1 && child > 1)
        ap[u] = true;
}

void dfs_edge(int u, int p) {
    visited[u] = true;
    disc[u] = low[u] = ++timer;

    for (int v : adj[u]) {
        if (v == p)
            continue;
        if (!visited[v]) {
            dfs_edge(v, u);
            low[u] = min(low[u], low[v]);
            if (p != -1 && disc[u] < low[v])
                edges.PB(MP(u, v));
        } else
            low[u] = min(low[u], disc[v]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    input();

    FOR(i, 1, n) {
        if (!visited[i])
            dfs_vertex(i, -1);
    }

    FOR(i, 1, n) {
        if (ap[i])
            cout << i << " ";
    }
    cout << endl;

    ms(visited, false);
    FOR(i, 1, n) {
        if (!visited[i])
            dfs_edge(i, -1);
    }

    for (auto it : edges)
        cout << it.F << " " << it.S << endl;

    return 0;
}
