#include <iostream>
#include <map>
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
 * Setup Characters
 *
 * input:
 *      T, S
 *      1 ≤ T ≤ 100; 1 ≤ length(S) ≤ 10000
 *
 * output: YES/NO
 *
 * @example
 *      input:
 *          3
 *          geeksforgeeks
 *          bbbabaaacd
 *          bbbbb
 *      output:
 *          1
 *          1
 *          -1
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int TC;
    cin >> TC;
    while (TC--) {
        string s;
        cin >> s;

        map<char, int> mp;
        FOR(i, 0, s.size()) mp[s[i]]++;

        int mx = 0;
        for (auto it : mp)
            mx = max(mx, it.second);

        int remain = s.size() - mx;

        int ok = remain + 1 >= mx;
        cout << (ok ? "YES" : "NO") << endl;
    }

    return 0;
}
