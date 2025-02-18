#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

/**
 * Sort Word
 *
 * input:
 *      T: number of test cases (1 <= T <= 100)
 *      S: string (size <= 1000)
 *
 * output: print sorted word in string
 *
 * @example
 *      input: aa abc aaa a bc z
 *      output: a aa aaa abc bc z
 */

int main() {
    SETUP;

    int TC;
    cin >> TC;
    cin.ignore();
    while (TC--) {
        string s;
        getline(cin, s);

        vector<string> v;
        stringstream ss(s);
        string word;

        while (ss >> word)
            v.push_back(word);

        sort(v.begin(), v.end());

        for (string w : v)
            cout << w << " ";

        cout << endl;
    }

    return 0;
}