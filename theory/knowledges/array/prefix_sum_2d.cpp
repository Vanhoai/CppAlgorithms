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
 * Prefix Sum 2D
 * pre[i][j] = pre[i - 1][j] + pre[i][j -1] - pre[i - 1][j - 1] + a[i][j]
 *
 * 8 8
 * 1 1 0 0 0 1 1 1
 * 1 0 0 0 1 1 1 1
 * 0 1 1 1 0 0 1 0
 * 1 1 1 1 0 1 1 0
 * 1 1 1 1 1 0 1 1
 * 1 0 0 1 0 1 0 1
 * 0 0 0 0 1 0 1 0
 * 1 1 0 0 0 1 0 1
 * 3
 * 2 3 1 7
 * 2 2 2 7
 * 1 2 1 8
 *
 * 8
 * 3
 * 10
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int TC;
    cin >> TC;
    while (TC--) {
        int n, m;
        cin >> n >> m;
        int a[n + 1][m + 1];
        FOR(i, 1, n) FOR(k, 1, m) cin >> a[i][k];

        int pre[n + 1][m + 1];
        ms(pre, 0);
        FOR(i, 1, n) FOR(k, 1, m) {
            pre[i][k] =
                pre[i][k - 1] + pre[i - 1][k] - pre[i - 1][k - 1] + a[i][k];
        }

        int q;
        cin >> q;
        FOR(i, 0, q) {
            int i1, i2, k1, k2;
            cin >> i1 >> i2 >> k1 >> k2;

            cout << pre[i2][k2] - pre[i1 - 1][k2] - pre[i2][k1 - 1] +
                        pre[i1 - 1][k1 - 1]
                 << endl;
        }
    }

    return 0;
}
