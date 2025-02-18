#include "bits/macros.h"
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

        for (int i = 1; i < s.size(); i++) {
            if (s[i] == '0')
                s[i] = s[i - 1];
            else {
                if (s[i - 1] == '0')
                    s[i] = '1';
                else
                    s[i] = '0';
            }
        }

        cout << s << endl;
    }

    return 0;
}