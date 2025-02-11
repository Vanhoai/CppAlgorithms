#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

/**
 * Traveler
 *
 * input:
 *      N, A(i)(j)
 *      1 <= N <= 15
 *      1 <= C(i) <= 100
 *
 * output: print the cost that person has to pay
 *
 * @example
 *      input:
 *          4
 *          0 20 35 10
 *          20 0 90 50
 *          35 90 0 12
 *          10 50 12 0
 *      output:
 *          117
 */

const int maxn = 15;
int n, A[maxn + 1][maxn + 1], X[100], cmin = 1e9 + 5, res = 0, ans = 1e9;
bool visited[maxn + 1];

void in() {
    cin >> n;
    REP(i, 1, n) REP(j, 1, n) {
        cin >> A[i][j];
        cmin = min(cmin, A[i][j]);
    }
}

void backtracking(int i) {
    for (int j = 2; j <= n; j++) {
        if (!visited[j]) {
            visited[j] = true;
            X[i] = j;
            res += A[X[i]][X[i - 1]];
            if (i == n)
                ans = min(ans, res + A[X[n]][1]);
            else if (res + cmin * (n - i + 1) < ans) {
                backtracking(i + 1);
            }

            visited[j] = false;
            res -= A[X[i]][X[i - 1]];
        }
    }
}

int main() {
    SETUP;

    in();
    memset(visited, false, sizeof(visited));
    X[1] = 1;
    backtracking(2);

    cout << ans << endl;
    return 0;
}