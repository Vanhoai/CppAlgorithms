#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

/**
input
2
010101
111111

output:
010110
000000

 */

int n, X[100], ok;

void init(string s) {
    n = s.size();
    REP(i, 1, n) { X[i] = s[i - 1] - '0'; }
}

void gen_next() {
    int i = n;
    while (i >= 1 && X[i] == 1) {
        X[i] = 0;
        i--;
    }

    if (i == 0)
        ok = 0;
    else {
        X[i] = 1;
    }
}

int main() {
    SETUP;

    int TC;
    cin >> TC;
    cin.ignore();
    while (TC--) {
        string s;
        getline(cin, s);
        init(s);
        gen_next();

        ok = 1;

        if (!ok) {
            for (int i = 1; i <= n; i++)
                cout << "0";
        } else {
            for (int i = 1; i <= n; i++)
                cout << X[i];
        }

        cout << endl;
    }

    return 0;
}