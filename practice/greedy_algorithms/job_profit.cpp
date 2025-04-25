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
 * Job & Profit
 *
 * input:
 *      T, N, A[i]
 *      1 ≤ T ≤ 100
 *      1 ≤ N ≤ 1000
 *      1 ≤ JobId ≤ 1000
 *      1 ≤ Deadline ≤ 1000
 *      1 ≤ Profit ≤ 1000.
 *
 * output: print the number job and profit
 *
 * @example
 *      input:
 *          2
 *          4
 *          1 4 20
 *          2 1 10
 *          3 1 40
 *          4 1 30
 *          5
 *          1 2 100
 *          2 1 19
 *          3 2 27
 *          4 1 25
 *          5 1 15
 *      output:
 *          2 60
 *          2 127
 */

struct Job {
    int id;
    int deadline;
    int profit;
};

bool cmp(Job a, Job b) { return a.profit > b.profit; };

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
        Job a[n];
        FOR(i, 0, n) cin >> a[i].id >> a[i].deadline >> a[i].profit;
        sort(a, a + n, cmp);

        bool used[n];
        int mark[n];
        ms(used, false);
        ms(mark, 0);

        int sum = 0;
        FOR(i, 0, n) FORD(j, a[i].deadline - 1, 0) {
            if (used[j] == false) {
                used[j] = true;
                mark[j] = i;
                sum += a[i].profit;
                break;
            }
        }

        int count = 0;
        FOR(i, 0, n) if (used[i]) count++;

        cout << count << " " << sum << endl;
    }

    return 0;
}
