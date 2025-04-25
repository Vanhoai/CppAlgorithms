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
 * Max Group Friend
 *
 * input:
 *      N, M
 *      1 <= N <= 1000
 *      0 <= M <= N*(N-1)/2
 *      1 <= U, V <= N;
 *
 * output: print the number of members max in a group
 *
 * @example
 *      input:
 *          10 6
 *          8 2
 *          4 1
 *          8 6
 *          8 7
 *          8 1
 *          8 5
 *      output:
 *          7
 */

int n, m;
vector<int> adj[DEG];
bool visited[DEG];
int comps;

void input() {
    cin >> n >> m;
    FOR(i, 1, m) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}

void dfs(int u) {
    comps++;
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v])
            dfs(v);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    input();

    int ans = -1e9;
    FOR(i, 1, n) {
        if (!visited[i]) {
            comps = 0;
            dfs(i);
            ans = max(ans, comps);
        }
    }

    cout << ans << endl;
    return 0;
}
