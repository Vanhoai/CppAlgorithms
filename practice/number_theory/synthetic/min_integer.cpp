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
 * Min Integer
 * Find the smallest n-digit positive integer that is divisible by x, y, and z.
 *
 * input:
 *      T: number of testcases (1 <= T <= 100)
 *      x, y, z, n (1 ≤ x, y, z ≤ 10^4)  n ≤ 16.
 *
 * output: Print out the number that satisfies the conditions of the question
 *
 * @example
 *      input: 2 3 5 4
 *      output: 1020
 */

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) { return a / gcd(a, b) * b; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int TC;
    cin >> TC;
    while (TC--) {
        int x, y, z, n;
        cin >> x >> y >> z >> n;

        int lc = lcm(x, lcm(y, z));
        int res = ((ll) pow(10, n - 1) + lc - 1) / lc * lc;
        if (res > pow(10, n))
            cout << -1 << endl;
        else
            cout << res << endl;
    }

    return 0;
}
