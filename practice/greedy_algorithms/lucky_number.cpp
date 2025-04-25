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
 * Lucky Number
 *
 * input:
 *      T, N
 *      1 <= T <= 100
 *      1 <= N <= 10^6
 *
 * output: print minimum number with digit 4, 7 and sum of number equal k
 *
 * @example
 *      input:
 *          2
 *          11
 *          10
 *      output:
 *          47
 *          -1
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    // 4A + 7B = N

    int TC;
    cin >> TC;
    while (TC--) {
        ll n;
        cin >> n;

        int ok = 0;

        for (int b = n / 7; b >= 0; b--) {
            int remain = n - 7 * b;
            if (remain % 4 == 0) {
                ok = 1;
                int a = remain / 4;
                cout << string(a, '4');
                cout << string(b, '7');
                cout << endl;
                break;
            }
        }

        if (!ok)
            cout << -1 << endl;
    }

    return 0;
}
