#include <iostream>
using namespace std;

/**
 * Build prefix sum array
 *
 * input:
 *      1<=N<=10^6
 *      1<=A[i]<=10^9
 *
 * output: print prefix sum
 *
 * @example
 *      input:
 *          6
 *          8 7 6 5 6 6
 *      output:
 *          8 15 21 26 32 38
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int f[n];
    f[0] = a[0];
    for (int i = 1; i < n; i++)
        f[i] = f[i - 1] + a[i];

    for (int i = 0; i < n; i++)
        cout << f[i] << " ";
    cout << endl;

    return 0;
}
