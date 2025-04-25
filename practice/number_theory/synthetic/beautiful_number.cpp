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
 * Beautiful Numbers
 * A number is said to be beautiful if it is a prime number and
 * sum of digits of the number is exist in fibonacci number.
 *
 * input:
 *      L, R: range of number (1 ≤ a ≤ b ≤ 10^9)
 *
 * output: print all beautiful number in range, if not exist, print -1
 *
 * @example
 *      input: 2 50
 *      output: 2 3 5 11 17 23 41
 */

ll f[93];

void init() {
    f[0] = 0;
    f[1] = 1;
    for (int i = 2; i <= 92; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }
}

int sum_digit(ll n) {
    int sum = 0;
    while (n) {
        sum += n % 10;
        n /= 10;
    }

    return sum;
}

int is_prime(ll n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return 0;
    }

    return n > 1;
}

int check_in_fib(int n) {
    for (int i = 0; i <= 92; i++) {
        if (n == f[i]) {
            return 1;
        }
    }

    return 0;
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
        ll L, R;
        cin >> L >> R;

        int check = 0;
        for (ll i = L; i <= R; i++) {
            if (is_prime(i) && check_in_fib(sum_digit(i))) {
                check = 1;
                cout << i << " ";
            }
        }

        if (!check)
            cout << "-1";

        cout << endl;
    }

    return 0;
}
