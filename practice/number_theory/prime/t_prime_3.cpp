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
 * T-Prime 3
 *
 * input:
 *      T: integer (1 <= T <= 100)
 *      L, R: integer (1 ≤ L, R ≤ 10^12)
 *
 * output: print the number of number with exactly 3 factors in the range [L, R]
 *
 * @example
 *      input: 1 1000000000000
 *      output: 78498
 */

const int maxn = 1e6 + 1;
int prime[maxn];

void sieve() {
    memset(prime, 1, sizeof(prime));
    for (int i = 2; i * i <= maxn; i++) {
        if (prime[i]) {
            for (int k = i * i; k <= maxn; k += i) {
                prime[k] = 0;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    sieve();

    int TC;
    cin >> TC;
    while (TC--) {
        ll L, R;
        cin >> L >> R;

        int count = 0;
        int c1 = sqrt(L);
        int c2 = sqrt(R);

        for (ll i = max(2, c1); i <= c2; i++) {
            if (prime[i]) {
                count++;
            }
        }

        cout << count << endl;
    }

    return 0;
}
