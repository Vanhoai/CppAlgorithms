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
 * Min Expression Multiply
 *
 * input:
 *      T, N, A[i]
 *      1 ≤ T ≤ 100
 *      1 ≤ N ≤ 10^7
 *      0 ≤ A[i], B[i] ≤ 10^18
 *
 * output: print min expression
 *
 *      P(min) = A[i] * B[i] (i: 0 -> n - 1)
 *
 * @example
 *      input:
 *          2
 *          7
 *          1 6 3 4 5 2 7
 *          1 1 1 2 3 4 3
 *          7
 *          1 6 3 5 5 2 2
 *          0 1 9 0 1 2 3
 *      output:
 *          45
 *          27
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
        int n;
        cin >> n;
        ll a[n], b[n];

        FOR(i, 0, n) cin >> a[i];
        FOR(i, 0, n) cin >> b[i];

        sort(a, a + n);
        sort(b, b + n, greater<int>());

        ll res = 0;
        FOR(i, 0, n) res += a[i] * b[i];

        cout << res << endl;
    }

    return 0;
}
