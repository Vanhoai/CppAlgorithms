#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

int n, k, X[100];

void out() {
    for (int i = 1; i <= k; i++)
        cout << X[i];
}

void backtracking(int i) {
    for (int j = X[i - 1] + 1; j <= n - k + i; j++) {
        X[i] = j;
        if (i == k) {
            out();
            cout << endl;
        } else {
            backtracking(i + 1);
        }
    }
}

int main() {
    SETUP;

    cin >> n >> k;
    backtracking(1);

    return 0;
}