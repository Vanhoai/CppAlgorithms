#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

/**
 * Subsequence with sum equal to K
 *
 * input:
 *      T: number testcase 1 <= T <= 100
 *      N: size of array 1 <= N <= 10
 *      K: target sum 1 <= K
 *      A[i] <= 100
 *
 * output: print all array from A[] satisfy
 *
 * @example
 *      input:
 *          2
 *          5 50
 *          5 10 15 20 25
 *          8 53
 *          15 22 14 26 32 9 16 8
 *      output:
 *          [5 10 15 20] [5 20 25] [10 15 25]
 *          [8 9 14 22] [8 14 15 16] [15 16 22]
 */

const int maxn = 11;
int n, k, sum, ok, A[maxn], X[maxn];

void input() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> A[i];

    sort(A + 1, A + n + 1);
}

/**
 * i: index mark for X[i]
 * pos: index mark for A[i] // case gen
 */
void backtracking(int i, int pos) {
    for (int j = pos; j <= n; j++) {
        X[i] = A[j];
        sum += A[j];

        if (sum == k) {
            ok = 1;
            for (int b = 1; b <= i; b++)
                cout << X[b] << " ";
            cout << endl;
        } else {
            backtracking(i + 1, j + 1);
        }

        sum -= A[j];
    }
}

int main() {
    SETUP;

    int TC;
    cin >> TC;
    while (TC--) {
        input();

        ok = 0;
        sum = 0;
        backtracking(1, 1);
        if (!ok)
            cout << "-1\n";
    }

    return 0;
}