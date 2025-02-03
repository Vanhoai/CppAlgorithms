#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

/**
 * Square Number in range
 *
 *
 * input:
 *      T: number of testcases (1 <= T <= 100)
 *      L, R: range of number (1 ≤ a ≤ b ≤ 10^6)
 *
 * output: print all square number in range
 *
 * @example
 *      input: 10 20
 *      output: 16
 */

int main() {
    SETUP;

    int TC;
    cin >> TC;
    while (TC--) {
        int L, R;
        cin >> L >> R;

        int c1 = sqrt(L);
        int c2 = sqrt(R);

        if (c1 * c1 != L)   // check L if not square
            ++c1;

        for (int i = c1; i <= c2; i++) {
            cout << i * i << " ";
        }

        cout << endl;
    }

    return 0;
}