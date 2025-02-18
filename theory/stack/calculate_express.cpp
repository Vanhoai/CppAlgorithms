#include "bits/macros.h"
#include "bits/stdc++.h"
using namespace std;

// 1. 231*+9- -> -4
void solve(string s) {
    stack<int> st;
    for (int i = 0; i < s.size(); i++) {
        if (isdigit(s[i])) {
            st.push(s[i] - '0');
        } else {
            int operand1 = st.top();
            st.pop();
            int operand2 = st.top();
            st.pop();

            int res;
            if (s[i] == '+')
                res = operand1 + operand2;
            else if (s[i] == '-')
                res = operand2 - operand1;
            else if (s[i] == '*')
                res = operand1 * operand2;
            else
                res = operand2 / operand1;

            st.push(res);
        }
    }

    cout << st.top() << endl;
}

// 1. -+7*45+20 -> 25
void solve2(string s) {
    stack<int> st;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (isdigit(s[i])) {
            st.push(s[i] - '0');
        } else {
            int operand1 = st.top();
            st.pop();
            int operand2 = st.top();
            st.pop();

            int res;
            if (s[i] == '+')
                res = operand1 + operand2;
            else if (s[i] == '-')
                res = operand1 - operand2;
            else if (s[i] == '*')
                res = operand1 * operand2;
            else
                res = operand1 / operand2;

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