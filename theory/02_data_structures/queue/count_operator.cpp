#include <iostream>
#include <set>
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

inline ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
inline ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

int solve(int s, int t) {
    queue<pi> q;
    q.emplace(s, 0);

    set<int> se;
    se.insert(s);

    while (!q.empty()) {
        pi it = q.front();
        q.pop();

        if (it.F == t)
            return it.S;

        if (it.F > 1 && se.count(it.F - 1) == 0) {
            q.emplace(it.F - 1, it.S + 1);
            se.insert(it.F - 1);
        }

        if (it.F < t && se.count(it.F * 2) == 0) {
            q.emplace(it.F * 2, it.S + 1);
            se.insert(it.F * 2);
        }
    }

    return -1;
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
        int s, t;
        cin >> s >> t;
        cout << solve(s, t) << endl;
    }

    return 0;
}
