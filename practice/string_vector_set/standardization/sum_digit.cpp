#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

/**
input: 1abc2x30yz67
output: 100
*/

int main() {
    SETUP;

    int TC;
    cin >> TC;
    cin.ignore();
    while (TC--) {
        string s;
        getline(cin, s);

        int sum = 0;

        for (int i = 0; i < s.size(); i++) {
            if (!isdigit(s[i]))
                continue;
            else {
                string num = "";
                int j = i;
                while (j < s.size() && isdigit(s[j])) {
                    num += s[j];
                    j++;
                }

                sum += stoi(num);
                i = j - 1;
            }
        }

        cout << sum << endl;
    }

    return 0;
}