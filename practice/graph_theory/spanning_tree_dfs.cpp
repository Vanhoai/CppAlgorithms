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
 * Spanning Tree DFS
 *
 * input:
 *      N, M, s
 *      1 <= s <= n <= 1000
 *      1 <= m <= n*(n - 1)/2
 *
 * output: print all edge in spanning tree
 *
 * @example
 *      input:
 *          9 18 4
 *          9 3
 *          5 4
 *          5 1
 *          5 2
 *          7 5
 *          4 3
 *          8 5
 *          4 2
 *          2 1
 *          9 4
 *          7 2
 *          8 6
 *          9 7
 *          4 1
 *          6 1
 *          9 1
 *          6 3
 *          7 1
 *      output:
 *          4->1
 *          4->2
 *          4->3
 *          4->5
 *          4->9
 *          1->6
 *          1->7
 *          5->8
 */

int n, m, s;
vector<int> adj[1001];
bool visited[1001];

void input() {
    cin >> n >> m >> s;
    FOR(i, 0, m) {
        int x, y;
        cin >> x >> y;
        adj[x].PB(y);
        adj[y].PB(x);
    }

    FOR(i, 1, n) sort(all(adj[i]));
    ms(visited, false);
}

void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            cout << u << "->" << v << endl;
            dfs(v);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    input();
    dfs(s);

    return 0;
}
