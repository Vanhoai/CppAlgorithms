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
 * Smallest number with N divisors
 *
 * input:
 *      T, N
 *      T ≤ 20
 *      1 ≤ N ≤ 1000
 *
 * output: print minimum number with N divisors
 *
 * @example
 *      input:
 *          2
 *          4
 *          6
 *      output:
 *          6
 *          12
 */

int p[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
int n;

ll backtracking(int pos, ll count, ll x) {
    if (count == n)
        return x;

    ll tmp = 1e18 + 5;
    int i = 1;
    while (true) {
        x *= p[pos];
        if (x > tmp)
            break;

        if (count * (i + 1) > n)
            break;

        tmp = min(tmp, backtracking(pos + 1, count * (i + 1), x));
        i++;
    }

    return tmp;
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
        cin >> n;
        ll ans = backtracking(0, 1, 1);
        cout << ans << endl;
    }

    return 0;
}
