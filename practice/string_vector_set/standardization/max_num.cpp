#include <iostream>
using namespace std;

/**
input: 100klh564abc365bg
output: 564
*/

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

        int res = -1e9;

        for (int i = 0; i < s.size(); i++) {
            if (!isdigit(s[i]))
                continue;
            else {
                string num = "";
                int j = i;
                while (j < s.size() && isdigit(s[j])) {
                    num += s[j];
                    j++;
                }

                i = j - 1;
                res = max(res, stoi(num));
            }
        }

        cout << res << endl;
    }

    return 0;
}
