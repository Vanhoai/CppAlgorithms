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
 * Move in Maze 2
 *
 * input:
 *      T, N, A(i)(j)
 *      1 ≤ T ≤ 10
 *      2 ≤ N ≤ 8
 *      0 ≤ A(i)(j) ≤ 1
 *
 * output: print all way move from (1, 1) to (n, n)
 *
 * @example
 *      input:
 *          3
 *          4
 *          1 0 0 0
 *          1 1 0 1
 *          0 1 0 0
 *          0 1 1 1
 *          4
 *          1 0 0 0
 *          1 1 0 1
 *          1 1 0 0
 *          0 1 1 1
 *          5
 *          1 0 0 0 0
 *          1 1 1 1 1
 *          1 1 1 0 1
 *          0 0 0 0 1
 *          0 0 0 0 1
 *      output:
 *          DRDDRR
 *          DDRDRR DRDDRR
 *          DDRRURRDDD DDRURRRDDD DRDRURRDDD DRRRRDDD
 */

const int maxn = 100;
int n, ok, A[maxn][maxn];

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, -1, 1, 0};
string direction = "DLRU";

void input() {
    cin >> n;
    FOR(i, 1, n) FOR(j, 1, n) cin >> A[i][j];
}

void backtracking(int i, int j, string path) {
    if (i == n && j == n) {
        ok = 1;
        cout << path << " ";
        return;
    }

    for (int k = 0; k < 4; k++) {
        int ix = i + dx[k];
        int jy = j + dy[k];

        if (ix >= 1 && ix <= n && jy >= 1 && jy <= n && A[ix][jy]) {
            A[ix][jy] = 0;
            backtracking(ix, jy, path + direction[k]);
            A[ix][jy] = 1;
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
        backtracking(1, 1, "");
        if (!ok)
            cout << "-1\n";
        else
            cout << endl;
    }

    return 0;
}
