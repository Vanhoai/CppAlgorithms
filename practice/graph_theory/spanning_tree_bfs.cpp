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
 * Spanning Tree BFS
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
 *          7 12 3
 *          6 3
 *          6 2
 *          5 3
 *          5 4
 *          7 3
 *          5 2
 *          7 1
 *          4 3
 *          2 1
 *          6 4
 *          7 2
 *          3 2
 *      output:
 *          3->2
 *          2->1
 *          1->7
 *          2->5
 *          5->4
 *          4->6
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

void bfs() {
    queue<int> q;
    q.push(s);
    visited[s] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (!visited[v]) {
                cout << u << "->" << v << endl;
                q.push(v);
                visited[v] = true;
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

    input();
    bfs();

    return 0;
}
