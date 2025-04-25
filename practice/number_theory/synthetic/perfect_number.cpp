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
 * Perfect Number
 * A perfect number is a number whose sum of proper divisors (excluding itself)
 * is equal to the number itself. Given a positive integer n, check whether n is
 * a perfect number or not. input: T: number of testcases (1 <= T <= 100) N:
 * number check (1 <= N <= 10^9)
 *
 * output: YES/NO
 *
 * @example
 *      input: 2305843008139952128
 *      output: YES
 */

int is_prime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return 0;
    }

    return n > 1;
}

ll perfect[10];
int cnt = 0;

void init() {
    for (int p = 2; p <= 32; p++) {
        if (is_prime(p)) {
            int tmp = (int) pow(2, p) - 1;
            if (is_prime(tmp)) {
                ll n = 1LL * (int) pow(2, p - 1) * tmp;
                perfect[cnt] = n;
                ++cnt;
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

    init();

    int TC;
    cin >> TC;
    while (TC--) {
        ll N;
        cin >> N;

        bool check = false;
        for (int i = 0; i < cnt; i++) {
            if (N == perfect[i]) {
                check = true;
                break;
            }
        }

        cout << (check ? "YES" : "NO") << endl;
    }

    return 0;
}
