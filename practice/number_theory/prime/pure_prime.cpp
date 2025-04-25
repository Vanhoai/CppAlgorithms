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
 * Pure Prime
 * A number is considered to be prime if it is prime, all of its digits are
 * prime, and the sum of its digits is also a prime. The problem is to count how
 * many prime numbers there are between two given integers.
 *
 * input:
 *      T: number of test cases (1 <= T <= 100)
 *      A, B: two integers (1 <= A <= B <= 10^9)
 *
 * output: print count of pure prime numbers between A and B
 *
 * @example
 *      input: 23 199
 *      output: 1 number: 23
 */

int is_prime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return 0;
    }

    return n > 1;
}

int digit_prime(int n) {
    while (n) {
        if (!is_prime(n % 10)) {
            return 0;
        }

        n /= 10;
    }

    return 1;
}

int sum_prime(int n) {
    int sum = 0;
    while (n) {
        sum += n % 10;
        n /= 10;
    }

    return is_prime(sum);
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
        int A, B;
        cin >> A >> B;

        int count = 0;
        FOR(i, A, B) {
            if (is_prime(i) && digit_prime(i) && sum_prime(i)) {
                count++;
            }
        }

        cout << count << endl;
    }

    return 0;
}
