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

const int maxn = 1001;

int n, m;
vii adj[1001];
bool used[1001];

struct Edge {
    int u, v, w;
};

void input() {
    cin >> n >> m;
    FOR(i, 0, m) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].PB(MP(v, w));
        adj[v].PB(MP(u, w));
    }
}

void prim(int s) {
    priority_queue<pi, vii, greater<pi>> Q;
    used[s] = true;

    for (pi v : adj[s]) {
        if (!used[v.F])
            Q.push(MP(v.S, v.F));
    }

    int d = 0, count = 0;
    vector<Edge> edges;

    while (!Q.empty()) {
        pi e = Q.top();
        Q.pop();
        int u = e.S, w = e.F;

        if (!used[u]) {
            count++;
            d += w;
            used[u] = true;

            for (pi v : adj[u]) {
                if (!used[v.F])
                    Q.push(MP(v.S, v.F));
            }
        }
    }

    cout << d << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    input();
    prim(1);

    return 0;
}
