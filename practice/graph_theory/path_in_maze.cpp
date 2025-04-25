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
 * Path in Maze
 *
 * input:
 *      N, Si, Sj, Ei, Ej
 *      2 <= N <= 1000
 *      0 <= A[i][j] <= 1
 *
 * output: print the minimum distance to reach the end
 *
 * @example
 *      input:
 *          10
 *          9 6 9 3
 *          1 1 0 1 1 1 1 0 0 1
 *          0 0 1 0 0 1 0 1 0 1
 *          1 1 1 1 0 0 0 1 1 0
 *          1 0 0 0 1 0 0 0 1 1
 *          1 0 1 0 0 1 0 1 1 0
 *          0 0 1 1 0 1 0 0 0 0
 *          1 1 0 1 0 1 1 0 0 0
 *          0 0 0 1 1 0 1 1 0 1
 *          1 0 1 0 0 1 0 0 1 1
 *          0 1 1 1 1 0 1 0 1 1
 *      output:
 *          3
 */

const int maxn = 1001;
int A[maxn][maxn], D[maxn][maxn];
int n, si, sk, ei, ek;

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

void input() {
    cin >> n;
    cin >> si >> sk >> ei >> ek;
    FOR(i, 1, n) FOR(k, 1, n) cin >> A[i][k];

    ms(D, 0);
}

void bfs() {
    queue<pi> q;
    q.push(MP(si, sk));
    D[si][sk] = 0;

    while (!q.empty()) {
        pi u = q.front();
        q.pop();
        int x = u.F, y = u.S;
        if (x == ei && y == ek)
            break;

        FOR(i, 0, 8) {
            int ix = x + dx[i], iy = y + dy[i];
            if (ix >= 1 && ix <= n && iy >= 1 && iy <= n && A[ix][iy] == 1) {
                A[ix][iy] = 0;
                q.push(MP(ix, iy));

                D[ix][iy] = D[x][y] + 1;
            }
        }
    }

    cout << D[ei][ek] << endl;
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
