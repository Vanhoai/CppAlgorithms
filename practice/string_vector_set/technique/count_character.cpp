#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

/**
 * Count the number of letter, number, and special characters in a string
 *
 * input:
 *      T: number of test cases (1 <= T <= 100)
 *      S: string to be analyzed (size <= 1000)
 *
 * output: print the number of letter, number, and special characters in a
 * string
 *
 * @example
 *      input: Python 123@@
 *      output: 6 3 3
 */

int main() {
    SETUP;

    int TC;
    cin >> TC;
    cin.ignore();
    while (TC--) {
        string s;
        getline(cin, s);

        int letter = 0;
        int number = 0;
        int special = 0;

        for (int i = 0; i < s.size(); i++) {
            if (isalpha(s[i]))
                letter++;
            else if (isdigit(s[i]))
                number++;
            else
                special++;
        }

        cout << letter << " " << number << " " << special << endl;
    }

    return 0;
}