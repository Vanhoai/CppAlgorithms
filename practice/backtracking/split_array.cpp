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
 * Split Array
 *
 * input:
 *      T, N, K, A(i)
 *      1 ≤ T ≤ 100
 *      1 ≤ N, K ≤ 20
 *      0 ≤ A(i) ≤ 100
 *
 * output: print 1 if possible, otherwise print 0
 *
 * @example
 *      input:
 *          2
 *          5 3
 *          2 1 4 5 6
 *          5 3
 *          2 1 5 5 6
 *      output:
 *          1
 *          0
 */

int n, k, s, ans, A[100];
bool visited[100];

void backtracking(int sum, int count) {
    if (count == k && sum == s) {
        ans = 1;
        return;
    }

    if (ans)
        return;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            if (sum == s) {
                backtracking(0, count + 1);
            } else if (sum + A[i] <= s) {
                backtracking(sum + A[i], count);
            }
        }

        visited[i] = false;
    }
}

void solve() {
    cin >> n >> k;

    s = 0;
    FOR(i, 1, n) {
        cin >> A[i];
        s += A[i];
    }

    if (s % k != 0) {
        cout << "0\n";
        return;
    }

    s /= k;
    memset(visited, false, sizeof(visited));

    ans = 0;

    backtracking(0, 0);
    cout << ans << endl;
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
