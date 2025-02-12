#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

/**
 * Missing Math
 *
 * input:
 *      A, B
 *      1 ≤ A, B ≤ 1 000 000
 *
 * output: print two number is min and max after change
 *
 * @example
 *      input:
 *          11 25
 *      output:
 *          36 37
 */

int main() {
    SETUP;

    int TC;
    cin >> TC;
    while (TC--) {
        int a, b;
        cin >> a >> b;

        // make sure a < b
        if (a > b)
            swap(a, b);

        string sa = to_string(a);
        string sb = to_string(b);

        for (int i = 0; i < sa.size(); i++) {
            if (sa[i] == '6')
                sa[i] = '5';
        }

        for (int i = 0; i < sb.size(); i++) {
            if (sb[i] == '6')
                sb[i] = '5';
        }

        int mn = abs(stoi(sb) + stoi(sa));

        for (int i = 0; i < sa.size(); i++) {
            if (sa[i] == '5')
                sa[i] = '6';
        }

        for (int i = 0; i < sb.size(); i++) {
            if (sb[i] == '5')
                sb[i] = '6';
        }

        int mx = abs(stoi(sb) + stoi(sa));
        cout << mn << " " << mx << endl;
    }

    return 0;
}
