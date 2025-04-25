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
 * 2
 * 5
 * 1 2
 * 1 3
 * 2 4
 * 2 5
 * 4
 * 1 2
 * 2 3
 * 3 4
 *
 * 2
 * 3
 */

vector<int> adj[100001];
int d[100001];
bool visited[100001];
int n;

void input() {
    cin >> n;
    FOR(i, 0, n - 1) {
        int u, v;
        cin >> u >> v;
        adj[u].PB(v);
        adj[v].PB(u);
    }

    ms(visited, false);
    ms(d, 0);
}

void bfs(int s) {
    queue<int> q;
    q.push(s);
    visited[s] = true;
    d[s] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (!visited[v]) {
                d[v] = d[u] + 1;
                visited[v] = true;
                q.push(v);
            }
        }
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
        bfs(1);

        cout << *max_element(d + 1, d + n + 1) << endl;
        FOR(i, 1, n) adj[i].clear();
    }

    return 0;
}
