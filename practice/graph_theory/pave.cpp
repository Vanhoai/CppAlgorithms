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
 * Make Road
 *
 * input:
 *      1 ≤ n ≤ 10^5
 *      1 ≤ m ≤ 2*10^5
 *      1 ≤ a,b ≤ n
 *
 * output: print pair a: components, b: max components
 *
 * @example
 *      input:
 *          5 3
 *          1 2
 *          1 3
 *          4 5
 *      output:
 *          4 2
 *          3 3
 *          2 3
 */

struct Edge {
    int u;
    int v;
    int w;
};

int n, m, res;
int sz[100001], parent[100001];

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

int Union(int u, int v) {
    u = Find(u);
    v = Find(v);

    if (u == v)
        return 0;

    if (sz[u] < sz[v])
        swap(u, v);

    sz[u] += sz[v];
    parent[v] = u;

    res = max(res, sz[u]);
    return 1;
}

void solve() {
    cin >> n >> m;
    init();

    res = 1;
    int comps = n;
    FOR(i, 0, m) {
        int x, y;
        cin >> x >> y;
        comps -= Union(x, y);
        cout << comps << " " << res << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    solve();
    return 0;
}
