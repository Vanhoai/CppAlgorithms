#include <iostream>
using namespace std;

#define FOR(i, a, b)  for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= b; --i)

/**
 * Mergesort
 *
 * input:
 *      T, N, A(i)
 *      1 ≤ T ≤ 100
 *      1 ≤ N ≤ 10^5
 *
 * output: print sorted array
 *
 * @example
 *      input:
 *          4 4
 *          1 2 4 6
 *          3 5 8 9
 *      output:
 *          b1 b2 c1 b3 c2 b4 c3 c4
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    int b[n], c[m];
    FOR(i, 1, n + 1) cin >> b[i];
    FOR(i, 1, m + 1) cin >> c[i];

    int i = 1;
    int j = 1;
    while (i <= n && j <= m) {
        if (b[i] <= c[j]) {
            cout << "b" << i++ << " ";
        } else {
            cout << "c" << j++ << " ";
        }
    }

    while (i <= n) {
        cout << "b" << i++ << " ";
    }

    while (j <= m) {
        cout << "c" << j++ << " ";
    }

    return 0;
}
