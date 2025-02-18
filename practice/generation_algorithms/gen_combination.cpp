#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

/**
input
2
4 3
5 3

output:
123 124 134 234
123 124 125 134 135 145 234 235 245 345

 */

int n, k, ok, g[100];

void init() { REP(i, 1, k) g[i] = i; }

void gen() {
    int i = k;
    while (i >= 1 && g[i] == n - k + i)
        i--;

    if (i == 0)
        ok = 0;
    else {
        g[i]++;
        for (int j = i + 1; j <= k; j++)
            g[j] = g[j - 1] + 1;
    }
}

int main() {
    SETUP;

    int TC;
    cin >> TC;
    while (TC--) {
        cin >> n >> k;
        init();

        ok = 1;
        while (ok) {
            REP(i, 1, k) cout << g[i];
            cout << " ";

            gen();
        }

        cout << endl;
    }

    return 0;
}