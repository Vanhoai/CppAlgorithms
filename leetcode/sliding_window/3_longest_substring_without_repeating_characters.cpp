#include <iostream>
#include <map>
#include <string>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int L = 0;
    map<char, int> mp;
    int mx = 0;

    for (int R = 0; R < s.size(); R++) {
        mp[s[R]]++;

        while (mp[s[R]] > 1) {
            mp[s[L]]--;
            L++;
        }

        mx = max(mx, R - L + 1);
    }

    return mx;
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
        cout << lengthOfLongestSubstring(s) << endl;
    }

    return 0;
}
