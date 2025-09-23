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
 * Kosaraju's Algorithm
 *
 * 1. Topological
 * 2. Make transpose graph
 * 3. Loop in topological order and dfs in transpose graph
 */

int n, m;
vector<int> adj[1001];
vector<int> trans[1001];

bool visited[1001];
stack<int> st;

void input() {
    cin >> n >> m;
    FOR(i, 1, m) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        trans[y].push_back(x);
    }

    ms(visited, false);
}

void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v])
            dfs(v);
    }

    st.push(u);
}

void dfs_trans(int u) {
    visited[u] = true;
    cout << u << " ";
    for (int v : trans[u]) {
        if (!visited[v])
            dfs_trans(v);
    }
}

void kosaraju() {
    ms(visited, false);
    while (!st.empty()) {
        int u = st.top();
        st.pop();

        if (!visited[u]) {
            dfs_trans(u);
            cout << endl;
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

    FOR(i, 1, n) {
        if (!visited[i])
            dfs(i);
    }

    kosaraju();
    return 0;
}
