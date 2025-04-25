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
 * Max Total
 *
 * input:
 *      N, Q, L, R, A[i]
 *      1<=N<=10^6
 *      1<=Q<=10^5
 *      0<=L<=R<=N-1
 *      0<=A[i],K<=1000
 *
 * output: print max total sum in L, R in all Q query
 *
 * @example
 *      input:
 *          6 2
 *          5 2 5 3 5 1
 *          2 5
 *          2 4
 *      output:
 *          33
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

    int d[n + 5];
    ms(d, 0);

    while (q--) {
        int L, R;
        cin >> L >> R;

        L--;
        R--;

        d[L] += 1;
        d[R + 1] -= 1;
    }

    int F[n];
    F[0] = d[0];
    FOR(i, 1, n) F[i] = F[i - 1] + d[i];

    sort(F, F + n, greater<int>());
    sort(a, a + n, greater<int>());

    ll res = 0;
    FOR(i, 0, n) res += 1LL * a[i] * F[i];
    cout << res << endl;

    return 0;
}
