#include <iostream>
#include <map>
#include <sstream>
using namespace std;

bool isIsomorphic(string s, string t) {
    map<char, char> st;
    map<char, char> ts;

    if (s.length() != t.length())
        return false;

    for (int i = 0; i < s.length(); i++) {
        if (st.find(s[i]) != st.end() && st[s[i]] != t[i])
            return false;

        if (ts.find(t[i]) != ts.end() && ts[t[i]] != s[i])
            return false;

        st[s[i]] = t[i];
        ts[t[i]] = s[i];
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int TC;
    cin >> TC;
    cin.ignore();
    while (TC--) {
        string s;
        getline(cin, s);

        stringstream ss(s);
        string token;
        vector<string> words;
        while (ss >> token)
            words.push_back(token);

        s = words[0];
        string t = words[1];

        cout << (isIsomorphic(s, t) ? "YES" : "NO") << endl;
    }

    return 0;
}
