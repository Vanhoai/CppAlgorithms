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
 * Link line
 *
 * input:
 *      T, N, A[i]
 *      N ≤ 2 * 10^6
 *      1 ≤ A[i] ≤ 10^9
 *
 * output: print minimum fee link line
 *
 * @example
 *      input:
 *          7
 *          2 4 1 2 10 2 3
 *      output:
 *          59
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    priority_queue<ll, vector<ll>, greater<ll>> Q;
    FOR(i, 0, n) {
        int x;
        cin >> x;
        Q.push(x);
    }

    ll res = 0;
    while (Q.size() > 1) {
        ll u = Q.top();
        Q.pop();
        ll v = Q.top();
        Q.pop();

        res += 1LL * u + v;
        res %= MOD;
        Q.push(u + v);
    }

    cout << res << endl;

    return 0;
}
