#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

/**
input
2
5 3
1 4 5
5 3
3 4 5

output:
2 3 4
1 2 3

 */

int n, k, ok, X[100];

void gen() {
    int i = k;
    while (i >= 1 && X[i] == n - k + i)
        i--;

    if (i == 0)
        ok = 0;
    else {
        X[i]++;
        for (int j = i + 1; j <= k; j++)
            X[j] = X[j - 1] + 1;
    }
}

int main() {
    SETUP;

    int TC;
    cin >> TC;
    while (TC--) {
        cin >> n >> k;
        REP(i, 1, k) {
            int x;
            cin >> x;
            X[i] = x;
        }

        ok = 1;
        gen();

        if (ok) {
            for (int i = 1; i <= k; i++)
                cout << X[i] << " ";
        } else {
            for (int i = 1; i <= k; i++)
                cout << i << " ";
        }

        cout << endl;
    }

    return 0;
}