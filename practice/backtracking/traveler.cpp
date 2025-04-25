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
 * Traveler
 *
 * input:
 *      N, A(i)(j)
 *      1 <= N <= 15
 *      1 <= C(i) <= 100
 *
 * output: print the cost that person has to pay
 *
 * @example
 *      input:
 *          4
 *          0 20 35 10
 *          20 0 90 50
 *          35 90 0 12
 *          10 50 12 0
 *      output:
 *          117
 */

const int maxn = 15;
int n, A[maxn + 1][maxn + 1], X[100], cmin = 1e9 + 5, res = 0, ans = 1e9;
bool visited[maxn + 1];

void in() {
    cin >> n;
    FOR(i, 1, n) FOR(j, 1, n) {
        cin >> A[i][j];
        cmin = min(cmin, A[i][j]);
    }
}

void backtracking(int i) {
    for (int j = 2; j <= n; j++) {
        if (!visited[j]) {
            visited[j] = true;
            X[i] = j;
            res += A[X[i]][X[i - 1]];
            if (i == n)
                ans = min(ans, res + A[X[n]][1]);
            else if (res + cmin * (n - i + 1) < ans) {
                backtracking(i + 1);
            }

            visited[j] = false;
            res -= A[X[i]][X[i - 1]];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    in();
    memset(visited, false, sizeof(visited));
    X[1] = 1;
    backtracking(2);

    cout << ans << endl;
    return 0;
}
