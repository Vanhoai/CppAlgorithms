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
 * Meeting
 *
 * input:
 *      N, M, K
 *      1 ≤ K ≤ 100
 *      1 ≤ N ≤ 1,000
 *      1 ≤ M ≤ 10,000
 *
 * output: print the number of location can meeting
 *
 * @example
 *      input:
 *          4 10 15
 *          1
 *          4
 *          5
 *          7
 *          10 3
 *          5 6
 *          4 9
 *          5 3
 *          8 6
 *          4 6
 *          8 9
 *          3 9
 *          1 9
 *          6 9
 *          7 9
 *          9 6
 *          7 3
 *          2 9
 *          5 9
 *      output:
 *          2
 */

int n, m, k;
vector<int> positions;
vector<int> adj[1001];
bool visited[1001];
int counts[1001];

void input() {
    cin >> k >> n >> m;
    FOR(i, 0, k) {
        int x;
        cin >> x;
        positions.PB(x);
    }

    FOR(i, 0, m) {
        int u, v;
        cin >> u >> v;
        adj[u].PB(v);
    }

    ms(visited, false);
}

void dfs(int u) {
    visited[u] = true;
    counts[u]++;
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
    int TC;
    cin >> TC;
    while (TC--) {
        input();
        ms(counts, 0);

        for (int u : positions) {
            ms(visited, false);
            dfs(u);
        }

        vi v;
        FOR(i, 1, n) {
            if (counts[i] == k)
                v.PB(i);
        }

        cout << v.size() << endl;
        FOR(i, 0, sz(v)) cout << v[i] << " ";
        cout << endl;
    }

    return 0;
}
