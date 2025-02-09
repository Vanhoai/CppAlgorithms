#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

/**
input
D

output:
ABCD
ABDC
ACBD
ACDB
ADBC
ADCB
BCDA
BDCA
CBDA
CDBA
DBCA
DCBA

*/

bool vower(char c) { return c == 'A' || c == 'E'; }

bool check(string s) {
    for (int i = 1; i < s.size() - 1; i++) {
        if (vower(s[i]) && !vower(s[i - 1]) && !vower(s[i + 1]))
            return false;
    }

    return true;
}

int main() {
    SETUP;

    char C;
    cin >> C;
    string s;

    int n = C - 'A' + 1;

    for (int i = 0; i < n; i++) {
        s += i + 'A';
    }

    do {
        if (check(s)) {
            cout << s << endl;
        }
    } while (next_permutation(s.begin(), s.end()));

    return 0;
}