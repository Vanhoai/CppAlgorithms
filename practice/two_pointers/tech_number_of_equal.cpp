#include <iostream>
using namespace std;

#define FOR(i, a, b)  for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= b; --i)

/**
 * Tech number of equal
 *
 * input:
 *      1<=N,M<=10^7
 *      1<=A[i],B[i]<= 10^9
 *
 * output: print the number of pair i, j with a[i] = b[i]
 *
 * @example
 *      input:
 *          6 7
 *          3 3 3 4 7 9
 *          2 3 3 5 6 9 10
 *
 *      output:
 *          7
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    int a[n], b[m];

    FOR(i, 0, n - 1) cin >> a[i];
    FOR(i, 0, m - 1) cin >> b[i];

    int i = 0, j = 0;
    int res = 0;

    while (i < n && j < m) {
        if (a[i] < b[j])
            i++;
        else if (a[i] > b[j])
            j++;
        else {
            int i1 = i, j1 = j, k1 = 0, k2 = 0;

            while (a[i1] == a[i]) {
                k1++;
                i1++;
            }

            while (b[j1] == b[j]) {
                k2++;
                j1++;
            }

            res += k1 * k2;
            i += k1;
            j += k2;
        }
    }

    cout << res << endl;

    return 0;
}
