#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

/**
 * Count Frequency
 * Print out the letters and their number of occurrences in the order they
 * appear in the string.
 *
 * input:
 *      T: number of test cases (1 <= T <= 100)
 *      S: string to be analyzed (size <= 1000)
 *
 * output: print char and frequency
 *
 * @example
 *      input: aaababca
 *      output: b 2 a 5 c 1
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

        for (char c : s) {
            if (a[c]) {
                cout << c << " " << a[c] << endl;
                a[c] = 0;
            }
        }

        cout << endl;
    }

    return 0;
}