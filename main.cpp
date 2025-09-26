#include <iostream>
using namespace std;

#define FOR(i, a, b)  for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= b; --i)

#define PB push_back
#define MP make_pair
#define F  first
#define S  second

typedef long long ll;
typedef std::pair<int, int> pi;
typedef std::vector<int> vi;
typedef std::vector<pi> vii;
typedef std::vector<vi> vvi;

constexpr int MOD = static_cast<int>(1e9) + 7;
constexpr int INF = static_cast<int>(1e9) + 1;
constexpr int DEG = 10001;

inline ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
inline ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    vvi a(n + 1, vi(m + 1)), f(n + 1, vi(m + 1));
    FOR(i, 1, n) FOR(j, 1, m) cin >> a[i][j];

    FOR(i, 1, n) FOR(j, 1, m) {
        f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1] + a[i][j];
    }

    FOR(i, 1, n) {
        FOR(j, 1, m) { cout << f[i][j] << " "; }
        cout << endl;
    }

    int q;
    cin >> q;
    while (q--) {
        int i1, j1, i2, j2;
        cin >> i1 >> j1 >> i2 >> j2;

        cout << f[i2][j2] - f[i1 - 1][j2] - f[i2][j1 - 1] + f[i1 - 1][j1 - 1]
             << endl;
    }

    return 0;
}
