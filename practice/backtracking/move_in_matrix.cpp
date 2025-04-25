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
 * Move in matrix
 *
 * input:
 *      T, M, N, A[i][j]
 *      1 ≤ T ≤ 10; 1 ≤ M, N, A[i][j] ≤ 100
 *
 * output: print the number of path from A[0][0] -> A[n - 1][n - 1]
 *
 * @example
 *      input:
 *          2
 *          2 3
 *          1 2 3
 *          4 5 6
 *          2 2
 *          1 2
 *          3 4
 *      output:
 *          3
 *          2
 */

const int maxn = 100;
int n, m, ans, a[maxn + 1][maxn + 1];

void input() {
    cin >> n >> m;
    FOR(i, 1, n) FOR(j, 1, m) cin >> a[i][j];
}

void backtracking(int i, int j) {
    if (i == n && j == m)
        ans++;

    if (i + 1 <= n)
        backtracking(i + 1, j);

    if (j + 1 <= m)
        backtracking(i, j + 1);
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
        ans = 0;
        backtracking(1, 1);
        cout << ans << endl;
    }

    return 0;
}
