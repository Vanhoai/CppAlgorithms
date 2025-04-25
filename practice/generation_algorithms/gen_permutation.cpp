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
input
2
2
3

output:
12 21
123 132 213 231 312 321

 */

int n, ok, g[100];

void init() { FOR(i, 1, n) g[i] = i; }

void gen() {
    int i = n - 1;
    while (i >= 1 && g[i] > g[i + 1])
        i--;

    if (i == 0)
        ok = 0;
    else {
        int j = n;
        while (g[i] > g[j])
            j--;

        swap(g[i], g[j]);
        reverse(g + i + 1, g + n + 1);
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
        cin >> n;
        init();

        ok = 1;
        while (ok) {
            FOR(i, 1, n) cout << g[i];
            cout << " ";

            gen();
        }

        cout << endl;
    }

    return 0;
}
