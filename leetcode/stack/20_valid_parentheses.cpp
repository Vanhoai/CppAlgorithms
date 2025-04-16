#include <iostream>
#include <stack>
#include <string>
using namespace std;

#define FOR(i, a, b)  for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= b; --i)

bool isValid(string s) {
    stack<char> st;
    for (int i = 0; i < s.size(); i++) {
        if (st.empty() || s[i] == '(' || s[i] == '[' || s[i] == '{')
            st.push(s[i]);
        else {
            if (st.empty())
                return false;
            else {
                if (s[i] == ')') {
                    if (st.top() != '(')
                        return false;
                    else
                        st.pop();
                } else if (s[i] == '}') {
                    if (st.top() != '{')
                        return false;
                    else
                        st.pop();
                } else {
                    if (st.top() != '[')
                        return false;
                    else
                        st.pop();
                }
            }
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
        cout << isValid(s) << endl;
    }

    return 0;
}
