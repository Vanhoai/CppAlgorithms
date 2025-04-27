#include <iostream>
#include <sstream>
#include <string>
using namespace std;

bool canConstruct(string ransomNote, string magazine) {
    unordered_map<char, int> mp;
    for (char &c : magazine)
        mp[c]++;

    for (char &c : ransomNote)
        if (--mp[c] < 0)
            return false;

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
        string line;
        getline(cin, line);

        vector<string> words;
        stringstream ss(line);
        string w;
        while (ss >> w)
            words.push_back(w);

        string ransomNote = words[0];
        string magazine = words[1];

        cout << (canConstruct(ransomNote, magazine) ? "Yes" : "No") << endl;
    }

    return 0;
}
