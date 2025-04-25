#include <iostream>
#include <set>
#include <sstream>
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
