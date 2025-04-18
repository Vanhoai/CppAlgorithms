#include <iostream>
#include <sstream>
#include <string>
using namespace std;

#define FOR(i, a, b)  for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= b; --i)

string reverseWords(string s) {
    stringstream ss(s);
    string w;
    vector<string> words;
    while (ss >> w)
        words.push_back(w);

    string res = "";
    for (int i = words.size() - 1; i >= 0; i--) {
        res += words[i];
        if (i > 0)
            res += " ";
    }

    return res;
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
        cout << reverseWords(s) << endl;
    }

    return 0;
}
