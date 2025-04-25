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

ll factorial(int n) {
    if (n == 1)
        return 1;
    return n * factorial(n - 1);
}

const int maxn = 1000005;
int f[maxn];

void solve(int a[], int n, int s) {
    ms(f, 0);
    FOR(i, 0, n) f[a[i]]++;

    ll res = 0;
    FOR(i, 0, n) {
        if (f[s - a[i]]) {

            if (a[i] == s - a[i]) {
                res += 1LL * factorial(f[a[i]] - 1);
            } else {
                res += 1LL * (f[a[i]] * f[s - a[i]]);
            }

            f[a[i]] = 0;
            f[s - a[i]] = 0;
        }
    }

    cout << res << endl;
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
        int n, s;
        cin >> n >> s;
        int a[n];
        FOR(i, 0, n) cin >> a[i];

        solve(a, n, s);
    }

    return 0;
}
