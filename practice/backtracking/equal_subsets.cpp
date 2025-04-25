#include <iostream>
using namespace std;

/**
 * Equal subsets
 *
 * input:
 *      T: number testcase 1 <= T <= 100
 *      N: size of array 1 <= N <= 100
 *      A[i] <= 100
 *
 * output: YES/NO
 *
 * @example
 *      input:
 *          2
 *          4
 *          1 5 11 5
 *          3
 *          1 3 5
 *      output:
 *          YES
 *          NO
 */

void solve() {
    int n;
    cin >> n;
    int a[n];

    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    if (sum % 2) {
        cout << "NO\n";
        return;
    }

    bool mark[sum / 2 + 1];
    for (int i = 0; i < n; i++) {
        for (int j = sum / 2; j >= a[i]; j--) {
            if (mark[j - a[i]] == 1 || j == a[i]) {
                mark[j] = true;
            }
        }
    }

    if (mark[sum / 2])
        cout << "YES\n";
    else
        cout << "NO\n";
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
        solve();
    }

    return 0;
}
