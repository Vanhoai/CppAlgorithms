#include <iostream>
#include <set>
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

int n, m;
vector<int> adj[1001];
bool visited[1001];
set<int> a[1001];
vii edges;

void input() {
    cin >> n >> m;
    FOR(i, 1, m) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);

        a[x].insert(y);
        a[y].insert(x);

        edges.push_back(MP(x, y));
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

void vertex() {
    ms(visited, false);
    int comps = components();

    FOR(i, 1, n) {
        ms(visited, false);
        visited[i] = true;

        if (components() < comps) {
            cout << i << " ";
        }
    }
}

void bridge() {
    int coms = components();

    int count = 0;
    vii res;

    for (auto e : edges) {
        int u = e.F, v = e.S;
        a[u].erase(v);
        a[v].erase(u);

        ms(visited, false);
        if (components() < coms) {
            count++;
            res.PB(MP(u, v));
        }

        a[u].insert(v);
        a[v].insert(u);
    }

    cout << count << endl;
    for (auto it : res)
        cout << it.F << " " << it.S << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    input();

    return 0;
}
