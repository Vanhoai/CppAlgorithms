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
 * Prime Numbers
 *
 * input:
 *      N, P, S
 *      1 ≤ T ≤100
 *      1 ≤ N ≤ 10
 *      2 ≤ S, P ≤200
 *
 * output: print n subset with element is prime and sum equal s
 *
 * @example
 *      input:
 *          2
 *          2 7 28
 *          3 2 23
 *      output:
 *          1
 *          11 17
 *          2
 *          3 7 13
 *          5 7 11
 */

int n, p, s, ans, X[100];
vector<int> primes;
vector<vector<int>> res;

bool is_prime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return n > 1;
}

void input() {
    cin >> n >> p >> s;
    res.clear();
    primes.clear();

    for (int i = p + 1; i <= s; i++) {
        if (is_prime(i))
            primes.push_back(i);
    }
}

void backtracking(int i, int pos, int sum) {
    if (i == n && sum == s) {
        vector<int> tmp(X, X + n);
        res.push_back(tmp);
        return;
    }

    for (int j = pos; j <= primes.size(); j++) {
        if (sum + primes[j] <= s) {
            X[i] = primes[j];
            backtracking(i + 1, j + 1, sum + X[i]);
        }
    }
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
        input();
        backtracking(0, 0, 0);

        cout << res.size() << endl;
        FOR(i, 0, res.size() - 1) {
            FOR(j, 0, res[i].size() - 1) cout << res[i][j] << " ";
            cout << endl;
        }
    }

    return 0;
}
