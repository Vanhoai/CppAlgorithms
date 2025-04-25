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
 * Prefix Sum in Matrix 2D
 *
 * input:
 *      1<=N,M<=1000
 *      1<=Q<=10^5
 *      1<=x1,x2<=N, 1<=y1,y2<=M
 *
 * output: print sum of query from L to R
 *
 * @example
 *      input:
 *          8 8
 *          1 1 0 0 0 1 1 1
 *          1 0 0 0 1 1 1 1
 *          0 1 1 1 0 0 1 0
 *          1 1 1 1 0 1 1 0
 *          1 1 1 1 1 0 1 1
 *          1 0 0 1 0 1 0 1
 *          0 0 0 0 1 0 1 0
 *          1 1 0 0 0 1 0 1
 *          3
 *          2 3 1 7 // x1, x2, y1, y2
 *          2 2 2 7
 *          1 2 1 8
 *      output:
 *          8
 *          3
 *          10
 */

const int maxn = 1001;
int A[maxn][maxn], Q[maxn][maxn];

void build() {
    int n, m;
    cin >> n >> m;
    FOR(i, 1, n) FOR(k, 1, m) cin >> A[i][k];

    memset(Q, 0, sizeof(Q));
    FOR(i, 1, n) FOR(k, 1, m) {
        Q[i][k] = Q[i - 1][k] + Q[i][k - 1] - Q[i - 1][k - 1] + A[i][k];
    }
}

void query() {
    int q;
    cin >> q;
    while (q--) {
        int x1, x2, y1, y2;
        cin >> x1 >> x2 >> y1 >> y2;
        int res = Q[x2][y2] - Q[x1 - 1][y2] - Q[x2][y1 - 1] + Q[x1 - 1][y1 - 1];
        cout << res << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    build();
    query();

    return 0;
}
