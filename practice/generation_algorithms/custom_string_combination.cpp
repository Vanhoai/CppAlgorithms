#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

/**
input
D 2

output:
AA
AB
AC
AD
BB
BC
BD
CC
CD
DD

*/

int n, k, ok;
char C, X[100];

void init() {
    for (int i = 1; i <= k; i++)
        X[i] = 'A';
}

void gen() {
    int i = k;
    while (i >= 1 && X[i] == C)
        i--;

    if (i == 0)
        ok = 0;
    else {
        X[i]++;
        for (int j = i + 1; j <= k; j++)
            X[j] = X[i];
    }
}

int main() {
    SETUP;

    cin >> C >> k;
    n = C - 'A' + 1;

    init();

    ok = 1;
    while (ok) {
        for (int i = 1; i <= k; i++)
            cout << X[i];

        cout << endl;
        gen();
    }

    return 0;
}