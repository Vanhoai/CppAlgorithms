#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

/**
 * Expression
 *
 * input:
 *      A, B, C, D, E <= 100
 *      [[[A o(1) B] o(2) C] o(3) D] o(4) E = 23
 *      o: +, -, *
 *
 * output: YES/NO
 *
 * @example
 *      input:
 *          3
 *          1 1 1 1 1
 *          1 2 3 4 5
 *          2 3 5 7 11
 *      output:
 *          NO
 *          YES
 *          YES
 */

int n, ok, X[100], A[6];
vector<vector<int>> pers, ckn;

void backtracking(int i) {
    REP(j, 1, 3) {
        X[i] = j;
        if (i == 4) {
            vector<int> tmp(X + 1, X + i + 1);
            ckn.push_back(tmp);
        } else
            backtracking(i + 1);
    }
}

void init() {
    int a[5] = {1, 2, 3, 4, 5};
    do {
        vector<int> tmp(a, a + 5);
        pers.push_back(tmp);
    } while (next_permutation(a, a + 5));

    backtracking(1);
}

void solve() {
    for (int i = 1; i <= 5; i++)
        cin >> A[i];

    ok = false;
    for (auto per : pers) {
        for (auto c : ckn) {
            int res = A[per[0]];
            for (int k = 0; k < 4; k++) {
                if (c[k] == 1) {   // +
                    res += A[per[k + 1]];
                } else if (c[k] == 2) {
                    res -= A[per[k + 1]];
                } else {
                    res *= A[per[k + 1]];
                }
            }

            if (res == 23) {
                ok = true;
                break;
            }
        }

        if (ok)
            break;
    }

    if (ok)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main() {
    SETUP;

    init();

    int TC;
    cin >> TC;
    while (TC--) {
        solve();
    }

    return 0;
}