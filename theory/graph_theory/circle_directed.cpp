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

int n, m, colors[DEG], in[DEG];
vector<int> adj[DEG];

void input() {
    cin >> n >> m;
    FOR(i, 0, m) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        in[v]++;
    }

    ms(colors, 0);
}

bool dfs(int u, int p) {
    colors[u] = 1;
    for (int v : adj[u]) {
        if (colors[v] == 0) {
            if (dfs(v, u))
                return true;
        } else if (colors[v] == 1)
            return true;
    }

    colors[u] = 2;
    return false;
}

bool kahn() {
    queue<int> q;
    FOR(i, 1, n) if (in[i] == 0) q.push(i);

    int count = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        count++;

        for (int v : adj[u]) {
            in[v]--;
            if (in[v] == 0)
                q.push(v);
        }
    }

    return count != n;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    input();

    bool check = false;
    FOR(i, 1, n) {
        if (colors[i] == 0 && dfs(i, 0)) {
            check = true;
            break;
        }
    }

    if (kahn())
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
