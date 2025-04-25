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
 * Statistical Number
 *
 * input:
 *      T, N, X, A(i)
 *      1 ≤ T ≤ 10
 *      1 ≤ X, A(i) ≤ 100
 *      N ≤ 20
 *
 * output: print all way statistical number (partition)
 *
 * @example
 *      input:
 *          1
 *          4 8
 *          2 4 6 8
 *      output:
 *          [2 2 2 2] [2 2 4] [2 6] [4 4] [8]
 */

int n, s, ok, X[100], A[100];

void input() {
    cin >> n >> s;
    FOR(i, 1, n) cin >> A[i];
    sort(A + 1, A + n + 1);
}

void backtracking(int i, int pos, int sum) {
    if (sum == s) {
        cout << "[";
        for (int k = 1; k < i; k++) {
            cout << X[k];
            if (k == i - 1)
                cout << "]";
            else
                cout << " ";
        }

        cout << " ";
        ok = 1;
        return;
    }

    for (int k = pos; k <= n; k++) {
        if (sum + A[k] <= s) {
            X[i] = A[k];
            backtracking(i + 1, k, sum + A[k]);
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
        ok = 0;
        backtracking(1, 1, 0);
        if (!ok)
            cout << "-1\n";
    }

    return 0;
}
