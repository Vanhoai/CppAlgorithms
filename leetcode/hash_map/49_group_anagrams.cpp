#include <iostream>
#include <sstream>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs) {
    unordered_map<string, vector<string>> anagramGroups;

    for (const auto &word : strs) {
        string sortedWord = word;
        sort(sortedWord.begin(), sortedWord.end());
        anagramGroups[sortedWord].push_back(word);
    }

    vector<vector<string>> result;
    for (const auto &pair : anagramGroups)
        result.push_back(pair.second);

    return result;
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
        string token;
        vector<string> words;
        while (ss >> token)
            words.push_back(token);

        vector<vector<string>> result = groupAnagrams(words);
        for (const auto &group : result) {
            for (const auto &word : group)
                cout << word << " ";
            cout << endl;
        }
    }

    return 0;
}
