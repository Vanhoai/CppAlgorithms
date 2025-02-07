#include "bits/macros.cpp"
#include "bits/stdc++.h"
using namespace std;

/**
input
3
2
5
11

output:
90
90
99
*/

ll divisible[501];
vector<string> v;
string s;
int ok;

void gen() {
    int i = s.size();
    while (i >= 0 && s[i] == '9') {
        s[i] = '0';
        --i;
    }

    if (i == -1)
        ok = 0;
    else
        s[i] = '9';
}

void init() {
    s = "000000000000";
    ok = 1;
    while (ok) {
        v.push_back(s);
        gen();
    }

    for (int i = 1; i <= 500; i++) {
        for (string it : v) {
            ll tm = stoll(it);
            if (tm != 0 && tm % i == 0) {
                divisible[i] = tm;
                break;
            }
        }
    }
}

int main() {
    SETUP;

    init();

    int TC;
    cin >> TC;
    while (TC--) {
        int n;
        cin >> n;
        cout << divisible[n] << endl;
    }

    return 0;
}