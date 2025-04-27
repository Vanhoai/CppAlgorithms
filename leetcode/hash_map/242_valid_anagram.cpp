#include <iostream>
#include <sstream>
#include <string>
using namespace std;

bool isAnagram(string s, string t) {
    unordered_map<char, int> freq;
    for (char c : s)
        freq[c]++;

    for (char c : t)
        freq[c]--;

    for (auto &p : freq)
        if (p.second != 0)
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

        string s = words[0];
        string t = words[1];

        cout << (isAnagram(s, t) ? "Yes" : "No") << endl;
    }

    return 0;
}
