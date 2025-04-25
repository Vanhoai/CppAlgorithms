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
 * Reversible Number
 *
 *
 * input:
 *      T: number of testcases (1 <= T <= 100)
 *      N: number check (1 <= N <= 10^18)
 *
 * output: YES/NO
 *
 * @example
 *      input: 9999999999999999
 *      output: YES
 */

const int maxn = 18;
int digit[maxn + 1];
int cnt = 0;

void decay_n(ll n) {
    int index = 1;
    while (n) {
        digit[index++] = n % 10;
        n /= 10;
    }

    cnt = index - 1;
}

int solve(ll N) {
    ll sum = 0;
    ll index = cnt;
    for (int i = 1; i <= cnt; i++) {
        ll k = digit[i] * pow(10, --index);
        sum += k;
    }

    return sum == N;
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
        ll N;
        cin >> N;

        memset(digit, 0, sizeof(digit));
        decay_n(N);

        if (solve(N))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
