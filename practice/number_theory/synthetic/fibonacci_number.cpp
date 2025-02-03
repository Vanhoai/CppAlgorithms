#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

/**
 * Fibonacci Number
 *
 * output: YES/NO
 *
 * @example
 *      input: 420196140727489673
 *      output: YES
 */

ll f[100];

void init() {
    f[0] = 0;
    f[1] = 1;
    for (int i = 2; i <= 92; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }
}

int main() {
    SETUP;
    init();

    int TC;
    cin >> TC;
    while (TC--) {
        ll N;
        cin >> N;

        bool check = false;
        for (int i = 0; i <= 92; i++) {
            if (N == f[i]) {
                check = true;
                break;
            }
        }

        cout << (check ? "YES" : "NO") << endl;
    }

    return 0;
}