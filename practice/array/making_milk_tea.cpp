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
 * Making Milk Tea
 *
 * input:
 *      1<=K<=N<=200000
 *      1<=Q<=200000
 *      1<=L,R<=200000
 *
 * output: print the number of cup enough standard serve for customer in range L
 * -> R
 *
 * @example
 *      input: // N, K, Q
 *          5 3 4
 *          2 9
 *          5 8
 *          2 4
 *          2 4
 *          1 6
 *          3 4
 *          5 7
 *          5 8
 *          5 8
 *
 *      output:
 *          2
 *          2
 *          2
 *          2
 */

const int maxn = 200000;
int d[maxn + 1], f[maxn + 1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, k, q;
    cin >> n >> k >> q;
    ms(d, 0);

    while (n--) {
        int L, R;
        cin >> L >> R;
        d[L] += 1;
        d[R + 1] -= 1;
    }

    ms(f, 0);
    f[0] = d[0];
    FOR(i, 1, maxn + 1) f[i] = f[i - 1] + d[i];

    while (q--) {
        int L, R;
        cin >> L >> R;
        int count = 0;
        FOR(i, L, R) if (f[i] >= k) count++;
        cout << count << endl;
    }

    return 0;
}
