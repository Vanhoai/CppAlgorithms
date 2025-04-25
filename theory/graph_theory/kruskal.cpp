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

struct Edge {
    int u;
    int v;
    int w;
};

int n, m;
int sz[100001], parent[100001];
vector<Edge> edges;

void init() {
    FOR(i, 1, n) {
        sz[i] = 1;
        parent[i] = i;
    }
}

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

    if (sz[u] > sz[v]) {
        parent[v] = u;
        sz[u] += sz[v];
    } else {
        parent[u] = v;
        sz[v] += sz[u];
    }

    return true;
}

void input() {
    cin >> n >> m;
    FOR(i, 0, m) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.PB((Edge) {u, v, w});
    }
}

void kruskal() {
    sort(all(edges), [](Edge a, Edge b) -> bool { return a.w < b.w; });
    int d = 0;

    vector<Edge> mst;
    FOR(i, 0, m) {
        if (mst.size() == n - 1)
            break;

        Edge e = edges[i];
        if (Union(e.u, e.v)) {
            mst.PB(e);
            d += e.w;
        }
    }

    cout << d << endl;
    for (auto it : mst)
        cout << it.u << "->" << it.v << ": " << it.w << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    input();
    init();
    kruskal();

    return 0;
}
