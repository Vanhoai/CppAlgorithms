#include <iostream>
#include <set>
#include <sstream>
using namespace std;

/**
 * input:
 * lap trinh python java python c lap trinh
 * trinh php java
 * output: c lap python
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
        string s1, s2;
        getline(cin, s1);
        getline(cin, s2);

        stringstream ss1(s1);
        stringstream ss2(s2);
        string word;

        set<string> se;
        while (ss1 >> word)
            se.insert(word);

        while (ss2 >> word)
            se.erase(word);

        for (string w : se)
            cout << w << " ";

        cout << endl;
    }

    return 0;
}
