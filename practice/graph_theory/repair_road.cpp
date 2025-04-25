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
 * Repair Road
 *
 * input:
 *      1 ≤ n ≤ 10^5
 *      1 ≤ m ≤ 2*10^5
 *      1 ≤ a,b ≤ n
 *      1 ≤ c ≤ 10^9
 *
 * output: print minimum fee repair road
 *
 * @example
 *      input:
 *          5 6
 *          1 2 3
 *          2 3 5
 *          2 4 2
 *          3 4 8
 *          5 1 7
 *          5 4 4
 *      output:
 *          14
 */

struct Edge {
    int u;
    int v;
    int w;
};

int n, m, sz[1001], parent[1001];
vector<Edge> adj;

int Find(int u) {
    if (u == parent[u])
        return u;

    return parent[u] = Find(parent[u]);
}

bool Union(int u, int v) {
    u = Find(u);
    v = Find(v);

    if (u == v)
        return false;

    if (sz[u] < sz[v])
        swap(u, v);

    sz[u] += sz[v];
    parent[v] = u;

    return true;
}

void input() {
    cin >> n >> m;
    FOR(i, 0, m) {
        int u, v, w;
        cin >> u >> v >> w;
        adj.PB((Edge) {u, v, w});
    }

    FOR(i, 1, n) {
        sz[i] = 1;
        parent[i] = i;
    }
}

bool cmp(Edge a, Edge b) { return a.w < b.w; }

void kruskal() {
    sort(all(adj), cmp);
    ll ans = 0;
    int count = 0;

    FOR(i, 0, m) {
        if (count == n - 1)
            break;

        if (Union(adj[i].u, adj[i].v)) {
            count++;
            ans += adj[i].w;
        }
    }

    if (count != n - 1)
        cout << "IMPOSSIBLE";
    else
        cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    input();
    kruskal();

    return 0;
}
