#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

/**
input
5
3 2 7 4 1

output:
1
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

int main() {
    SETUP;

    int TC;
    cin >> TC;
    while (TC--) {
        cin >> n;
        int W[100];
        for (int i = 1; i <= n; i++)
            cin >> W[i];
        init();
        ok = 1;

        ll res = 1e18;
        while (ok) {
            ll s1 = 0, s2 = 0;
            for (int i = 1; i <= n; i++) {
                if (X[i] == 0)
                    s1 += W[i];
                else
                    s2 += W[i];
            }

            res = min(res, abs(s1 - s2));
            gen();
        }

        cout << res << endl;
    }

    return 0;
}