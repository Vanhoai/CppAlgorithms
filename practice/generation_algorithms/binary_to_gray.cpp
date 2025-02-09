#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

int main() {
    SETUP;

    int TC;
    cin >> TC;
    cin.ignore();
    while (TC--) {
        string s;
        cin >> s;

        cout << s[0];
        for (int i = 1; i < s.size(); i++) {
            cout << ((s[i] - '0') ^ (s[i - 1] - '0'));
        }

        cout << endl;
    }

    return 0;
}