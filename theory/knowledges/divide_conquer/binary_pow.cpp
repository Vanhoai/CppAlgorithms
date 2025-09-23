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
 * Binary Pow
 *
 * input:
 *      N, K
 *      1<=N<=10^6
 *      1<=K<=10^9
 *
 * output: print result of N ^ K mod 10^9 + 7
 *
 * a^b = {
 *      b == 0 -> 1
 *      b even -> a^b/2 * a^b/2
 *      b old -> a^b/2 * a^b/2 * a
 * }
 *
 * @example
 *      input:
 *          2
 *          9 9
 *          994402 999992619
 *      output:
 *          387420489
 *          925329307
 */

ll binpow(ll a, ll b) {
    if (b == 0)
        return 1;

    ll n = binpow(a, b / 2);
    if (b % 2 == 0)
        return (n % MOD) * (n % MOD) % MOD;
    else
        return ((n % MOD) * (n % MOD) % MOD) * (a % MOD) % MOD;
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
        ll n, k;
        cin >> n >> k;
        cout << binpow(n, k) << endl;
    }

    return 0;
}
