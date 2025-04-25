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
 * Divide Two Subset Max Minus
 *
 * input:
 *      T, N, A[i]
 *      1 ≤ T ≤ 100
 *      1 ≤ K < N ≤ 50
 *      0 ≤ A[i] ≤ 1000
 *
 * output: print maximum minus 2 subset (k elements) - (n -k elements)
 *
 * @example
 *      input:
 *          2
 *          5 2
 *          8 4 5 2 10
 *          8 3
 *          1 1 1 1 1 1 1 1
 *      output:
 *          17
 *          2
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
        int n, k;
        cin >> n >> k;
        int a[n];
        FOR(i, 0, n) cin >> a[i];
        sort(a, a + n, greater<int>());

        int mn = n - k;
        if (mn > k)
            swap(mn, k);

        // make sure k > mn
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (i < k)
                res += a[i];
            else
                res -= a[i];
        }

        cout << res << endl;
    }

    return 0;
}
