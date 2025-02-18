#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

/**
 * Prefix Sum
 * a[i] = sum(a[j]) where j: 0 -> i
 *
 *
 * 11 3
 * 6 5 9 7 7 6 7 7 5 9 7
 * 1 9
 * 1 10
 * 0 8
 *
 * 62
 * 69
 * 59
 */

int main() {
    SETUP;

    int TC;
    cin >> TC;
    while (TC--) {
        int n, q;
        cin >> n >> q;
        int a[n];
        FOR(i, 0, n) cin >> a[i];

        ll prefix[n];
        prefix[0] = a[0];
        FOR(i, 1, n) prefix[i] = 1LL * a[i] + prefix[i - 1];

        FOR(i, 0, q) {
            int L, R;
            cin >> L >> R;
            if (L == 0)
                cout << prefix[R] << endl;
            else
                cout << prefix[R] - prefix[L - 1] << endl;
        }
    }

    return 0;
}