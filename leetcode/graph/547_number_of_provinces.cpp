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

void dfs(int u, vvi &matrix) {
    matrix[u][u] = 0;
    for (int i = 0; i < matrix[u].size(); i++) {
        if (matrix[u][i]) {
            matrix[u][i] = 0;
            matrix[i][u] = 0;
            dfs(i, matrix);
        }
    }
}

int findCircleNum(vvi &isConnected) {
    int count = 0;
    for (int i = 0; i < isConnected.size(); i++) {
        if (isConnected[i][i]) {
            count++;
            dfs(i, isConnected);
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

    int TC;
    cin >> TC;
    while (TC--) {
        int n;
        cin >> n;
        vvi matrix(n, vi(n));
        FOR(i, 0, n - 1) FOR(k, 0, n - 1) cin >> matrix[i][k];
        cout << findCircleNum(matrix) << endl;
    }

    return 0;
}
