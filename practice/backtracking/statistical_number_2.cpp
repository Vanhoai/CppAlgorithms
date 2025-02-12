#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

/**
 * Statistical Number 2
 *
 * input:
 *      T, N
 *      1 ≤ T, N ≤ 10
 *
 * output: print all way statistical number (partition)
 *
 * @example
 *      input:
 *          1
 *          4
 *      output:
 *          (5)(4 1)(3 2)(3 1 1)(2 2 1)(2 1 1 1)(1 1 1 1)
 */

int n, X[100];
vector<vector<int>> res;

void backtracking(int sum, int i, int pos) {
    if (sum == n) {
        vector<int> tmp(X + 1, X + i);
        res.push_back(tmp);
        return;
    }

    for (int k = pos; k >= 1; k--) {
        if (sum + k <= n) {
            X[i] = k;
            backtracking(sum + k, i + 1, k);
        }
    }
}

int main() {
    SETUP;

    int TC;
    cin >> TC;
    while (TC--) {
        cin >> n;
        res.clear();
        backtracking(0, 1, n);

        cout << res.size() << endl;
        for (int i = 0; i < res.size(); i++) {
            cout << "(";
            for (int k = 0; k < res[i].size(); k++) {
                cout << res[i][k];
                if (k == res[i].size() - 1)
                    cout << ")";
                else
                    cout << " ";
            }
        }

        cout << endl;
    }

    return 0;
}