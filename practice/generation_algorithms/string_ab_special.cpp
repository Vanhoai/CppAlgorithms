#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

/**
input
1
5 3

output:
AAABA
AAABB
ABAAA
BAAAB
BBAAA

 */

int n, k, ok, g[100];

void init() { REP(i, 1, n) g[i] = 0; }

void gen() {
    int i = n;
    while (i >= 1 && g[i] == 1) {
        g[i] = 0;
        i--;
    }

    if (i == 0)
        ok = 0;
    else
        g[i] = 1;
}

int check() {
    int count = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (g[i] == 0)
            count++;
        else
            count = 0;

        if (count > k)
            return 0;
        if (count == k)
            ans++;
    }

    return ans == 1;
}

int main() {
    SETUP;

    int TC;
    cin >> TC;
    while (TC--) {
        cin >> n >> k;

        ok = 1;
        while (ok) {
            if (check()) {
                for (int i = 1; i <= n; i++) {
                    if (g[i] == 0)
                        cout << "A";
                    else
                        cout << "B";
                }

                cout << " ";
            }

            gen();
        }

        cout << endl;
    }

    return 0;
}