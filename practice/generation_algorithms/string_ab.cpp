#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

/**
input
2
2
3

output:
AA AB BA BB
AAA AAB ABA ABB BAA BAB BBA BBB

 */

int n, ok;
char g[100];

void init() { REP(i, 1, n) g[i] = 'A'; }

void gen() {
    int i = n;
    while (i >= 1 && g[i] == 'B') {
        g[i] = 'A';
        i--;
    }

    if (i == 0)
        ok = 0;
    else
        g[i] = 'B';
}

int main() {
    SETUP;

    int TC;
    cin >> TC;
    while (TC--) {
        cin >> n;

        ok = 1;
        while (ok) {
            REP(i, 1, n) cout << (char) g[i];
            cout << " ";

            gen();
        }

        cout << endl;
    }

    return 0;
}