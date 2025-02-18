#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

/**
 * Upper Word
 *
 * input:
 *      T: number of test cases (1 <= T <= 100)
 *      S: string (size <= 1000)
 *
 * output: print all word uppercase in string
 *
 * @example
 *      input: Python Java C++ PHP JS
 *      output: PHP JS
 */

bool check(string s) {
    for (int i = 0; i < s.size(); i++) {
        if (!isupper(s[i]))
            return false;
    }

    return true;
}

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
            if (check(word))
                cout << word << " ";
        }

        cout << endl;
    }

    return 0;
}