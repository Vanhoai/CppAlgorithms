#include <iostream>
#include <map>
#include <sstream>
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
