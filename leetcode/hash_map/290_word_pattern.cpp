#include <iostream>
#include <map>
#include <sstream>
using namespace std;

#define FOR(i, a, b)  for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= b; --i)

bool wordPattern(string pattern, string s) {
    vector<string> words;
    stringstream ss(s);
    string word;
    while (ss >> word)
        words.push_back(word);

    if (words.size() != pattern.size())
        return false;

    map<char, string> mp;
    map<string, char> mw;

    for (int i = 0; i < pattern.size(); i++) {
        if (mp.find(pattern[i]) == mp.end() && mw.find(words[i]) == mw.end()) {
            mp[pattern[i]] = words[i];
            mw[words[i]] = pattern[i];
        } else {
            if (mp[pattern[i]] != words[i] || mw[words[i]] != pattern[i])
                return false;
        }
    }

    return true;
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
        string pattern, s;
        getline(cin, pattern);
        getline(cin, s);
        cout << wordPattern(pattern, s) << endl;
    }

    return 0;
}
