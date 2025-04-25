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
 * Count Room
 *
 * input:
 *      T, N, M
 *      1 <= T <= 50
 *      1 <= N <= 1000
 *
 * output: print the number of rooms
 *
 * @example
 *      input:
 *          2
 *          6 6
 *          ..###.
 *          ...#..
 *          #..#..
 *          .##.#.
 *          ######
 *          .#.##.
 *          6 6
 *          ####.#
 *          .#..##
 *          .#..##
 *          ####..
 *          #...##
 *          .##..#
 *      output:
 *          7
 *          6
 */

int n, m;
char A[1001][1001];

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void input() {
    cin >> n >> m;
    FOR(i, 1, n) FOR(k, 1, m) cin >> A[i][k];
}

void dfs(int u, int v) {
    A[u][v] = '#';
    FOR(i, 0, 4) {
        int ix = u + dx[i], iy = v + dy[i];
        if (ix >= 1 && ix <= n && iy >= 1 && iy <= m && A[ix][iy] == '.')
            dfs(ix, iy);
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
        int count = 0;
        FOR(i, 1, n) FOR(j, 1, m) {
            if (A[i][j] == '.') {
                count++;
                dfs(i, j);
            }
        }

        cout << count << endl;
    }

    return 0;
}
