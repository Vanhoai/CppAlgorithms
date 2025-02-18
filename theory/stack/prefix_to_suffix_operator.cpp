#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

// 1. *-A/BC-/AKL -> ABC/-AK/L-*
// 2. -+AB*/-CDE+FG -> AB+CD-E/FG+*-

void solve(string s) {
    stack<string> st;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (isalpha(s[i])) {
            st.push(string(1, s[i]));
        } else {
            string operand1 = st.top();
            st.pop();
            string operand2 = st.top();
            st.pop();

            string res = operand1 + operand2 + s[i];
            st.push(res);
        }
    }

    cout << st.top() << endl;
}

int main() {
    SETUP;

    int TC;
    cin >> TC;
    while (TC--) {
        string s;
        cin >> s;
        solve(s);
    }

    return 0;
}