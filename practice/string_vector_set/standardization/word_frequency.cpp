#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

/**
 * Word Frequency
 *
 * input:
 *      T: number of test cases (1 <= T <= 100)
 *      S: string (size <= 1000)
 *
 * output: print all word exists in string
 *
 * @example
 *      input: Python     Java  C++ PHP JS
 *      output: Python Java C++ PHP JS
 */

int main() {
    SETUP;

    int TC;
    cin >> TC;
    cin.ignore();
    while (TC--) {
        string s;
        getline(cin, s);

        stringstream ss(s);
        string word;

        while (ss >> word) {
            cout << word << endl;
        }
    }

    return 0;
}