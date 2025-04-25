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
 * Sunken Island
 *
 * input:
 *      N, M
 *      1 <= N <= 1000
 *      1 <= M <= N*(N-1)/2
 *      1 <= u,v <= N
 *
 * output: print all island which can be sunken
 * and therefore can be disconnected
 *
 * @example
 *      input:
 *          6 8
 *          1 3
 *          6 1
 *          6 3
 *          4 1
 *          6 4
 *          5 2
 *          3 2
 *          3 5
 *      output:
 *          1
 */

int n, m;
vector<int> adj[1001];
bool visited[1001];

void input() {
    cin >> n >> m;
    FOR(i, 0, m) {
        int u, v;
        cin >> u >> v;
        adj[u].PB(v);
        adj[v].PB(u);
    }

    ms(visited, false);
}

void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v])
            dfs(v);
    }
}

int components() {
    int count = 0;
    FOR(i, 1, n) {
        if (!visited[i]) {
            dfs(i);
            count++;
        }
    }

    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    input();

    vi v;
    int cc = components();
    FOR(i, 1, n) {
        ms(visited, false);
        visited[i] = true;
        if (components() > cc)
            v.push_back(i);
    }

    cout << v.size() << endl;
    FOR(i, 0, sz(v)) cout << v[i] << " ";

    return 0;
}
