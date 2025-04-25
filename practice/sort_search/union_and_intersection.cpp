#include <iostream>
#include <map>
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
typedef vector<vi> vvi;
typedef map<int, int> mii;

const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9 + 1;
const int DEG = (int) 10001;

inline ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
inline ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

/**
 *  Union & Intersection
 *
 * input:
 *      N, M, A[i], B[i]
 *      1 ≤ N, M ≤ 10^6
 *      -10^6 ≤ A[i], B[i] ≤ 10^6
 *
 * output: print array after sorted
 *
 * @example
 *      input:
 *          4 5
 *          1 2 3
 *          1 2 3 5 9
 *      output:
 *          1 2 3 5 9
 *          1 2 3
 */

void solve1() {

    int n, m;
    cin >> n >> m;
    int a[n], b[m];

    FOR(i, 0, n) cin >> a[i];
    FOR(i, 0, m) cin >> b[i];

    vi intersection;
    set<int> unions;
    int i = 0, j = 0;
    while (i < n && j < m) {
        unions.insert(a[i]);
        unions.insert(b[j]);

        if (a[i] == b[j]) {
            intersection.push_back(a[i]);
            i++;
            j++;
        } else if (a[i] > b[j])
            j++;
        else
            i++;
    }

    while (i < n)
        unions.insert(a[i++]);

    while (j < m)
        unions.insert(b[j++]);

    for (auto it : unions)
        cout << it << " ";

    cout << endl;

    for (auto it : intersection)
        cout << it << " ";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m;
    cin >> n >> m;

    mii mp;
    FOR(i, 0, n) {
        int x;
        cin >> x;
        mp[x]++;
    }

    FOR(i, 0, m) {
        int x;
        cin >> x;
        mp[x]++;
    }

    for (auto it : mp)
        cout << it.first << " ";
    cout << endl;

    for (auto it : mp) {
        if (it.second >= 2)
            cout << it.first << " ";
    }
    return 0;
}
