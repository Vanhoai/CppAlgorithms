#include <iostream>
using namespace std;

// 1. ABC/-AK/L-* -> *-A/BC-/AKL
// 2. AB+CD-E/FG+*- -> -+AB*/-CDE+FG

void solve(string s) {
    stack<string> st;
    for (int i = 0; i < s.size(); i++) {
        if (isalpha(s[i])) {
            st.push(string(1, s[i]));
        } else {
            string operand1 = st.top();
            st.pop();
            string operand2 = st.top();
            st.pop();

            string res = s[i] + operand2 + operand1;
            st.push(res);
        }
    }

    cout << st.top() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int TC;
    cin >> TC;
    while (TC--) {
        string s;
        cin >> s;
        solve(s);
    }

    return 0;
}
