#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

int n, X[100], used[100];

void out() {
    for (int i = 1; i <= n; i++)
        cout << X[i];
}

void backtracking(int i) {
    for (int j = 1; j <= n; j++) {
        if (used[j] == 0) {
            used[j] = 1;
            X[i] = j;
            if (i == n) {
                out();
                cout << endl;
            } else
                backtracking(i + 1);

            // backtrack
            used[j] = 0;
        }
    }
}

int main() {
    SETUP;

    cin >> n;
    memset(used, 0, sizeof(used));
    backtracking(1);

    return 0;
}