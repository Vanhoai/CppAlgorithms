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

int n, m, parent[DEG];
vector<int> adj[DEG];
bool visited[DEG];

bool bfs(int s) {
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (!visited[v]) {
                q.push(v);
                visited[v] = true;
                parent[v] = u;
            } else if (v != parent[u]) {
                return true;
            }
        }
    }

    return false;
}

void input() {
    cin >> n >> m;
    FOR(i, 0, m) {
        int x, y;
        cin >> x >> y;
        adj[x].PB(y);
        adj[y].PB(x);
    }

    ms(visited, false);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    input();

    bool ok = false;
    FOR(i, 1, n) {
        if (!visited[i] && bfs(i)) {
            ok = true;
            break;
        }
    }

    if (ok)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
