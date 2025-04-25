#include <iostream>
using namespace std;

/**
 * Pascal Triangle
 *
 * input:
 *      T: number of testcases (1 <= T <= 100)
 *      N: hight of triangle (1 <= N <= 100)
 *
 * output: print triangle
 *
 * @example
 *      input: 6
 *      output:
 *      1
 *      1 1
 *      1 2 1
 *      1 3 3 1
 *      1 4 6 4 1
 *      1 5 10 10 5 1
 */

void solve(int n) {
    int a[n + 1][n + 1];
    memset(a, 0, sizeof(a));

    for (int i = 1; i <= n; i++) {
        a[i][1] = 1;
        a[i][i] = 1;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= n; j++) {
            a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j]) {
                cout << a[i][j] << " ";
            }
        }
        cout << endl;
    }
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

        solve(n);
    }

    return 0;
}
