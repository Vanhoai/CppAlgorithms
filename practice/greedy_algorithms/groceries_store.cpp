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
 * Groceries Store
 *
 * input:
 *      T, N, S, M
 *      1 ≤ T ≤ 100
 *      1 ≤ N, S, M ≤ 30
 *
 * output: print the number of day at least can buy for s next day
 *
 * @example
 *      input:
 *          2
 *          16 10 2
 *          20 10 30
 *      output:
 *          2
 *          -1
 *
 */

int check(int n, int s, int m) {
    if (m > n)
        return -1;

    int sun = s / 7;
    bool check = n * (s - sun) >= m * s;

    if (!check)
        return -1;

    FOR(i, 1, n - sun + 1) {
        if (s * m <= i * n)
            return i;
    }

    return -1;
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
        int n, s, m;
        cin >> n >> s >> m;
        cout << check(n, s, m) << endl;
    }

    return 0;
}
