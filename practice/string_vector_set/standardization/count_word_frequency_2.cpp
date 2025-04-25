#include <iostream>
#include <map>
#include <sstream>
using namespace std;

/**
 * input: PYTHON Java php php java pyTHON C
 * output: c 1 java 2 php 2 python 2
 */

void string_tolower(string &s) {
    for (int i = 0; i < s.size(); i++)
        s[i] = tolower(s[i]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

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

        for (auto it : mp) {
            cout << it.first << " " << it.second << endl;
        }

        cout << endl;
    }

    return 0;
}
