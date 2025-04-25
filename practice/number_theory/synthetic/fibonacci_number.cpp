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
 * Fibonacci Number
 *
 * output: YES/NO
 *
 * @example
 *      input: 420196140727489673
 *      output: YES
 */

ll f[100];

void init() {
    f[0] = 0;
    f[1] = 1;
    for (int i = 2; i <= 92; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }
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
        ll N;
        cin >> N;

        bool check = false;
        for (int i = 0; i <= 92; i++) {
            if (N == f[i]) {
                check = true;
                break;
            }
        }

        cout << (check ? "YES" : "NO") << endl;
    }

    return 0;
}
