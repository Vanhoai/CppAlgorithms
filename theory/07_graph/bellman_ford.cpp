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
 * Bellman Ford
 *
 * d[i] = INF(i: 1 -> n)
 * d[s] = 0
 * Loop n - 1 th
 *      Loop all edge in graph
 *      Relaxation
 */

struct Edge {
    int u;
    int v;
    int w;
};

int n, m, d[1001];
vector<Edge> edges;

void input() {
    cin >> n >> m;
    FOR(i, 0, m) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.PB((Edge) {u, v, w});
    }
}

void bellman_ford(int s) {
    FOR(i, 1, n) d[i] = INF;
    d[s] = 0;

    FOR(i, 0, n - 1) {
        FOR(k, 0, m) {
            Edge tmp = edges[k];
            int u = tmp.u, v = tmp.v, w = tmp.w;

            if (d[u] < INF)
                d[v] = min(d[v], d[u] + w);
        }
    }

    FOR(i, 1, n) cout << d[i] << " ";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    input();
    bellman_ford(1);

    return 0;
}
