#include "./stdc++.h"

#define IOS   ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define IO    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#define SETUP IOS, IO

#define ms(s, v)         memset(s, v, sizeof(s))
#define all(a)           a.begin(), a.end()
#define present(t, x)    (t.find(x) != t.end())
#define sz(a)            int((a).size())
#define FOR(i, a, b)     for (int i = (a); i < (b); ++i)
#define INVERSE(i, a, b) for (int i = (a); i >= b; --i)
#define REP(i, a, b)     for (int i = (a); i <= (b); ++i)

#define PB push_back
#define PF push_front
#define MP make_pair
#define F  first
#define S  second

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef std::pair<int, int> pi;
typedef std::vector<int> vi;
typedef std::vector<pi> vii;
typedef std::map<int, int> mii;

const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9 + 1;

inline ll GCD(ll a, ll b) {
    ll r;
    while (b) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
inline ll LCM(ll a, ll b) { return a / GCD(a, b) * b; }
inline bool PRIME(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return n > 1;
}
