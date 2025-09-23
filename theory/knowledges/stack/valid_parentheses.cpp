#include <iostream>
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
        if (solve(s))
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
