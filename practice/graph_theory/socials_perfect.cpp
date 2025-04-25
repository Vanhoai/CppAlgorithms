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
 * Socials Perfect
 *
 * input:
 *      N, M
 *      1 <= N,M <= 1000
 *
 * output: YES/NO
 *
 * @example
 *      input:
 *          4 3
 *          1 3
 *          3 4
 *          1 4
 *      output:
 *          YES
 */

int n, m, count_comp;
vector<int> adj[1001];
bool visited[1001];
vector<int> comp;

void input() {
    cin >> n >> m;
    FOR(i, 1, m) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    ms(visited, false);
}

void dfs(int u) {
    comp.push_back(u);
    count_comp++;
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
    int TC;
    cin >> TC;
    while (TC--) {
        input();

        bool ok = true;
        FOR(i, 1, n) {
            count_comp = 0;
            if (!visited[i]) {
                comp.clear();
                dfs(i);
                for (int x : comp) {
                    if (adj[x].size() != count_comp - 1) {
                        ok = false;
                        break;
                    }
                }
            }

            if (!ok)
                break;
        }

        cout << (ok ? "YES" : "NO") << endl;
    }

    return 0;
}
