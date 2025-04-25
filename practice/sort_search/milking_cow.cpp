#include <iostream>
using namespace std;

#define FOR(i, a, b)  for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= b; --i)

/**
 * Milking Cow
 *
 * input:
 *      T, N, M, A(i)
 *      1 ≤ T ≤ 100
 *      1 ≤ N, M ≤ 10^5
 *
 * output: print maximum milk
 *
 * @example
 *      input:
 *          2
 *          4
 *          4 4 4 4
 *          4
 *          2 1 4 3
 *      output:
 *          10
 *          6
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
        int n;
        cin >> n;
        int a[n];
        FOR(i, 0, n) cin >> a[i];

        sort(a, a + n, greater<int>());
        int res = 0;
        for (int i = 0; i < n; i++) {
            res += max(a[i] - i, 0);
        }

        cout << res << endl;
    }

    return 0;
}
