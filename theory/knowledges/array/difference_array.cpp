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

constexpr int MOD = static_cast<int>(1e9) + 7;
constexpr int INF = static_cast<int>(1e9) + 1;
constexpr int DEG = 10001;

inline ll gcd(const ll a, const ll b) { return b == 0 ? a : gcd(b, a % b); }
inline ll lcm(const ll a, const ll b) { return a / gcd(a, b) * b; }

/**
 * Difference Array
 * d[0] = a[0]
 * d[i] = a[i] - a[i - 1] where i >= 1
 *
 * increate L -> R with K unit
 * -> d[L] += K, d[R + 1] -= K
 *
 * 7 3
 * 8 5 8 9 7 6 9
 * 0 5 0
 * 0 5 0
 * 1 5 1
 *
 * 8 6 9 10 8 7 9
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, q;
    cin >> n >> q;
    int a[n];
    FOR(i, 0, n) cin >> a[i];

    int d[n + 2];
    ms(d, 0);

    d[0] = a[0];
    FOR(i, 1, n) d[i] = a[i] - a[i - 1];

    FOR(i, 0, q) {
        int L, R, K;
        cin >> L >> R >> K;
        d[L] += K;
        d[R + 1] -= K;
    }

    cout << d[0] << " ";
    FOR(i, 1, n) {
        d[i] = d[i] + d[i - 1];
        cout << d[i] << " ";
    }

    return 0;
}
