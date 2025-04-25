#include <iostream>
using namespace std;

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
 *  Couting Sort
 *
 * input:
 *      T, N
 *      1 ≤ T ≤ 100
 *      1 ≤ n ≤ 10^3
 *      0 <= A[i] <= 2
 *
 * output: print arrray sorted
 *
 * @example
 *      input:
 *          2
 *          5
 *          1 1 0 0 2
 *          6
 *          1 1 1 0 0 2
 *      output:
 *          0 0 1 1 2
 *          0 0 1 1 1 2
 */

void counting_sort(int a[], int n) {
    int c[3];
    ms(c, 0);

    FOR(i, 0, n) c[a[i]]++;

    int i = 0;
    FOR(k, 0, 3) {
        while (c[k]) {
            a[i++] = k;
            c[k]--;
        }
    }

    FOR(i, 0, n) cout << a[i] << " ";
    cout << endl;
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
        int n;
        cin >> n;
        int a[n];
        FOR(i, 0, n) cin >> a[i];
        counting_sort(a, n);
    }

    return 0;
}
