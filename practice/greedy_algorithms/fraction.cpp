#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

/**
 * Fraction
 *
 * input:
 *      T, P, Q
 *      1 ≤ T ≤ 100
 *      1 ≤ P, Q ≤ 100.
 *
 * output: print answers
 *
 * @example
 *      input:
 *          2
 *          2 3
 *          1 3
 *      output:
 *          1/2 + 1/6
 *          1/3
 *
 */

void backtracking(int p, int q) {
    if (q % p == 0) {
        cout << "1/" << q / p << endl;
        return;
    }

    ll x = q / p + 1;
    cout << "1/" << x << " + ";
    ll q_new = q * x;
    ll p_new = p * x - q;
    backtracking(p_new, q_new);
}

int main() {
    SETUP;

    int TC;
    cin >> TC;
    while (TC--) {
        int p, q;
        cin >> p >> q;
        backtracking(p, q);
    }

    return 0;
}
