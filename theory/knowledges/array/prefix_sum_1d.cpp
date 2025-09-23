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
 * Prefix Sum
 * a[i] = sum(a[j]) where j: 0 -> i
 *
 *
 * 11 3
 * 6 5 9 7 7 6 7 7 5 9 7
 * 1 9
 * 1 10
 * 0 8
 *
 * 62
 * 69
 * 59
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int TC;
    cin >> TC;
    while (TC--) {
        int n, q;
        cin >> n >> q;
        int a[n];
        FOR(i, 0, n) cin >> a[i];

        ll prefix[n];
        prefix[0] = a[0];
        FOR(i, 1, n) prefix[i] = 1LL * a[i] + prefix[i - 1];

        FOR(i, 0, q) {
            int L, R;
            cin >> L >> R;
            if (L == 0)
                cout << prefix[R] << endl;
            else
                cout << prefix[R] - prefix[L - 1] << endl;
        }
    }

    return 0;
}
