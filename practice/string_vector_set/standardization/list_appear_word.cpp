#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

/**
 * input: PYTHON Java php php java pyTHON C
 * output: python java php c
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

        set<string> se;

        while (ss >> word) {
            string_tolower(word);
            se.insert(word);
        }

        for (string w : se) {
            cout << w << " ";
        }

        cout << endl;
    }

    return 0;
}