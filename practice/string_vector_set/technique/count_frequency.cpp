#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

/**
 * Count Frequency
 *
 * input:
 *      T: number of test cases (1 <= T <= 100)
 *      S: string to be analyzed (size <= 1000)
 *
 * output: print char and frequency
 *
 * @example
 *      input: aaababca
 *      output: a 5 b 2 c 1
 */

int main() {
    SETUP;

    int TC;
    cin >> TC;
    cin.ignore();
    while (TC--) {
        string s;
        getline(cin, s);

        int a[256];
        memset(a, 0, sizeof(a));

        for (int i = 0; i < s.size(); i++)
            a[s[i]]++;

        for (int i = 0; i < 256; i++) {
            if (a[i]) {
                cout << (char) i << " " << a[i] << endl;
            }
        }

        cout << endl;
    }

    return 0;
}