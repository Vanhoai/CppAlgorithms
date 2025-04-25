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
 * Prefix Prefix
 *
 * input:
 *      1<=N,M,K<=10^5
 *      0<=A[i]<=10^5
 *      1<=L,R<=N, 0<=D<=10^5
 *      1<=x,y<=M
 *
 * output: print array after k operation
 *
 * @example
 *      input:
 *          6 5 2
 *          1 7 5 2 8 7
 *          2 6 5
 *          1 5 1
 *          1 6 1
 *          2 6 4
 *          2 5 4
 *          2 5
 *          2 4
 *
 *      output:
 *          5 23 21 18 24 17
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m, k;
    cin >> n >> m >> k;
    int a[n + 1];
    FOR(i, 1, n) cin >> a[i];

    vector<int> q[m + 1];
    FOR(i, 1, m) {
        int x, y, w;
        cin >> x >> y >> w;
        q[i].push_back(x);
        q[i].push_back(y);
        q[i].push_back(w);
    }

    int d[n + 1];
    d[1] = a[1];
    FOR(i, 2, n) d[i] = a[i] - a[i - 1];

    while (k--) {
        int r1, r2;
        cin >> r1 >> r2;
        FOR(i, r1, r2) {
            int x = q[i][0];
            int y = q[i][1];
            int w = q[i][2];

            d[x] += w;
            d[y + 1] -= w;
        }
    }

    a[1] = d[1];
    FOR(i, 2, n) a[i] = a[i - 1] + d[i];
    FOR(i, 1, n) cout << a[i] << " ";
    cout << endl;

    return 0;
}
