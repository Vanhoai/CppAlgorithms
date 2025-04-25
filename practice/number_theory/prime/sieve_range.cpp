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
 * Sieve of Eratosthenes
 *
 * input: a, b (0 <= a <= b <= 10^9) & (b - a <= 10^5)
 * output: print all numbers between inclusively a and b if they are prime
 */

void sieve_range(ll L, ll R) {
    int is_prime[R - L + 1];

    for (ll i = L; i <= R; i++) {
        is_prime[i - L] = 1;
    }

    for (ll i = 2; i <= sqrt(R); i++) {
        for (ll j = max(i * i, (L + i - 1) / i * i); j <= R; j += i) {
            is_prime[j - L] = 0;
        }
    }

    for (ll i = max(2ll, L); i <= R; i++) {
        if (is_prime[i - L]) {
            cout << i << ' ';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ll a, b;
    cin >> a >> b;
    sieve_range(a, b);

    return 0;
}
