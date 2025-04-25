#include <iostream>
using namespace std;

#define FOR(i, a, b)  for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= b; --i)

/**
 *  Print To Shape
 *
 * input:
 *      T, N
 *      1 ≤ T ≤ 100
 *      1 ≤ n ≤ 10^3
 *
 * output: print arrray sorted
 *
 * @example
 *      input:
 *          2
 *          7
 *          7 1 2 3 4 5 6
 *          8
 *          1 6 9 4 3 7 8 2
 *      output:
 *          7 1 6 2 5 3 4
 *          9 1 8 2 7 3 6 4
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

        sort(a, a + n);
        int i = 0, j = n - 1;
        while (i < j) {
            cout << a[j] << " " << a[i] << " ";
            i++;
            j--;
        }

        if (i == j)
            cout << a[i];
        cout << endl;
    }

    return 0;
}
