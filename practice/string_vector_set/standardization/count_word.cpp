#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

/**
 * Count Word
 *
 * input:
 *      T: number of test cases (1 <= T <= 100)
 *      S: string (size <= 1000)
 *
 * output: the number of words in string
 *
 * @example
 *      input: Python     Java  C++ PHP JS
 *      output: 5
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

        int count = 0;

        while (ss >> word)
            count++;

        cout << count << endl;
    }

    return 0;
}