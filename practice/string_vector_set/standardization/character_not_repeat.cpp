#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

/**
input: ABCDEABC
output: DE
*/

int main() {
    SETUP;

    int TC;
    cin >> TC;
    cin.ignore();
    while (TC--) {
        string s;
        getline(cin, s);

        map<char, int> mp;
        for (int i = 0; i < s.size(); i++)
            mp[s[i]]++;

        for (auto it : mp) {
            if (it.second == 1)
                cout << it.first;
        }

        cout << endl;
    }

    return 0;
}