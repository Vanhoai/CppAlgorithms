#include <iostream>
using namespace std;

#define FOR(i, a, b)  for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= b; --i)

/**
 * First index in array
 *
 * input:
 *      T, N, A(i)
 *      1 ≤ T ≤ 100
 *      1 ≤ N ≤ 10^5
 *
 * output: print index of first element in array
 *
 * @example
 *      input:
 *          2
 *          5 3
 *          1 2 3 3 3
 *          5 4
 *          1 1 2 5 6
 *      output:
 *          3
 *          -1
 */

int first(int a[], int n, int k) {
    int res = -1;
    int l = 0, r = n - 1;
    while (l <= r) {
        int m = (l + r) >> 1;
        if (a[m] == k) {
            res = m;
            r = m - 1;
        } else if (a[m] > k)
            r = m - 1;
        else
            l = m + 1;
    }

    if (res != -1)
        return res + 1;
    return res;
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
        int n, k;
        cin >> n >> k;
        int a[n];
        FOR(i, 0, n) cin >> a[i];

        int index = lower_bound(a, a + n, k) - a;
        if (a[index] != k)
            cout << -1 << endl;
        else
            cout << index + 1 << endl;

        cout << first(a, n, k) << endl;
    }

    return 0;
}
