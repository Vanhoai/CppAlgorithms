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
 * Segment Tree
 *
 * 11 3
 * 6 5 9 7 7 6 7 7 5 9 7
 * 1 9 u
 * 1 2 q
 * 0 8 q
 *
 * 18
 * 63
 */

const int maxn = 100001;
int a[maxn], n, q;
int seg[4 * maxn];

void build(int v, int L, int R) {
    if (L == R)
        seg[v] = a[L];
    else {
        int m = (L + R) >> 1;
        build(2 * v, L, m);
        build(2 * v + 1, m + 1, R);
        seg[v] = seg[2 * v] + seg[2 * v + 1];
    }
}

int query(int v, int tL, int tR, int L, int R) {
    if (L > R)
        return 0;
    if (L == tL && R == tR)
        return seg[v];
    else {
        int tM = (tL + tR) >> 1;
        return query(2 * v, tL, tM, L, min(tM, R)) +
               query(2 * v + 1, tM + 1, tR, max(tM + 1, L), R);
    }
}

void update(int v, int L, int R, int pos, int value) {
    if (L == R)
        seg[v] = value;
    else {
        int m = (L + R) >> 1;
        if (pos <= m)
            update(2 * v, L, m, pos, value);
        else
            update(2 * v + 1, m + 1, R, pos, value);

        seg[v] = seg[2 * v] + seg[2 * v + 1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> n >> q;
    FOR(i, 0, n) cin >> a[i];
    build(1, 0, n - 1);

    while (q--) {
        int x, y;
        char r;
        cin >> x >> y >> r;
        if (r == 'u')
            update(1, 0, n - 1, x, y);
        else
            cout << query(1, 0, n - 1, x, y) << endl;
    }

    return 0;
}
