#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

bool solve(string s) {
    stack<char> st;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(')
            st.push(s[i]);
        else {
            if (st.empty())
                return false;
            else
                st.pop();
        }
    }

    return st.empty();
}

int main() {
    SETUP;

    int TC;
    cin >> TC;
    while (TC--) {
        string s;
        cin >> s;
        if (solve(s))
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}