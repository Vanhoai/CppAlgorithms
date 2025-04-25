#include <iostream>
using namespace std;

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
 *  Merge two array
 *
 * input:
 *      T, N, M, A[i]
 *      1 ≤ T ≤ 100
 *      1 ≤ n, m ≤ 10^6
 *      -10^9 ≤ A[i], B[i] ≤ 10^9
 *
 * output: print array after merge
 *
 * @example
 *      input:
 *          1
 *          3 4
 *          1 2 3
 *          1 5 6 2
 *      output:
 *          1 1 2 2 3 5 6
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
        ll a[n], b[m];

        FOR(i, 0, n) cin >> a[i];
        FOR(i, 0, m) cin >> b[i];

        sort(a, a + n);
        sort(b, b + m);

        ll res[n + m];
        int k = 0;

        int i = 0, j = 0;
        while (i < n && j < m) {
            if (a[i] <= b[j])
                res[k++] = a[i++];
            else
                res[k++] = b[j++];
        }

        while (i < n)
            res[k++] = a[i++];

        while (j < m)
            res[k++] = b[j++];

        FOR(e, 0, k) cout << res[e] << " ";
        cout << endl;
    }

    return 0;
}
