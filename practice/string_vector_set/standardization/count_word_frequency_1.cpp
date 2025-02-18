#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

/**
 * input: PYTHON Java php php java pyTHON C
 * output: python 2 java 2 php 2 c 1
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

        vector<string> v;

        while (ss >> word) {
            string_tolower(word);
            v.push_back(word);
        }

        map<string, int> mp;
        for (string w : v)
            mp[w]++;

        for (int i = 0; i < v.size(); i++) {
            if (mp[v[i]]) {
                cout << v[i] << " " << mp[v[i]] << endl;
                mp[v[i]] = 0;
            }
        }

        cout << endl;
    }

    return 0;
}