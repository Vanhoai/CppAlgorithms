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
 * Euler's Totient function
 * Count the number of co-prime numbers with n not exceeding n.
 *
 * output: print the number of co-prime numbers with n not exceeding n.
 *
 * @example
 *      input: 10000000000000000
 *      output: 4000000000000000
 */

ll u(ll n) {
    ll res = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            res = res - res / i;
            while (n % i == 0)
                n /= i;
        }
    }

    if (n > 1)
        res = res - res / n;

    return res;
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
        ll n;
        cin >> n;
        cout << u(n) << endl;
    }

    return 0;
}
