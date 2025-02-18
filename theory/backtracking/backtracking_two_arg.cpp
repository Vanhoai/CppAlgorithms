#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

int n, k, sum, X[100], A[100];

void backtracking(int i, int pos) {
    for (int j = pos; j <= n; j++) {
        X[i] = A[j];
        sum += A[j];
        if (sum == k) {
            for (int b = 1; b <= i; b++)
                cout << X[b] << " ";
            cout << endl;
        } else {
            backtracking(i + 1, j + 1);
        }

        // backtrack
        sum -= A[j];
    }
}

int main() {
    SETUP;

    int TC;
    cin >> TC;
    while (TC--) {
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
            cin >> A[i];

        sum = 0;
        X[0] = 0;
        backtracking(1, 1);
    }

    return 0;
}