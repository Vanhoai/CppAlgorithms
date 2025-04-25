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
 * Setup Characters with d unit
 *
 * input:
 *      T, S, D
 *      1 ≤ T ≤ 100
 *      1 ≤ D ≤ 100
 *      1 ≤ length(S) ≤ 10000
 *
 * output: YES/NO
 *
 * @example
 *      input:
 *          2
 *          2
 *          ABB
 *          2
 *          AAA
 *      output:
 *          1
 *          -1
 */

void solve(string s, int d) {

    int n = s.size();
    map<char, int> mp;
    FOR(i, 0, s.size()) mp[s[i]]++;

    vector<pair<char, int>> v;
    for (auto it : mp)
        v.push_back(it);

    sort(all(v), [](pair<char, int> a, pair<char, int> b) -> bool {
        return a.S > b.S;
    });

    string res = string(n, '#');
    bool ok = true;
    FOR(i, 0, sz(v)) {
        int pos = i;
        while (res[pos] != '#')
            pos++;
        FOR(k, 0, v[i].second) {
            if (pos + k * d >= n) {
                ok = false;
                break;
            }
            res[pos + k * d] = v[i].F;
        }
    }

    if (!ok)
        cout << -1 << endl;
    else
        cout << 1 << endl;
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
        int d;
        cin >> d;
        string s;
        cin >> s;

        solve(s, d);
    }

    return 0;
}
