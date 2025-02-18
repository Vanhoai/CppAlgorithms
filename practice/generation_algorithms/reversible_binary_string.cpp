#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

/**
input
1
3

output:
000 010 101 111
*/

int n, ok, X[100];

void init() {
    for (int i = 1; i <= n; i++)
        X[i] = 0;
}

void gen() {
    int i = n;
    while (i >= 1 && X[i] == 1) {
        X[i] = 0;
        i--;
    }

    if (i == 0)
        ok = 0;
    else
        X[i] = 1;
}

bool check() {
    int L = 1, R = n;
    while (L < R) {
        if (X[L] != X[R])
            return false;

        L++;
        R--;
    }

    return true;
}

int main() {
    SETUP;

    int TC;
    cin >> TC;
    while (TC--) {
        cin >> n;
        init();
        ok = 1;
        while (ok) {
            if (check()) {
                for (int i = 1; i <= n; i++) {
                    cout << X[i];
                }

                cout << " ";
            }

            gen();
        }

        cout << endl;
    }

    return 0;
}