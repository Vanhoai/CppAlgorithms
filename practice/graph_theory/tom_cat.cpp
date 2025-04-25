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
 * Tom Cat
 *
 * input:
 *      N, M
 *      2 <= N <= 1000
 *      1 <= m <= n
 *
 * output: print maximum fish cat can be eat
 *
 * @example
 *      input:
 *          7 1
 *          1 0 1 1 0 0 0
 *          1 2
 *          1 3
 *          2 4
 *          2 5
 *          3 6
 *          3 7
 *      output:
 *          2
 */

int n, s, res, bug[1001];
vector<int> adj[1001];

void input() {
    cin >> n >> s;
    FOR(i, 1, n) cin >> bug[i];
    FOR(i, 0, n - 1) {
        int u, v;
        cin >> u >> v;
        adj[u].PB(v);
        adj[v].PB(u);
    }
}

void dfs(int u, int p, int b) {
    if (bug[u])
        b++;
    else
        b = 0;

    if (b > s)
        return;

    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u, b);
        }
    }

    if (b <= s && adj[u].size() == 1 && u != 1)
        res++;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    input();
    dfs(1, -1, 0);

    cout << res << endl;
    return 0;
}
