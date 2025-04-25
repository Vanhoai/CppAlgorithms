#include <iostream>
using namespace std;

/**
input:
    abcde
    azhuywfjalzabcde

output: YES
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
        string s1;
        string s2;
        getline(cin, s1);
        getline(cin, s2);

        if (s2.find(s1) != string::npos)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
