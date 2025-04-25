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
AA AB BA BB
AAA AAB ABA ABB BAA BAB BBA BBB

 */

int n, ok;
char g[100];

void init() { FOR(i, 1, n) g[i] = 'A'; }

void gen() {
    int i = n;
    while (i >= 1 && g[i] == 'B') {
        g[i] = 'A';
        i--;
    }

    if (i == 0)
        ok = 0;
    else
        g[i] = 'B';
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

        ok = 1;
        while (ok) {
            FOR(i, 1, n) cout << (char) g[i];
            cout << " ";

            gen();
        }

        cout << endl;
    }

    return 0;
}
