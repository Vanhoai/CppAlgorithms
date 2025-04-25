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
 * sort() -> intro sort (heap sort and quick sort)
 * stable_sort() -> sort but with stability (merge sort)
 */

void theory() {
    int n;
    cin >> n;
    int a[n];
    FOR(i, 0, n) cin >> a[i];
    sort(a, a + n);

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    stable_sort(a, a + n, greater<int>());

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}

bool cmp(pi a, pi b) {
    if (a.S == b.S)
        return a.F > b.F;
    return a.S > b.S;
}

void sort_frequency(int a[], int n) {
    map<int, int> mp;
    FOR(i, 0, n) mp[a[i]]++;

    vii v;
    for (int i = 0; i < n; i++)
        v.PB(MP(a[i], mp[a[i]]));

    sort(v.begin(), v.end(), cmp);
    FOR(i, 0, v.size()) cout << v[i].F << " ";

    sort(a, a + n, [](int a, int b) -> bool { return a > b; });
    FOR(i, 0, n) cout << a[i] << " ";

    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    int a[n];
    FOR(i, 0, n) cin >> a[i];

    sort_frequency(a, n);
    return 0;
}
