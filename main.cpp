#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

/**
 * C(n, k) = C(n - 1, k -1) + C(n - 1, k)
 * Base in pascal triangle
 */

ll C[1001][1001];

void init() {
    for (int i = 0; i <= 1000; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                C[i][j] = 1;
            } else {
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
                C[i][j] %= 1000000007;
            }
        }
    }
}

int main() {
    SETUP;
    init();

    int TC;
    cin >> TC;
    while (TC--) {
        int n, k;
        cin >> n >> k;
        cout << C[n][k] << endl;
    }

    return 0;
}