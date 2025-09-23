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
 * Coin problem
 * 3 10
 * 4 5 8
 *
 * dp[i] = min(dp[i], d[i - a[j]] + 1) where i > a[j]
 */

int dp[1000001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int TC;
    cin >> TC;
    while (TC--) {
        int n, s;
        cin >> n >> s;
        int a[n];
        FOR(i, 0, n) cin >> a[i];

        ms(dp, INF);
        dp[0] = 0;
        FOR(i, 1, s) {
            for (int c : a) {
                if (i >= c)
                    dp[i] = min(dp[i], dp[i - c] + 1);
            }
        }

        if (dp[s] == INF)
            cout << -1 << endl;
        else
            cout << dp[s] << endl;
    }

    return 0;
}
