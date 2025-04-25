#include <iostream>
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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

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
