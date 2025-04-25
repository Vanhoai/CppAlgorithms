#include <iostream>
#include <map>
using namespace std;

/**
input: ABCDEABC
output: DE
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

        map<char, int> mp;
        for (int i = 0; i < s.size(); i++)
            mp[s[i]]++;

        for (auto it : mp) {
            if (it.second == 1)
                cout << it.first;
        }

        cout << endl;
    }

    return 0;
}
