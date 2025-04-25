#include <iostream>
using namespace std;

#define FOR(i, a, b)  for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= b; --i)

/**
 * Count subset with k relative
 *
 * input:
 *      N, K
 *      1 ≤ N ≤ 100
 *      1 ≤ K ≤ 10^6
 *
 * output: print the number of subset
 *
 * @example
 *      input:
 *          4
 *          7 1
 *          2 6 1 7 3 4 9
 *          7 2
 *          2 6 1 7 3 4 9
 *          5 5
 *          15 1 20 4 17
 *          8 10
 *          100 200 300 400 500 600 700 800
 *      output:
 *          Case #1: 3: {1, 2, 3, 4}, {6, 7}, {9}
 *          Case #2: 1
 *          Case #3: 2
 *          Case #4: 8
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int TC;
    cin >> TC;
    int i = 1;
    while (i <= TC) {
        int n, k;
        cin >> n >> k;
        int a[n];
        FOR(i, 0, n) cin >> a[i];
        sort(a, a + n);

        int count = 1;
        for (int i = 0; i < n - 1; i++) {
            if (abs(a[i] - a[i + 1]) <= k)
                continue;
            else
                count++;
        }

        cout << "Case #" << i++ << ": " << count << endl;
    }

    return 0;
}
