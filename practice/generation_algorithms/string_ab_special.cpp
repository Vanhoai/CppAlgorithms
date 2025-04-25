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
1
5 3

output:
AAABA
AAABB
ABAAA
BAAAB
BBAAA

 */

int n, k, ok, g[100];

void init() { FOR(i, 1, n) g[i] = 0; }

void gen() {
    int i = n;
    while (i >= 1 && g[i] == 1) {
        g[i] = 0;
        i--;
    }

    if (i == 0)
        ok = 0;
    else
        g[i] = 1;
}

int check() {
    int count = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (g[i] == 0)
            count++;
        else
            count = 0;

        if (count > k)
            return 0;
        if (count == k)
            ans++;
    }

    return ans == 1;
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
        cin >> n >> k;

        ok = 1;
        while (ok) {
            if (check()) {
                for (int i = 1; i <= n; i++) {
                    if (g[i] == 0)
                        cout << "A";
                    else
                        cout << "B";
                }

                cout << " ";
            }

            gen();
        }

        cout << endl;
    }

    return 0;
}
