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

const int MAXN = 1001;
int n;
int a[MAXN][MAXN];

void input() {
    cin >> n;
    ms(a, 0);
    FOR(i, 1, n) FOR(j, 1, n) cin >> a[i][j];
}

void solve() {
    FOR(j, 2, n) {
        FOR(i, 1, n) {
            int mx = max(a[i][j - 1], max(a[i - 1][j - 1], a[i + 1][j - 1]));
            a[i][j] = mx + a[i][j];
        }
    }

    int mx = 0;
    FOR(i, 1, n) mx = max(mx, a[i][n]);
    cout << mx << endl;
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
        solve();
    }

    return 0;
}
