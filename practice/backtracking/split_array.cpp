#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

/**
 * Split Array
 *
 * input:
 *      T, N, K, A(i)
 *      1 ≤ T ≤ 100
 *      1 ≤ N, K ≤ 20
 *      0 ≤ A(i) ≤ 100
 *
 * output: print 1 if possible, otherwise print 0
 *
 * @example
 *      input:
 *          2
 *          5 3
 *          2 1 4 5 6
 *          5 3
 *          2 1 5 5 6
 *      output:
 *          1
 *          0
 */

int n, k, s, ans, A[100];
bool visited[100];

void backtracking(int sum, int count) {
    if (count == k && sum == s) {
        ans = 1;
        return;
    }

    if (ans)
        return;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            if (sum == s) {
                backtracking(0, count + 1);
            } else if (sum + A[i] <= s) {
                backtracking(sum + A[i], count);
            }
        }

        visited[i] = false;
    }
}

void solve() {
    cin >> n >> k;

    s = 0;
    REP(i, 1, n) {
        cin >> A[i];
        s += A[i];
    }

    if (s % k != 0) {
        cout << "0\n";
        return;
    }

    s /= k;
    memset(visited, false, sizeof(visited));

    ans = 0;

    backtracking(0, 0);
    cout << ans << endl;
}

int main() {
    SETUP;

    int TC;
    cin >> TC;
    while (TC--) {
        solve();
    }

    return 0;
}