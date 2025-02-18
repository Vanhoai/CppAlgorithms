#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

/**
input
2
5
1 2 3 4 5
5
5 4 3 2 1

output:
1 2 3 5 4
1 2 3 4 5

 */

int n, ok, X[100];

void gen() {
    int i = n - 1;
    while (i >= 1 && X[i] > X[i + 1])
        i--;

    if (i == 0)
        ok = 0;
    else {
        int j = n;
        while (X[i] > X[j])
            j--;

        swap(X[i], X[j]);
        reverse(X + i + 1, X + n + 1);
    }
}

int main() {
    SETUP;

    int TC;
    cin >> TC;
    while (TC--) {
        cin >> n;
        REP(i, 1, n) {
            int x;
            cin >> x;
            X[i] = x;
        }

        ok = 1;
        gen();

        if (!ok)
            REP(i, 1, n) cout << i << " ";
        else
            REP(i, 1, n) cout << X[i] << " ";

        cout << endl;
    }

    return 0;
}