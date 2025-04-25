#include <iostream>
using namespace std;

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
 *  Sort by abs
 *
 * input:
 *      T, N, X, A[i]
 *      1 ≤ T ≤ 100
 *      1 ≤ n, X, A[i] ≤ 10^5
 *
 * output: print array after sorted
 *
 * @example
 *      input:
 *          2
 *          5 7
 *          10 5 3 9 2
 *          5 6
 *          1 2 3 4 5
 *      output:
 *          5 9 10 3 2
 *          5 4 3 2 1
 */

const int maxn = 100005;
int idx[maxn];

int n, X;

bool comparator(int a, int b) {
    if (abs(X - a) == abs(X - b))
        return idx[a] < idx[b];

    return abs(X - a) < abs(X - b);
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
        cin >> n >> X;
        int a[n];
        ms(idx, 0);

        FOR(i, 0, n) {
            cin >> a[i];
            idx[a[i]] = i;
        }

        sort(a, a + n, comparator);
        FOR(i, 0, n) cout << a[i] << " ";
        cout << endl;
    }

    return 0;
}
