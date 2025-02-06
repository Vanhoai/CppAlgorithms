#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

/**
 * Sort Characters
 *
 * input:
 *      T: number of test cases (1 <= T <= 100)
 *      S: string (size <= 1000)
 *
 * output: print sorted characters in string
 *
 * @example
 *      input: aazabcd
 *      output: aaabcdz
 */

int main() {
    SETUP;

    int TC;
    cin >> TC;
    cin.ignore();
    while (TC--) {
        string s;
        getline(cin, s);
        sort(s.begin(), s.end());

        cout << s << endl;
    }

    return 0;
}