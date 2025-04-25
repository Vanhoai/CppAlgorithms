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
 * Expression
 *
 * input:
 *      A, B, C, D, E <= 100
 *      [[[A o(1) B] o(2) C] o(3) D] o(4) E = 23
 *      o: +, -, *
 *
 * output: YES/NO
 *
 * @example
 *      input:
 *          3
 *          1 1 1 1 1
 *          1 2 3 4 5
 *          2 3 5 7 11
 *      output:
 *          NO
 *          YES
 *          YES
 */

int n, ok, X[100], A[6];
vector<vector<int>> pers, ckn;

void backtracking(int i) {
    FOR(j, 1, 3) {
        X[i] = j;
        if (i == 4) {
            vector<int> tmp(X + 1, X + i + 1);
            ckn.push_back(tmp);
        } else
            backtracking(i + 1);
    }
}

void init() {
    int a[5] = {1, 2, 3, 4, 5};
    do {
        vector<int> tmp(a, a + 5);
        pers.push_back(tmp);
    } while (next_permutation(a, a + 5));

    backtracking(1);
}

void solve() {
    for (int i = 1; i <= 5; i++)
        cin >> A[i];

    ok = false;
    for (auto per : pers) {
        for (auto c : ckn) {
            int res = A[per[0]];
            for (int k = 0; k < 4; k++) {
                if (c[k] == 1) {   // +
                    res += A[per[k + 1]];
                } else if (c[k] == 2) {
                    res -= A[per[k + 1]];
                } else {
                    res *= A[per[k + 1]];
                }
            }

            if (res == 23) {
                ok = true;
                break;
            }
        }

        if (ok)
            break;
    }

    if (ok)
        cout << "YES\n";
    else
        cout << "NO\n";
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
        solve();
    }

    return 0;
}
