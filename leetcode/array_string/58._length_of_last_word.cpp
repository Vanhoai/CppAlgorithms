#include <iostream>
using namespace std;

int lengthOfLastWord(string s) {
    int i = s.size() - 1;
    while (i >= 0 && s[i] == ' ')
        i--;

    int len = 0;
    while (i >= 0 && s[i] != ' ') {
        len++;
        i--;
    }

    return len;
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
        cout << lengthOfLastWord(s) << endl;
    }

    return 0;
}
