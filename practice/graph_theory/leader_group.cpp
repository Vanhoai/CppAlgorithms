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
 * Leader Group
 *
 * input:
 *      N, M
 *      1 <= N <= 1000
 *      0 <= M <= N*(N-1)/2
 *      1 <= U, V <= N;
 *
 * output: print all leader each group
 *
 * @example
 *      input:
 *          10 6
 *          4 3
 *          4 1
 *          8 5
 *          8 6
 *          4 2
 *          8 2
 *      output:
 *          4 7 9 10
 */

int n, m;
vector<int> adj[DEG];
bool visited[DEG];
vector<int> comps;

void input() {
    cin >> n >> m;
    FOR(i, 1, m) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    ms(visited, false);
    FOR(i, 1, n) sort(all(adj[i]));
}

void dfs(int u) {
    comps.PB(u);
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

    vector<int> ans;

    FOR(i, 1, n) {
        if (!visited[i]) {
            comps.clear();
            dfs(i);

            int res = i;
            int max = 0;
            sort(all(comps));
            for (int x : comps) {
                if (adj[x].size() > max) {
                    res = x;
                    max = adj[x].size();
                }
            }

            ans.PB(res);
        }
    }

    sort(all(ans));
    FOR(i, 0, sz(ans)) cout << ans[i] << " ";

    return 0;
}
