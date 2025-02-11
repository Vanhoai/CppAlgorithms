#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

/**
 * Prime Numbers
 *
 * input:
 *      N, P, S
 *      1 ≤ T ≤100
 *      1 ≤ N ≤ 10
 *      2 ≤ S, P ≤200
 *
 * output: print n subset with element is prime and sum equal s
 *
 * @example
 *      input:
 *          2
 *          2 7 28
 *          3 2 23
 *      output:
 *          1
 *          11 17
 *          2
 *          3 7 13
 *          5 7 11
 */

int n, p, s, ans, X[100];
vector<int> primes;
vector<vector<int>> res;

void input() {
    cin >> n >> p >> s;
    res.clear();
    primes.clear();

    for (int i = p + 1; i <= s; i++) {
        if (PRIME(i))
            primes.push_back(i);
    }
}

void backtracking(int i, int pos, int sum) {
    if (i == n && sum == s) {
        vector<int> tmp(X, X + n);
        res.push_back(tmp);
        return;
    }

    for (int j = pos; j <= primes.size(); j++) {
        if (sum + primes[j] <= s) {
            X[i] = primes[j];
            backtracking(i + 1, j + 1, sum + X[i]);
        }
    }
}

int main() {
    SETUP;

    int TC;
    cin >> TC;
    while (TC--) {
        input();
        backtracking(0, 0, 0);

        cout << res.size() << endl;
        REP(i, 0, res.size() - 1) {
            REP(j, 0, res[i].size() - 1) cout << res[i][j] << " ";
            cout << endl;
        }
    }

    return 0;
}