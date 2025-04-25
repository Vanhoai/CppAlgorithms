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
 * Fraction
 *
 * input:
 *      T, P, Q
 *      1 ≤ T ≤ 100
 *      1 ≤ P, Q ≤ 100.
 *
 * output: print answers
 *
 * @example
 *      input:
 *          2
 *          2 3
 *          1 3
 *      output:
 *          1/2 + 1/6
 *          1/3
 *
 */

void backtracking(int p, int q) {
    if (q % p == 0) {
        cout << "1/" << q / p << endl;
        return;
    }

    ll x = q / p + 1;
    cout << "1/" << x << " + ";
    ll q_new = q * x;
    ll p_new = p * x - q;
    backtracking(p_new, q_new);
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
        int p, q;
        cin >> p >> q;
        backtracking(p, q);
    }

    return 0;
}
