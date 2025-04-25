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
 * ATM Tree
 *
 * input:
 *      T, N, S, A(i)
 *      1 <= N <= 30
 *      S ≤ 10^9
 *      A(i) <= 10^9
 *
 * output: print minimum paper of money
 *
 * @example
 *      input:
 *          1
 *          3 5
 *          1 4 5
 *      output:
 *          1 (1 - 5)
 */

int n, s, k, ok;
ll A[100], X[100];

void in() {
    cin >> n >> s;
    FOR(i, 1, n) cin >> A[i];
    sort(A + 1, A + n + 1, greater<ll>());
}

void backtracking(int i) {
    if (ok)
        return;

    for (int j = X[i - 1] + 1; j <= n - k + i; j++) {
        X[i] = j;
        if (i == k) {
            int sum = 0;
            for (int j = 1; j <= k; j++)
                sum += A[X[j]];

            if (sum == s) {
                ok = 1;
            }
        } else
            backtracking(i + 1);
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
        in();

        ok = 0;
        for (int i = 1; i <= n; i++) {
            k = i;
            backtracking(1);
            if (ok) {
                cout << k << endl;
                break;
            }
        }

        if (!ok)
            cout << -1 << endl;
    }

    return 0;
}
