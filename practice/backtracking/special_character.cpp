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
 * Special Character
 *
 * input:
 *      T < 10
 *      1 ≤ N ≤ 10^18
 *
 * output: print character k-th
 *
 * @example
 *      input:
 *          1
 *          COW 8
 *      output:
 *          C
 *          COW -> COWWCO -> COWWCOOCOWWC
 */

string s;
ll n, length;

char search(ll n, ll k) {
    if (n <= s.size())
        return s[n - 1];
    if (n <= k / 2)
        return search(n, k / 2);
    else {
        ll tmp = n - k / 2;
        if (tmp == 1)
            return search(k / 2, k / 2);
        else
            return search(tmp - 1, k / 2);
    }
}

void solve() {
    cin >> s >> n;

    length = s.size();
    while (length < n)
        length <<= 1;

    cout << search(n, length);
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
        solve();
    }
    return 0;
}
