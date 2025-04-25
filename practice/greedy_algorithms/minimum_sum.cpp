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
 * Minimum Sum
 *
 * input:
 *      T, N, A[i]
 *      1 ≤ T ≤ 100
 *      1 ≤ N ≤ 20
 *      0 ≤ A[i] ≤ 9
 *
 * output: print minimum sum from two number make from array
 *
 * @example
 *      input:
 *          2
 *          6
 *          6 8 4 5 2 3
 *          5
 *          5 3 0 7 4
 *      output:
 *          604
 *          82
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
        int a[n];
        FOR(i, 0, n) cin >> a[i];
        sort(a, a + n);

        vector<int> v;
        FOR(i, 0, n) {
            if (a[i])
                v.PB(a[i]);
        }

        int n1 = 0;
        int n2 = 0;

        for (int i = 0; i < v.size(); i += 2)
            n1 = n1 * 10 + v[i];

        for (int i = 1; i < v.size(); i += 2)
            n2 = n2 * 10 + v[i];

        cout << n1 + n2 << endl;
    }

    return 0;
}
