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
 * Dijsktra's Algorithms
 *
 * d[i] = INF(i: 1 -> n)
 * d[s] = 0
 * while Q not empty
 *      choose vertex have minimum fee
 *      remove in Q
 *      Relaxation d[v] = min(d[v], d[u] + w)
 */

const int maxn = 1001;
int n, m;
vector<pi> adj[maxn];
int d[maxn];

void input() {
    cin >> n >> m;
    FOR(i, 0, m) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].PB(MP(v, w));
        adj[v].PB(MP(u, w));
    }
}

void dijsktra(int s) {
    FOR(i, 1, n) d[i] = INF;
    d[s] = 0;

    priority_queue<pi, vii, greater<pi>> Q;
    Q.push(MP(0, s));

    while (!Q.empty()) {
        pi it = Q.top();
        Q.pop();

        int u = it.S, length = it.F;
        if (length > d[u])
            continue;

        for (pi it : adj[u]) {
            int v = it.F, w = it.S;
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                Q.push(MP(d[v], v));
            }
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
    dijsktra(1);

    return 0;
}
