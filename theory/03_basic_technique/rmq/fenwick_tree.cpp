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
 *
 * Fenwick Tree
 *
 * 11 3
 * 6 5 9 7 7 6 7 7 5 9 7
 * 1 9
 * 1 2
 * 0 8
 *
 * 59
 * 11
 * 54
 */

const int maxn = 1000005;
int a[maxn], bit[maxn], n, q;

/**
 * pos += pos & (-pos)
 *
 * pos = 3 -> 0011
 * -pos -> 1101
 *
 * -> pos & (-pos) => 0001 + 0011 = 0100 = 4
 */
void update(int pos, int value) {
    for (; pos <= n; pos += pos & (-pos))
        bit[pos] += value;
}

int query(int pos) {
    int sum = 0;
    for (; pos > 0; pos -= pos & (-pos))
        sum += bit[pos];

    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> n >> q;
    FOR(i, 1, n) {
        cin >> a[i];
        update(i, a[i]);
    }

    while (q--) {
        int L, R;
        cin >> L >> R;
        cout << query(R) - query(L - 1) << endl;
    }

    return 0;
}
