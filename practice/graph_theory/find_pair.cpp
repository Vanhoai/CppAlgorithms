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
 * Find Pair
 *
 * input:
 *      N
 *      2 <= N <= 1000
 *
 * output: print all leader each group
 *
 * @example
 *      input:
 *          10
 *          9 10
 *          5 9
 *          7 4
 *          4 5
 *          2 3
 *          6 7
 *          7 8
 *          3 6
 *          1 2
 *      output:
 *          51
 */

int n, child[1001];
vector<int> adj[1001];
bool visited[1001];

void input() {
    cin >> n;
    FOR(i, 1, n - 1) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}

int dfs(int u, int p) {
    int count = 1;
    for (int v : adj[u]) {
        if (v != p)
            count += dfs(v, u);
    }

    child[u] = count;
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    input();
    dfs(1, -1);

    int ans = 0;
    FOR(i, 1, n) ans += child[i];
    cout << ans;

    return 0;
}
