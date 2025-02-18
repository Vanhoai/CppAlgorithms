#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

/**
 * Standardization Name
 *
 * input:
 *      T: number of test cases (1 <= T <= 100)
 *      S: string (size <= 1000)
 *
 * output: print string after standardization
 *
 * @example
 *      input: NguYEN VAN maNH
 *      output: Nguyen Van Manh
 */

string format(string s) {
    char f = toupper(s[0]);
    s[0] = f;

    for (int i = 1; i < s.size(); i++)
        s[i] = tolower(s[i]);

    return s;
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
            cout << format(word) << " ";
        }

        cout << endl;
    }

    return 0;
}