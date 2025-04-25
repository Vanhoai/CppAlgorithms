#include <iostream>
using namespace std;

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
        cin >> s;

        for (int i = 1; i < s.size(); i++) {
            if (s[i] == '0')
                s[i] = s[i - 1];
            else {
                if (s[i - 1] == '0')
                    s[i] = '1';
                else
                    s[i] = '0';
            }
        }

        cout << s << endl;
    }

    return 0;
}
