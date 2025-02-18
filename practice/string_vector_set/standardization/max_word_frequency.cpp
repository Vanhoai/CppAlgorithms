#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

/**
 * input: PYTHON Java php php java pyTHON C
 * output: java 2
 */

void string_tolower(string &s) {
    for (int i = 0; i < s.size(); i++)
        s[i] = tolower(s[i]);
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

        map<string, int> mp;

        while (ss >> word) {
            string_tolower(word);
            mp[word]++;
        }

        int max = 0;
        string res = "";
        for (auto it : mp) {
            if (it.second > max) {
                max = it.second;
                res = it.first;
            }
        }

        cout << res << " " << max << endl;
    }

    return 0;
}