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
 * Update operation in difference array
 *
 * input:
 *      1<=N<=10^6
 *      1<=Q<= 10^5
 *      0<=L<=R<=N-1, 0<=A[i],K<=1000
 *
 * output: print array after q update
 *
 * @example
 *      input:
 *          7 3
 *          8 5 8 9 7 6 9
 *          0 5 0
 *          0 5 0
 *          1 5 1
 *
 *      output:
 *          8 6 9 10 8 7 9
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, q;
    cin >> n >> q;
    int a[n];
    FOR(i, 0, n) cin >> a[i];

    int d[n];
    d[0] = a[0];
    FOR(i, 1, n) d[i] = a[i] - a[i - 1];

    while (q--) {
        int l, r, v;
        cin >> l >> r >> v;
        a[l] += v;
        a[r + 1] -= v;
    }

    FOR(i, 1, n) d[i] = d[i] + d[i - 1];
    FOR(i, 0, n) cout << d[i] << " ";
    cout << endl;

    return 0;
}
