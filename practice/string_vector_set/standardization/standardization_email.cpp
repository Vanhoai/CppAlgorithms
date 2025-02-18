#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

/**
 * Standardization Email
 *
 * input:
 *      T: number of test cases (1 <= T <= 100)
 *      S: string (size <= 1000)
 *
 * output: print string after standardization
 *
 * @example
 *      input: NguYEN VAN maNH
 *      output: manhnv@gmail.com
 */

string format_lower(string s) {
    string res = "";
    for (int i = 0; i < s.size(); i++)
        res += tolower(s[i]);

    return res;
}

string format(string s) {
    stringstream ss(s);
    string w;

    vector<string> words;
    while (ss >> w)
        words.push_back(w);

    string res = format_lower(words[words.size() - 1]);
    for (int i = 0; i < words.size() - 1; i++)
        res += tolower(words[i][0]);

    return res + "@gmail.com";
}

int main() {
    SETUP;

    int TC;
    cin >> TC;
    cin.ignore();
    while (TC--) {
        string s;
        getline(cin, s);

        cout << format(s) << endl;
    }

    return 0;
}